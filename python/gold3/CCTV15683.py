import sys

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

directions = {
    1: [[0], [1], [2], [3]],                         
    2: [[0, 2], [1, 3]],                             
    3: [[0, 1], [1, 2], [2, 3], [3, 0]],             
    4: [[0, 1, 2], [1, 2, 3], [2, 3, 0], [3, 0, 1]], 
    5: [[0, 1, 2, 3]]                                
}

queue = []
wall_count = 0

for i in range(N):
    for j in range(M):
        if 1 <= board[i][j] <= 5:
            queue.append((i, j, board[i][j]))
        elif board[i][j] == 6:
            wall_count += 1
            
max_seven_count = 0

# 브르트포스 + dfs
def dfs(depth, current_seven_count):
    global max_seven_count
     
    # 큐 인자 전부 확인 시
    if depth == len(queue):
        if current_seven_count > max_seven_count:
            max_seven_count = current_seven_count
        return
    
    # 다음 정보
    r, c, type_num = queue[depth]
    
    # 모든 조합 확인
    for mode in directions[type_num]:
        changed_positions = []
        
        for d in mode:
            nr, nc = r, c
            while True:
                nr += dx[d]
                nc += dy[d]
                
                # 배열 밖으로 나가거나 6을 만나면 탐색 중지
                if nr < 0 or nr >= N or nc < 0 or nc >= M or board[nr][nc] == 6:
                    break
                
                # 0인 공간을 만나면 7로 변경하고 기록
                if board[nr][nc] == 0:
                    board[nr][nc] = 7
                    changed_positions.append((nr, nc))
        
        # 다음 큐의 위치 확인
        dfs(depth + 1, current_seven_count + len(changed_positions))
        
        for cr, cc in changed_positions:
            board[cr][cc] = 0

dfs(0, 0)

result = (N * M) - (max_seven_count + len(queue) + wall_count)

print(result)