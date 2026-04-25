import sys
from collections import deque

n = int(input().strip())
a, b = map(int, input().split())
m = int(input().strip())

g = [[] for _ in range(n + 1)]

for _ in range(m):
    x, y = map(int, input().split())

    g[x].append(y)
    g[y].append(x)


dist = [-1] * (n + 1)
q = deque([a])
dist[a] = 0

while q:
    u = q.popleft()
    if u == b:
        break
    for v in g[u]:
        if dist[v] == -1:
            dist[v] = dist[u] + 1
            q.append(v)

print(dist[b])

