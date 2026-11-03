<Measurement Methodology>

To have measurements for running time execution of a programm, we had to #include <time.h> to header files :
- We integrated `#include <time.h>` to access the `clock()` function and the `CLOCKS_PER_SEC` macro ;
Then we can use the clock-based timing function adding variables we want to have measurements :
- We declared pairs of `clock_t` variables (`start_total`, `end_total`, `start_build`, `end_build`, `start_process`, `end_process`, `start_reduce`, `end_reduce`) to isolate execution phases ;"
- Timers were strictly wrapped around each targeted routine (`build_dataset()`, `process_dataset()`, and `reduce_checksum()`), ensuring that unrelated overheads did not pollute phase measurements ;"
Elapsed times were converted into floating-point seconds using `(double)(end - start) / CLOCKS_PER_SEC` and printed precisely according to the project contract:
At the end, we just have to print all required lines and run the programm at least 3 times to see different results, (cf example in task 2) :

- TOTAL seconds: 0.001420`
- BUILD_DATA seconds: 0.000512`
- PROCESS seconds: 0.000635`
- REDUCE seconds: 0.000273`

<Observed Performance Differences>

You have different results for each implementation and only one way is the greenest one. As we can see in the second task,
Naive algorithm time: 0.482179 seconds / Single-pass algorithm time: 0.000015 seconds
Naive algorithm time: 0.481459 seconds / Single-pass algorithm time: 0.000015 seconds
Naive algorithm time: 0.478006 seconds / Single-pass algorithm time: 0.000015 seconds
The average time for Naive algorithm is 0.480548 seconds and for Single-pass algorithm its always 0.000015 seconds
So, implementation "Naive algorithm" is 32000 times slower than "Single-pass algorithm"
When testing our program in the 2nd task, we can clearly see that each step takes a different duration time:
"BUILD_DATA" is the time it takes to generate random numbers and set up the memory.
"PROCESS" is the longest step because it runs many operations.
Then, "REDUCE" is the fastest step, which simply runs a straight addition loop.
Most importantly, when we make the sum of all these steps, we have the "TOTAL" runtime (always in seconds).
This datas helping us to identify wich step is the most "energy consumer" and where we have to focus for writing a greener code.

<Relation Between Runtime and Energy Consumption>

The more runtime you have, the more energy you need to execute a program. Granted,
we are talking about very short durations for a single execution, but if you multiply this across a multitude of executions worldwide every second,
we can achieve significant energy savings by striving to write the greenest code possible

<Limitations of the Experiment>

One limitation of this methodology is OS background interference. While we tested the program, other tasks were also running in the background, such as downloads, updates, or internet activity.
These tasks can skew our measurements and make the process appear heavier than it actually is.

<Practical Engineering Takeaway>

Make a greener code is possible only if you want it ! By removing evertyhting your code dont need to be well executed, such as unused libraries, redundant functions, and unnecessary characters or operations.
By stripping away code bloat, we streamline execution, lower CPU utilization, and minimize the program's overall environmental footprint