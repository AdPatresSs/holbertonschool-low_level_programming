# Memory Maps — Task 0 (`analysis/memory_maps.md`)

## 1. `stack_example.c`
- **Build & Run (without Valgrind):** `make` then `./stack_example`
- **Observed Behavior:** Prints `stack_example: recursion and stack frames`, traces `enter` and `exit` across `depth` 0..3 with stack addresses for `local_int`, `p_local`, `local_buf`, and `marker`, and exits `0`.
- **Stack & Heap:** Zero heap allocations. Each `walk_stack(depth, max_depth)` call creates a distinct stack frame with its own `marker` instance (`0, 10, 20, 30` at depth peak `3`). Each `dump_frame` call creates a temporary frame (`local_int`, `local_buf[16]`, `p_local`) that ends its lifetime on return.
- **Lifetimes & Aliasing:** `p_local` aliases `local_int` within `dump_frame`. Frame locals end their automatic lifetime when their function returns.
- **AI Critique & Correction:**
  - *AI Claim:* Recursive calls overwrite the previous `marker` in place, and `local_buf[16]` lives on the heap.
  - *Why Wrong:* Each recursive call pushes a separate stack frame with a distinct `marker` object; `local_buf` is an automatic stack array whose lifetime ends when `dump_frame` returns.
  - *Correction:* Model each `walk_stack` frame independently and keep `local_buf` on the stack tied to `dump_frame`'s lifetime.

---

## 2. `aliasing_example.c`
- **Build & Run (without Valgrind):** `make` then `./aliasing_example`
- **Observed Behavior:** Allocates 5 `int`s in `make_numbers(5)`, assigns `b = a` in `main`, prints values via `a` and `b`, frees `a`, then reads `b[2]` and writes `b[3] = 1234` before exiting `0`.
- **Stack & Heap:** `a` and `b` are distinct pointer variables in `main`'s stack frame; both store the address of the single heap block (`5 * sizeof(int)` bytes) returned by `make_numbers`.
- **Lifetimes, Ownership & Aliasing:** Ownership of the heap block transfers from `make_numbers`'s local `arr` to `main`'s `a`, then is aliased by `b`. `free(a)` ends the heap block's lifetime while leaving both `a` and `b` holding the old address as dangling pointers. Accessing `b[2]` and writing `b[3] = 1234` are use-after-free accesses (Undefined Behavior).
- **AI Critique & Correction:**
  - *AI Claim:* After `free(a)`, `b` remains a valid pointer to the array because `free` was only called on `a`.
  - *Why Wrong:* `a` and `b` alias the same heap allocation; freeing via `a` ends the allocation's lifetime for all aliases, making `b` dangling as well.
  - *Correction:* Treat both `a` and `b` as dangling after `free(a)` and classify subsequent reads/writes through `b` as use-after-free.