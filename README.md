# 42 common core

My projects from the common core of [42](https://www.42network.org/), a peer-to-peer programming school with no teachers and no lectures. Every project starts from an empty folder and a subject that says what the program must do but not how. Most of them are in C, restricted to a handful of system calls, with no external libraries.

This repository holds the smaller and medium projects, one folder each. The larger ones have their own repositories.

| Project | Language | What it is |
| --- | --- | --- |
| [libft](libft) | C | My own C standard library: memory, strings, conversions, linked lists. Reused in most later projects. |
| [ft_printf](ft_printf) | C | `printf` rewritten with variadic arguments: `%c %s %p %d %i %u %x %X %%`. |
| [get_next_line](get_next_line) | C | Read a file one line at a time with a fixed-size buffer; the bonus keeps a separate buffer per file descriptor. |
| [push_swap](push_swap) | C | Sort integers using two stacks and a limited set of operations, in as few operations as possible. Includes a checker. |
| [pipex](pipex) | C | Reproduce the shell pipeline `< in cmd1 \| cmd2 > out` with `pipe`, `fork`, `dup2` and `execve`; the bonus adds a here-document mode. |
| [so_long](so_long) | C, MiniLibX | A small 2D game: collect every item and reach the exit. The map is validated with a flood fill before the game starts. |
| [philosophers](philosophers) | C, pthreads | The dining philosophers problem: one thread per philosopher, one mutex per fork, and a monitor thread that detects deaths. |
| [cpp-modules](cpp-modules) | C++98 | Ten modules, from classes and references to templates, STL containers and the Ford-Johnson merge-insertion sort. |
| [inception](inception) | Docker | A WordPress infrastructure built from my own Dockerfiles: NGINX with TLS, PHP-FPM, MariaDB, plus Redis, FTP, Adminer and Portainer. |

## Larger projects (own repositories)

| Project | What it is |
| --- | --- |
| [minishell](https://github.com/ade-ross/minishell) | A Bash-like shell in C: parsing, pipes, redirections, heredocs, environment variables, signals and builtins. Team of two. |
| [cub3D](https://github.com/ade-ross/cub3D) | A Wolfenstein-style raycasting engine in C with MiniLibX. Team of two. |
| [ft_irc](https://github.com/ade-ross/ft_irc) | An IRC server in C++98 built around a single `poll()` loop. Team of two. |
| [ft_transcendence](https://github.com/ade-ross/ft_transcendence) | A real-time 3D multiplayer browser game on four NestJS services. Team of five; I built the auth service. |

## Building

Everything was written and tested on Linux. Each folder has its own `Makefile`:

```bash
cd push_swap && make          # most projects
make bonus                    # where a bonus part exists
```

so_long needs the X11 development headers (`libx11-dev libxext-dev zlib1g-dev` on Debian/Ubuntu). Inception needs Docker; see its README.

## About the code style

42 projects must follow the school's coding standard, the *Norm*: functions of at most 25 lines, at most 5 functions per file, no `for` loops, declarations at the top of each function. This explains some of the splitting into small helper functions and files.
