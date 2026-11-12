# pipex

Reproduces this shell pipeline in C:

```bash
< infile cmd1 | cmd2 > outfile      # shell
./pipex infile "cmd1" "cmd2" outfile # pipex
```

## How it works

1. Create a pipe.
2. Fork the first child: it opens `infile`, redirects it to standard input and the write end of the pipe to standard output with `dup2`, then runs `cmd1` with `execve`.
3. The parent waits for it, then redirects the read end of the pipe to standard input and `outfile` to standard output, and runs `cmd2`.
4. Each command is split into its arguments and looked up in the directories of the `PATH` environment variable, testing each candidate with `access`, as the shell does.

## Bonus: here_doc

```bash
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" outfile
```

Instead of reading `infile`, the program shows a `pipe heredoc>` prompt and reads lines from standard input until `LIMITER`, then feeds them to `cmd1` through an extra pipe, like a shell here-document.

## Usage

```bash
make            # ./pipex
make bonus      # ./pipex_bonus
./pipex /etc/passwd "grep bash" "wc -l" out.txt
```
