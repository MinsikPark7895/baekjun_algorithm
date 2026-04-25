import sys
sys.setrecursionlimit(10 ** 6)

M, N = map(int, sys.stdin.readline().rstrip().split())

board = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(M)]

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def dfs(graph, end_row, end_col):

    dp = [[-1] * N for _ in range(M)]
    
    def go(cur_row, cur_col):
        if cur_row == end_row and cur_col == end_col:
            return 1
        if dp[cur_row][cur_col] != -1:
            return dp[cur_row][cur_col]
        
        dp[cur_row][cur_col] = 0

        for i in range(4):
            next_row = cur_row + dy[i]
            next_col = cur_col + dx[i]

            if 0 <= next_row < M and 0 <= next_col < N and graph[cur_row][cur_col] > graph[next_row][next_col]:
                dp[cur_row][cur_col] += go(next_row, next_col)
        
        return dp[cur_row][cur_col]
                    
    return go(0, 0)

print(dfs(board, M - 1, N - 1))

