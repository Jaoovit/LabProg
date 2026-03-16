Compiler bash command

gcc -Wall -std=c99 -o ../build/[program_name] [file_name].c 

Run bash command

./build/[program_name]

Before compile C files rename the _build folder to build.

---------------------------------------------------------------------------

Summary of best practices

 - Always prefer local variables and passing parameters;

 - Use descriptive and unique variable names to avoid namespace conflicts;

 - Keep functions independent and reusable;

 - Test each function in isolation to make bug detection easier;

 - Avoid global variables whenever possible;

 - If you need to use global variables, clearly document the reason and how they are used.