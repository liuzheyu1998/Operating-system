# Operating system implementation with memory management using C
Special instructions:
1. The quit command will exit script only, not the shell,  when we run a script with quit command. So for exec command, when one file has a quit command, then the rest of this file will not be executed, but other files will still be executed.
2. The shell only accepts valid command, otherwise, it will print corresponding error message.
3. For duplicate scripts in exec, only error message will be given, none of the scripts will be loaded or executed.
For example, if you run:
exec script1.txt script2.txt script2.txt
The shell will print Error: Script script2.txt already loaded. And then the shell will print a "$" in next line.
3. For ./mysh < TESTFILE.txt, for keeping the same format as run TESTFILE.txt, the command is printed as well.($ and the command will both be printed for the input)
