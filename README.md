*This project has been created as part of the 42 curriculum by bastalze.*

# pipex

## Description
Pipex replicates the behavior of shell pipelines. The program takes four arguments: input file name, 2 commants and an output file name. It executes command 1 on the given input file and pipes its output directly into ccommand 2, which writes the final result to an output file. It reacts exactly as if you had typed < file1 cmd1 | cmd2 > file2 in a terminal. To accomplish this I used fork, pipe, dup2 and execve and manually managed file descriptors and made sure both children wouldn't become zombies with waitpid().

## Instruction

### Compilation
- 'make' or 'make all' compiles the program
- 'make clean' removes object files
- 'make fclean' also removes the executable, library archive and depencency file (.d)
- 'make re' — recompiles the entire project from scratch

### Run program
To run the program you must have an existing infile and write the following line in the terminal. Where cmd1 is the first command and cmd2 is the second one and infile is the name of the infile and outfile is either the name of an existing outfile which will be overwritten or the name that you want the outfile to have.

	./pipex infile cmd1 cmd2 outfile
The equivalent shell expression:
'< infile grep must | wc -w > outfile'
Flags or additions that belong to a command need to be written in the same argument. For example:

	./pipex infile "grep must" "wc -w" outfile

## Resources

### References
- [Pipex the 42 project “Understanding Pipelines in C” - Medium](https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103)
- [dup() and dup2() Linux system call - geeksforgeeks](https://www.geeksforgeeks.org/c/dup-dup2-linux-system-call/)
- [Wait System Call in C - geeksforgeeks](https://www.geeksforgeeks.org/c/wait-system-call-c/)

### Peers
Thanks go out to the following people for their support. Kian gave me an entire crashcourse on the project - an hour of going through every step and possible pitfalls. Stefan A. answered my questions regarding the implementation order of functions and error handling. I collected infos from Irene, Michal and Felix on what is actually important to handle and what is overkill.

### AI Usage Statement
- understanding functions and concepts better
- decyphering error messages
