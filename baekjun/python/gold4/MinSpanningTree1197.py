import sys

<<<<<<< HEAD
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
=======
# find 연산
def find_parent(parent, x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

# union 연산
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


V, E = map(int, input().split())

# 부모 테이블 초기화
parent = [0] * (V + 1)
for i in range(1, V + 1):
    parent[i] = i

# 간선 정보 담을 리스트와 최소 신장 트리 계산 변수 정의
edges = []
total_cost = 0

# 간선 정보 하나씩 확인하면서 크루스칼 알고리즘 수행
for _ in range(E):
    A, B, cost = map(int,input().split())
    edges.append((cost, A, B))

# 간선 정보 비용 기준으로 오름차순 정렬
edges.sort()

# 간선 정보 하나씩 확인하면서 크루스칼 알고리즘 수행
for i in range(E):
    cost, A, B = edges[i]

    # find 연산 후, 부모 노드 다르면 사이클 발생 X이므로 union 연산 수행 -> 최소 신장 트리에 포함
    if find_parent(parent, A) != find_parent(parent, B):
        union_parent(parent, A, B)
        total_cost += cost

print(total_cost)

>>>>>>> ccd694e635a06cc611d0c5762d36f767a23707fd
