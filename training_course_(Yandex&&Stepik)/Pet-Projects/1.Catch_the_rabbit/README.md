# 🐇 Catch the Rabbit

A console-based hide-and-seek game written in **C++** where a rabbit hides somewhere on a grid and you have to find it using directional hints.

---

## How to Play

1. Launch the program
2. Choose a grid size: **10×10**, **30×30**, or **50×50**
3. The rabbit is hidden at a random position — you can't see it
4. Enter a coordinate `x y` (x = horizontal, y = vertical, both start at **0**)
5. If you miss, the game tells you which direction to go: **Left / Right / Up / Down**
6. Keep guessing until you find the rabbit (`&`)
7. After winning, choose to play again or exit

---

## Coordinate System

The grid follows the **first quadrant** of a Cartesian plane:

```
Y
^
4  . . . . .
3  . . . . .
2  . . & . .    <- rabbit at (2, 2)
1  . . . . .
0  . . . . .
   0 1 2 3 4  -> X
```

- `(0, 0)` is the **bottom-left** corner
- X grows to the **right**
- Y grows **upward**
- You enter `x` first, then `y`

---

## Grid Symbols

| Symbol | Meaning              |
|--------|----------------------|
| `.`    | Empty unchecked cell |
| `*`    | Cell you already checked |
| `&`    | The rabbit — you won! |

---

## Hint System

| Hint      | Meaning                                  |
|-----------|------------------------------------------|
| `Правее!` | Go right — rabbit has a higher X        |
| `Левее!`  | Go left — rabbit has a lower X          |
| `Выше!`   | Go up — rabbit has a higher Y           |
| `Ниже!`   | Go down — rabbit has a lower Y          |

Two hints can appear at once if you're off on both axes.

---

## Build & Run

**Requirements:** Windows, g++ (MinGW or MSVC)

```bash
g++ -o rabbit main.cpp
./rabbit
```

> The program uses `windows.h` for UTF-8 console output (`SetConsoleCP(65001)`), so it is Windows-only.

---

## What Was Used

### Language & Standard
- **C++17**
- Standard headers: `<iostream>`, `<vector>`, `<cstdlib>`, `<ctime>`
- Platform header: `<windows.h>` (for Cyrillic console output)

### Core C++ Concepts Applied

**`std::vector<std::vector<int>>`** — a 2D dynamic array used as the game grid. Each cell holds an integer: `0` = empty, `1` = checked, `2` = rabbit found.

**Nested loops** — used both for building the matrix and for rendering it row by row.

**`std::rand()` / `std::srand(std::time(0))`** — random number generation seeded by current time, so the rabbit spawns in a different place every game.

**`while(true)` with `break` / `continue`** — the outer loop restarts the game, the inner loop handles each guess. `continue` re-prompts on bad input; `break` exits on win.

**Row-major matrix indexing** — `Matrix[row][col]` where `row` is the vertical axis and `col` is the horizontal. This is the standard layout for 2D vectors in C++.

---

## Key Lessons Learned

**Matrix rows are vertical, columns are horizontal.**
`Matrix[i][j]` — `i` is the row (Y axis), `j` is the column (X axis). This is easy to mix up, especially when you name variables `x` and `y` and then use them as `Matrix[x][y]` — at that point `x` is actually acting as a row, meaning it controls the vertical position. Counterintuitive, but standard.

**Rendering direction matters for coordinate feel.**
If you loop `i = 0 → P-1` when drawing, row 0 appears at the **top** of the screen — which means Y=0 is visually at the top, like a screen/image coordinate system. To get Y=0 at the bottom (math/Cartesian style), you loop `i = P-1 → 0`.

**Boundary checks must use `>=`, not `>`.**
A grid of size `P` has valid indices `0` to `P-1`. Writing `x >= P` correctly rejects the value `P`; writing `x > P` silently accepts it and causes an out-of-bounds memory access.

**Input order and internal storage are separate concerns.**
The player expects to type `x` (horizontal) first — that's natural. But internally the matrix stores data as `[row][col]` = `[y][x]`. The fix is simple: read into temporary variables and assign them to the right internal ones. Trying to rename everything to match is more error-prone.

---

## Project Stats

| Item | Value |
|------|-------|
| Language | C++ |
| Lines of code | ~150 |
| Days of C++ experience at time of writing | 27 |
| Hours spent | ~3 |
| Bugs fixed | 5 |

---

*Written from scratch in 27 days of learning C++. First game project.*
