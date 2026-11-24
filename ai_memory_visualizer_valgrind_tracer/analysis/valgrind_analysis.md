# Valgrind Analysis — Task 1 (`analysis/valgrind_analysis.md`)

## 1. Commands & Scope
- **Build flags:** `-Wall -Wextra -Werror -pedantic -std=gnu89 -g` via `programs/Makefile`
- **Valgrind command:** `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes <binary>`
- **Programs analyzed:** `heap_example`, `aliasing_example` (plus baseline check on `stack_example`).

---

## 2. `aliasing_example` — Use-After-Free (`Invalid read` / `Invalid write`)
- **Valgrind Diagnostics:**
  - `Invalid read of size ...` at `b[2]` after `free(a)`.
  - `Invalid write of size ...` at `b[3] = 1234` after `free(a)`.
- **Memory Object & Lifetime Violation:** Targets the heap block of `5` `int`s allocated in `make_numbers` and aliased by `a` and `b` in `main`. Calling `free(a)` ends the heap block's lifetime, turning both `a` and `b` into dangling pointers. Reading `b[2]` and writing `b[3] = 1234` access memory after its lifetime ended (use-after-free / Undefined Behavior).
- **AI Critique & Correction:**
  - *AI Claim:* `Invalid read` / `Invalid write` occurs because `b` was never initialized or became `NULL` after `free(a)`.
  - *Why Wrong:* `b` was initialized to `a` (`b = a`) and still holds the old heap address after `free(a)`; the fault is accessing a freed heap allocation via a dangling alias, not dereferencing `NULL`.
  - *Correction:* Classify both accesses as use-after-free on a previously freed heap allocation referenced by dangling pointer `b`.

---

## 3. `heap_example` — Memory Leak Due to Lost Ownership (`definitely lost`)
- **Valgrind Diagnostic:** `definitely lost` for the `char` buffer (`len + 1` bytes) allocated for `alice->name` in `person_new`.
- **Memory Object & Lifetime Violation:** `person_new("Alice", 30)` allocates two separate heap blocks (`struct Person` and the `"Alice\0"` string buffer). `person_free_partial(alice)` calls `free(p)` without freeing `p->name`, losing the pointer to the string buffer and leaking that heap block. By contrast, `bob->name` and `bob` are freed in order with no leak.
- **AI Critique & Correction:**
  - *AI Claim:* Valgrind reports a leak on `alice` because `free(p)` never ran in `person_free_partial`.
  - *Why Wrong:* `free(p)` does run and frees the `struct Person` block; the leak is specifically the nested `p->name` string buffer whose pointer was stored inside the now-freed `Person` struct.
  - *Correction:* Identify the leaked object as the `p->name` heap buffer caused by freeing the parent `Person` struct without freeing `p->name` first.