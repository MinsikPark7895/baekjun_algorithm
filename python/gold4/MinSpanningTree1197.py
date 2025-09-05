import sys

v, e = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(e)]
parent = list(range(v+1))
res = 0

edges.sort(key = lambda x: x[2])

def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x <= y:
        parent[y] = x
    else:
        parent[x] = y


for i in range(e):
    x, y, c = edges[i]
    if find(x) != find(y):
        union(x, y)
        res += c

print(res)
