import sys
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]

INF = 10**9
FULL = (1 << N) - 1

# 미계산 표식 -1 로 둔다
dp = [[-1] * (1 << N) for _ in range(N)]

def dfs(x, visited):
    if visited == FULL:
        return graph[x][0] if graph[x][0] else INF

    if dp[x][visited] != -1:
        return dp[x][visited]

    ret = INF
    for nxt in range(1, N):           # 0은 시작도시로 고정
        if not graph[x][nxt]:         # 길 없음
            continue
        if visited & (1 << nxt):      # 이미 방문
            continue
        cost = dfs(nxt, visited | (1 << nxt))
        if cost != INF:
            ret = min(ret, cost + graph[x][nxt])

    dp[x][visited] = ret              # 결과가 INF라도 '계산됨'으로 저장!
    return ret

print(dfs(0, 1))
