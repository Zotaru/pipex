# Pipex

This project is an implementation of the Pipex program, done as part of the 42 school curriculum. The objective of this project is to recreate the functionality of the shell pipe (|) command in Unix-like operating systems.

### Language : ![C language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### Overview
The Pipex program takes an input file, runs two commands on it, and then redirects the output to another file. It simulates the behavior of the shell pipe command, which allows the output of one command to serve as the input to another command.

### Features
This project includes the following features:

A pipex program that takes input and output file names, along with two commands, and performs the equivalent of cmd1 < infile | cmd2 > outfile in the shell.
The program executes the commands in two child processes, establishing a pipe between them, and redirects the input and output accordingly.
Error handling for file opening, command execution, and pipe creation.

### Usage
#### Compilation
To compile the program, execute the following command:

```bash
make
```

#### Execution
To use the pipex program, execute the following command:

```shell
./pipex infile cmd1 cmd2 outfile
```

where:

* infile is the input file.
* cmd1 is the first command.
* cmd2 is the second command.
* outfile is the output file.
* The program will execute cmd1 < infile and cmd2 > outfile, and the output will be stored in outfile.

#### Example Usage
```shell
$> ./pipex infile "grep hello" "wc -l" outfile
```
This command will execute the equivalent of grep hello < infile | wc -l > outfile in the shell.

### Bonus Features
This project also includes the following bonus features:

* A here_doc option to simulate the << operator in shell scripting, allowing commands to read input from a specified delimiter instead of a file.
* Ability to pipe multiple commands consecutively, simulating the behavior of multiple | operators in shell commands. 
