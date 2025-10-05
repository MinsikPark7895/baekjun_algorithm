from collections import deque

required_jumps = int(input())
weight, height = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(height)]

dy4 = [0, 1, 0, -1]
dx4 = [1, 0, -1, 0]

dy8 = [1, 2, 2, 1, -1, -2, -2, -1]
dx8 = [2, 1, -1, -2, -2, -1, 1, 2]

visited = [[set() for _ in range(weight)] for _ in range(height)]

def bfs(H, W, K):

    if H == 1 and W == 1:
        return 0
    
    if board[0][0] == 1 or board[H-1][W-1] == 1:
        return -1

    queue = deque([(0, 0, 0, 0)])
    visited[0][0].add(0)

    while queue:
        cur_row, cur_col, jumps_used, dist = queue.popleft()

        for i in range(4):
            next_row, next_col = cur_row + dy4[i], cur_col + dx4[i]

            if 0 <= next_row < H and 0 <= next_col < W and board[next_row][next_col] == 0:
                if (next_row, next_col) == (H - 1, W - 1):
                    return dist + 1
                if jumps_used not in visited[next_row][next_col]:
                    visited[next_row][next_col].add(jumps_used)
                    queue.append((next_row, next_col, jumps_used, dist + 1))
        
        if jumps_used < K:
            next_jump = jumps_used + 1
            for i in range(8):
                next_row, next_col = cur_row + dy8[i], cur_col + dx8[i]
                if 0 <= next_row < H and 0 <= next_col < W and board[next_row][next_col] == 0:
                    if (next_row, next_col) == (H - 1, W - 1):
                        return dist + 1
                    if next_jump not in visited[next_row][next_col]:
                        visited[next_row][next_col].add(next_jump)
                        queue.append((next_row, next_col, next_jump, dist + 1))

        
    return -1

print(bfs(height, weight, required_jumps))

