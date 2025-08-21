# 도시의 개수
N = int(input())

# 버스의 개수
M = int(input())

graph = [[] for _ in range(N + 1)]

distance = [float("inf")] * (N + 1)

for _ in range(M):
    # u: 출발 노드
    # v: 도착 노드
    # w: 연결된 간선의 가중치
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

import heapq

def dijkstra(start):
    q = []
    # 우선순위, 값 형태로 들어감
    heapq.heappush(q, (0, start))

    distance[start] = 0

    while q:
        # 우선순위가 가장 낮은 값이 나온다
        dist, now = heapq.heappop(q)

        # 이미 입력되어있는 값이 현재 노드까지의 거리보다 작다면 이미 방문한 노드
        if distance[now] < dist:
            continue
        
        # 연결된 모든 노드 탐색
        for i in graph[now]:
            # 기존에 입력되어 있는 값보다 크다면
            if dist+i[1] < distance[i[0]]:
                distance[i[0]] = dist + i[1]
                heapq.heappush(q, (dist+i[1], i[0]))

start, end = map(int, input().split())

dijkstra(start)

print(distance[end])
