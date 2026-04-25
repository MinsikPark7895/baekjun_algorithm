import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
g = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

parent = [0] * (n + 1)
parent[1] = -1  # 루트 표시(아무 값이나 OK)

q = deque([1])
while q:
    cur = q.popleft()
    for nxt in g[cur]:
        if parent[nxt] == 0:        # 아직 방문 전
            parent[nxt] = cur
            q.append(nxt)

# 2번 노드부터 부모 출력
print('\n'.join(str(parent[i]) for i in range(2, n + 1)))
