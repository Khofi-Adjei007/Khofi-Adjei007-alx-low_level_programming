#!/usr/bin/python3
"""
5-island_perimeter module
"""

def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    c = 0  # Counter to keep track of the perimeter
    length = len(grid) - 1  # Length of the grid
    width = len(grid[0]) - 1  # Width of the grid

    # Loop through each row and column in the grid
    for i, r in enumerate(grid):
        for j, n in enumerate(r):
            if n == 1:  # Check if the cell represents part of the island
                # Check if the neighboring cell is water or outside the grid,
                # and if so, increment the perimeter counter
                if i == 0 or grid[i - 1][j] != 1:
                    c += 1
                if j == 0 or grid[i][j - 1] != 1:
                    c += 1
                if j == width or grid[i][j + 1] != 1:
                    c += 1
                if i == length or grid[i + 1][j] != 1:
                    c += 1
    return c  # Return the calculated perimeter
