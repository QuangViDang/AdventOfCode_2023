"""
https://adventofcode.com/2023/day/10

--- Part Two ---
You quickly reach the farthest point of the loop, but the animal never emerges. Maybe its nest is within the area enclosed by the loop?

To determine whether it's even worth taking the time to search for such a nest, you should calculate how many tiles are contained within the loop. For example:

...........
.S-------7.
.|F-----7|.
.||.....||.
.||.....||.
.|L-7.F-J|.
.|..|.|..|.
.L--J.L--J.
...........
The above loop encloses merely four tiles - the two pairs of . in the southwest and southeast (marked I below). The middle . tiles (marked O below) are not in the loop. Here is the same loop again with those regions marked:

...........
.S-------7.
.|F-----7|.
.||OOOOO||.
.||OOOOO||.
.|L-7OF-J|.
.|II|O|II|.
.L--JOL--J.
.....O.....
In fact, there doesn't even need to be a full tile path to the outside for tiles to count as outside the loop - squeezing between pipes is also allowed! Here, I is still within the loop and O is still outside the loop:

..........
.S------7.
.|F----7|.
.||OOOO||.
.||OOOO||.
.|L-7F-J|.
.|II||II|.
.L--JL--J.
..........
In both of the above examples, 4 tiles are enclosed by the loop.

Here's a larger example:

.F----7F7F7F7F-7....
.|F--7||||||||FJ....
.||.FJ||||||||L7....
FJL7L7LJLJ||LJ.L-7..
L--J.L7...LJS7F-7L7.
....F-J..F7FJ|L7L7L7
....L7.F7||L7|.L7L7|
.....|FJLJ|FJ|F7|.LJ
....FJL-7.||.||||...
....L---J.LJ.LJLJ...
The above sketch has many random bits of ground, some of which are in the loop (I) and some of which are outside it (O):

OF----7F7F7F7F-7OOOO
O|F--7||||||||FJOOOO
O||OFJ||||||||L7OOOO
FJL7L7LJLJ||LJIL-7OO
L--JOL7IIILJS7F-7L7O
OOOOF-JIIF7FJ|L7L7L7
OOOOL7IF7||L7|IL7L7|
OOOOO|FJLJ|FJ|F7|OLJ
OOOOFJL-7O||O||||OOO
OOOOL---JOLJOLJLJOOO
In this larger example, 8 tiles are enclosed by the loop.

Any tile that isn't part of the main loop can count as being enclosed by the loop. Here's another example with many bits of junk pipe lying around that aren't connected to the main loop at all:

FF7FSF7F7F7F7F7F---7
L|LJ||||||||||||F--J
FL-7LJLJ||||||LJL-77
F--JF--7||LJLJ7F7FJ-
L---JF-JLJ.||-FJLJJ7
|F|F-JF---7F7-L7L|7|
|FFJF7L7F-JF7|JL---7
7-L-JL7||F7|L7F-7F7|
L.L7LFJ|||||FJL7||LJ
L7JLJL-JLJLJL--JLJ.L
Here are just the tiles that are enclosed by the loop marked with I:

FF7FSF7F7F7F7F7F---7
L|LJ||||||||||||F--J
FL-7LJLJ||||||LJL-77
F--JF--7||LJLJIF7FJ-
L---JF-JLJIIIIFJLJJ7
|F|F-JF---7IIIL7L|7|
|FFJF7L7F-JF7IIL---7
7-L-JL7||F7|L7F-7F7|
L.L7LFJ|||||FJL7||LJ
L7JLJL-JLJLJL--JLJ.L
In this last example, 10 tiles are enclosed by the loop.

Figure out whether you have time to search for the nest by calculating the area within the loop. How many tiles are enclosed by the loop?
"""

from collections import deque

UP = set("S|LJ")
DOWN = set("S|F7")
LEFT = set("S-J7")
RIGHT = set("S-LF")

DIRECTIONS = [
    (-1, 0, (UP, DOWN)),
    (1, 0, (DOWN, UP)),
    (0, -1, (LEFT, RIGHT)),
    (0, 1, (RIGHT, LEFT)),
]

with open("input.txt") as f:
    data = f.read()
    lines = data.splitlines()
    S = divmod(data.find("S"), len(lines) + 1)

queue = deque([S])
loop = {S}

s_pipe = (UP | DOWN | LEFT) - {"S"}

while queue:
    row, column = queue.popleft()
    char = lines[row][column]

    for dr, dc, dirs in DIRECTIONS:
        new_row = row + dr
        new_column = column + dc
        from_dir, to_dir = dirs
        if (
            char in from_dir
            and lines[new_row][new_column] in to_dir
            and (new_row, new_column) not in loop
        ):
            queue.append((new_row, new_column))
            loop.add((new_row, new_column))
            if char == "S":
                s_pipe &= from_dir

lines[S[0]] = lines[S[0]].replace("S", tuple(s_pipe)[0])

outside = set()

for i, line in enumerate(lines):
    within = False
    up = None
    for j, char in enumerate(line):
        if (i, j) in loop:
            if char == "|":
                within = not within
            elif char in "LF":
                up = char == "L"
            elif char in "7J":
                if char != ("J" if up else "7"):
                    within = not within
                up = None

        if not within:
            outside.add((i, j))

print(len(lines) * len(lines[0]) - len(outside | loop))