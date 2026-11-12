# philosophers

The dining philosophers problem with POSIX threads. `N` philosophers sit around a table with one fork between each pair. To eat, a philosopher needs both forks next to them. Then they sleep, then think, then try to eat again. If one goes `time_to_die` milliseconds without starting a meal, they die and the simulation stops.

```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meals_each]
./philo 5 800 200 200 7
```

## Design

- **One thread per philosopher and one mutex per fork.** Each philosopher holds a pointer to its neighbour, so the forks form a ring.
- **No deadlock.** If everyone grabbed their own fork first, they could all wait forever on the second. Here philosopher 1 picks up the forks in the opposite order from everyone else, which breaks the circular wait.
- **Staggered start.** The philosophers in odd positions are started first and the even ones a moment later, so neighbours don't all compete for the same fork at the start.
- **A separate monitor thread** checks how long ago each philosopher last started eating, and also counts meals when the optional limit is given. When someone dies it sets a shared `is_dead` flag that every philosopher checks between actions.
- **Each piece of shared state has its own mutex:** the death flag and meal timestamps, the meal counters, the seat assignment, and `printf`, so that log lines are never interleaved.

Output format, one line per state change:

```
<ms since start> <philosopher> has taken a fork | is eating | is sleeping | is thinking | died
```
