# pipex

## Description

`pipex` is a 42 project that recreates the behavior of Unix shell pipelines in C.

The goal is to understand how processes communicate using **pipes**, and how to manage execution flow using system calls such as `fork`, `execve`, and `dup2`.

This program mimics the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

---

## How it works

The program:

1. Opens an input file
2. Creates a pipe
3. Forks processes
4. Redirects input/output using `dup2`
5. Executes commands with `execve`
6. Writes the final output to a file

---

## Usage

```bash
./pipex file1 "cmd-1" "cmd-2" file2
./pipex_bonus file1 "cmd-1" "cmd-2" "cmd-3" ... "cmd-n" file2
```

### Equivalent shell command:

```bash
< file1 cmd1 | cmd2 > file2
< file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```

---

## 🛠️ Compilation

```bash
make
make bonus
```

---

## Example

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Equivalent:

```bash
< infile grep hello | wc -l > outfile
```