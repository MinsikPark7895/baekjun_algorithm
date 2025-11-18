import sys

input = sys.stdin.readline

def quad_tree(x, y, size):
    first = board[x][y]
    for i in range(x, x + size):
        for j in range(y, y + size):
            if board[i][j] != first:
                size //= 2
                return (
                    "("
                    + quad_tree(x, y, size)
                    + quad_tree(x, y + size, size)
                    + quad_tree(x + size, y, size)
                    + quad_tree(x + size, y + size, size)
                    + ")"
                )
    return first

N = int(input())

board = list(input() for _ in range(N))

print(quad_tree(0, 0, N))




