# push_swap

Sort a list of integers using two stacks, `a` and `b`, and only these operations:

| Operation | Effect |
| --- | --- |
| `sa` `sb` `ss` | swap the top two elements of `a`, `b`, or both |
| `pa` `pb` | move the top element from one stack to the other |
| `ra` `rb` `rr` | rotate up: the top element goes to the bottom |
| `rra` `rrb` `rrr` | rotate down: the bottom element goes to the top |

The program prints the list of operations that sorts `a`. Fewer operations is better: the grading goes by how many it takes to sort 100 and 500 random numbers.

## How it works

**Up to 5 numbers:** push the extra elements to `b`, sort the three left in `a` with a fixed case analysis, then put the others back in their place.

**More than 5 numbers: a greedy cost-based insertion.**

1. Push two elements to `b`. From then on `b` is kept in descending order, seen as a circle.
2. For **every** element of `a`, compute the cost of moving it to the right place in `b`:
   - the rotations of `a` needed to bring it to the top (positive for `ra`, negative for `rra`, whichever is shorter);
   - the rotations of `b` needed to bring its correct neighbour to the top.
3. If both rotations go the same way they can be done together with `rr`/`rrr`, so the cost is `max(|a|, |b|)`; otherwise it is `|a| + |b|`.
4. Push the cheapest element, then repeat until `a` is empty.
5. Rotate `b` so that its largest element is on top and push everything back to `a`, which comes out sorted.

On random input this takes about 580 operations for 100 numbers and about 5,100 to 5,500 for 500.

## Checker (bonus)

`checker` reads operations from standard input, applies them, and prints `OK` if `a` ends up sorted and `b` empty, `KO` otherwise.

## Usage

```bash
make && make bonus
./push_swap 3 -1 42 7 0
ARG="$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"; ./push_swap $ARG | ./checker $ARG
```

Invalid input (non-numbers, duplicates, values outside `int`) prints `Error`.
