from collections import deque

n, m = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

visited = [[False] * m for _ in range(n)]

def bfs(y, x):
    queue = deque([(y, x)])

    visited[y][x] = True
    area = 1
    
    while queue:
        cur_y, cur_x = queue.popleft()
        
        for i in range(4):
            next_y = cur_y + dy[i]
            next_x = cur_x + dx[i]
            if 0 <= next_y < n and 0 <= next_x < m and not visited[next_y][next_x] and board[next_y][next_x] == 1:
                queue.append((next_y, next_x))
                visited[next_y][next_x] = True
                area += 1
    return area

cnt = 0
max_area = 0

for row in range(n):
    for col in range(m):
        if board[row][col] == 1 and not visited[row][col]:
            area = bfs(row, col)
            cnt += 1
            max_area = max(max_area, area)

print(cnt)
print(max_area)

