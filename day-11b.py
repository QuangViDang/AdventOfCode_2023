"""
https://adventofcode.com/2023/day/11

--- Part Two ---
The galaxies are much older (and thus much farther apart) than the researcher initially estimated.

Now, instead of the expansion you did before, make each empty row or column one million times larger. That is, each empty row should be replaced with 1000000 empty rows, and each empty column should be replaced with 1000000 empty columns.

(In the example above, if each empty row or column were merely 10 times larger, the sum of the shortest paths between every pair of galaxies would be 1030. If each empty row or column were merely 100 times larger, the sum of the shortest paths between every pair of galaxies would be 8410. However, your universe will need to expand far beyond these values.)

Starting with the same initial image, expand the universe according to these new rules, then find the length of the shortest path between every pair of galaxies. What is the sum of these lengths?
"""

import itertools

with open("input.txt") as f:
    lines = f.read().splitlines()

empty_rows = [i for i, row in enumerate(lines) if set(row) == {"."}]
empty_cols = [i for i, col in enumerate(zip(*lines)) if set(col) == {"."}]

galaxies = [
    (i, j) for i, row in enumerate(lines) for j, char in enumerate(row) if char == "#"
]

res = 0
for (a1, b1), (a2, b2) in itertools.combinations(galaxies, 2):
    for r in range(*sorted((a1, a2))):
        res += 1 + (999_999 * (r in empty_rows))
    for c in range(*sorted((b1, b2))):
        res += 1 + (999_999 * (c in empty_cols))

print(res)
