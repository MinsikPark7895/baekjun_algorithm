import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

def dfs(x, y):
    visited[y][x] = True
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < W and 0 <= ny < H:
            if not visited[ny][nx] and board[ny][nx] == 1:
                dfs(nx, ny)

while True:
    W, H = map(int, input().split())
    if W == 0 and H == 0:
        break

    board = [list(map(int, input().split())) for _ in range(H)]
    visited = [[False] * W for _ in range(H)]

    result = 0

    for row in range(H):
        for col in range(W):
            if board[row][col] == 1 and not visited[row][col]:
                dfs(col, row)
                result += 1

    print(result)
