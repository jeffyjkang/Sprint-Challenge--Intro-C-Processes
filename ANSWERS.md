**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
created- process awaits admission to the "ready" state. Typically admission will be approved automatically
ready- or "waiting" has been loaded onto main memory, awaiting execution on CPU, There may be many ready processes, if one processor system. only one process can execute at each time
running- when process is chosen fo execution, instructions are executed by one of CPU's (core's), at most one per core, (can run in either mode, kernel or user mode)
blocked- when process cannot carry on without external change, or some event occuring (example, call to an i/o device, printer) / (when process requires user input)
terminated - either through running state by completing its execution or explicitly killed, no longer executing but process remains in process table as zombie process,
until parent process calls the wait system call to read its exit status, then it will be removed from process table. if no wait call from parent, resource leak.

**2. What is a zombie process?**
A process that has completed execution, via exit system call but still has entry in the process table. Process in the terminated state.

**3. How does a zombie process get created? How does one get destroyed?**
Occurs when child processes are terminated, where the entry is still needed for parent process to read its child exit status. Once exit status is read via the wait system call of parent, the zombie's entry is removed from the process table. If in the event the parent is terminated first. child will become adopted from Great grandfather process or process 1, which will then execute the wait, and the zombie will be removed from the process table and be "reaped".

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
The benefits of working in a compiled language, is speed. There is also the benefit of being able to allocate memory directly and being more precise and less wasteful of space and memory. One can also manipulate programs or processes in a more detailed way. It is possible to script for drivers and kernels, use system calls, etc. Negatives are the complexity and how it is strongly typed, so things generally take longer to build even the simplest of processes or programs.
