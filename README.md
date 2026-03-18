Compiler bash command

gcc -Wall -std=c99 -o ../build/[program_name] [file_name].c 

Run bash command

../build/[program_name]

Before compile C files rename the _build folder to build.

---------------------------------------------------------------------------

Summary of best practices

 - Always prefer local variables and passing parameters;

 - Use descriptive and unique variable names to avoid namespace conflicts;

 - Keep functions independent and reusable;

 - Test each function in isolation to make bug detection easier;

 - Avoid global variables whenever possible;

 - If you need to use global variables, clearly document the reason and how they are used.

 ---------------------------------------------------------------------------

Best Practices to Avoid Memory Leaks in C

 - Every malloc() should have a corresponding free().

 - Clearly define who allocates memory and who frees it.

 - Free memory before exiting a function (even in error cases).

 - After free(), assign NULL to the pointer to avoid dangling pointers and double free errors.

 - Avoid dynamic allocation inside loops whenever possible.

 - Use a temporary variable when working with realloc().

 - For linked structures (lists, trees), implement release functions that traverse the entire structure.

 - Prefer local variables and parameter passing over dynamic allocation when possible.

 - Test your program with dynamic analysis tools (e.g., Valgrind, AddressSanitizer).