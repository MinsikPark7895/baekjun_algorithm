import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

board = []
start = (0, 0)

for i in range(N):
    line = list(input().strip())
    for j, ch in enumerate(line):
        if ch == '0':
            start = (i, j)
    board.append(line)

def bfs(start_row, start_col):
    # visited[row][col][key_mask]
    visited = [[[False] * (1 << 6) for _ in range(M)] for _ in range(N)]
    q = deque()

    q.append((start_row, start_col, 0, 0))  # (r, c, key_mask, dist)
    visited[start_row][start_col][0] = True

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    while q:
        r, c, key_mask, dist = q.popleft()
        cell = board[r][c]

        if cell == '1':
            return dist

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if not (0 <= nr < N and 0 <= nc < M):
                continue

            nxt = board[nr][nc]
            nxt_mask = key_mask

            if nxt == '#':
                continue

            # 문(A~F)
            if 'A' <= nxt <= 'F':
                door_idx = ord(nxt) - ord('A')
                if not (key_mask & (1 << door_idx)):
                    continue

            # 열쇠(a~f)
            if 'a' <= nxt <= 'f':
                key_idx = ord(nxt) - ord('a')
                nxt_mask = key_mask | (1 << key_idx)

            if not visited[nr][nc][nxt_mask]:
                visited[nr][nc][nxt_mask] = True
                q.append((nr, nc, nxt_mask, dist + 1))

    return -1

sr, sc = start
print(bfs(sr, sc))
