import sys
import heapq

# N: 학생수
# M: 단방향 도로의 개수
# X: 파티 장소
N, M, X = map(int, sys.stdin.readline().rstrip().split())

# 집으로 가는 최단 경로
paths = {}
# 파티로 가는 최단 경로
paths_reverse = {}

for i in range(M):
    # 시작점, 끝점, 시간
    start, end, time = map(int, sys.stdin.readline().rstrip().split())
    # 정뱡향 시작점이 없을 경우
    if start not in paths.keys():
        paths[start] = {end: time}
    else:
        paths[start][end] = time

    # 역방향 시작점이 없을 경우
    if end not in paths_reverse.keys():
        paths_reverse[end] = {start: time}
    else:
        paths_reverse[end][start] = time

# 일반 다익스트라 알고리즘
def djikstra(graph, start):
    # distances는 시작 노드에서 각 노드까지의 최단 거리를 저장하는 딕셔너리
    distances = {node: float('inf') for node in graph}
    # 시작 노드에서 자기 자신으로 가는 거리는 0으로 설정
    distances[start] = 0
    # 우선순위 큐를 생성합니다. 시작 노드부터 처리하므로 (0, start)를 추가
    priority_queue = [(0, start)]

    while priority_queue:
        # 현재 가장 가까운 노드를 우선순위 큐에서 꺼냄
        current_distance, current_node = heapq.heappop(priority_queue)

        # 이미 처리된 노드라면 무시
        if current_distance > distances[current_node]:
            continue

        # 이 거리(distance)가 기존에 저장된 거리보다 짧다면, 업데이트합니다
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            # 이웃 노드를 우선순위 큐에 추가
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                # 이웃 노드를 우선순위 큐에 추가
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances


to_home = djikstra(paths, X)
to_party = djikstra(paths_reverse, X)

result = float("-inf")

for i in range(1, N + 1):
    result = max(result, to_home[i] + to_party[i])

print(result)




