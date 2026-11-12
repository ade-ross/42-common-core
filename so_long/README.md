# so_long

A small top-down 2D game made with [MiniLibX](https://github.com/42Paris/minilibx-linux), the simple X11 graphics library used at 42. The player collects every item on the map and then reaches the exit.

## Maps

Maps are `.ber` text files:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

`1` wall · `0` floor · `P` player · `C` collectible · `E` exit

## Validation before the game starts

The map is refused, with an error message, if:

- it is not rectangular, or not closed by walls on every side;
- it has an invalid character, no collectible, or not exactly one player and one exit;
- **it is not playable**: some collectible or the exit can't be reached.

Playability is checked with a recursive **flood fill** on a copy of the map. Starting from the player, every reachable floor, collectible and exit tile is overwritten with a wall. If any `C`, `E` or `P` is left afterwards, there is no path to it. The `maps/` folder has a test map for each error case.

## Controls

`W` `A` `S` `D` or the arrow keys to move, `Esc` or the window's close button to quit. The move count is printed in the terminal. In the bonus version it is drawn in the game window instead.

## Build

MiniLibX is included in `minilibx-linux/` and built by the Makefile. It needs the X11 development headers:

```bash
sudo apt install libx11-dev libxext-dev zlib1g-dev
make && ./so_long maps/map.ber
make bonus && ./so_long_bonus maps/map.ber
```
