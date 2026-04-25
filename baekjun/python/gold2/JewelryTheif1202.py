import sys
import heapq

# N : 보석의 개수
# K : 가방의 개수
N, K = map(int, sys.stdin.readline().rstrip().split())

# (Mi, Vi)
# (보석의 무게, 보석의 가격)
jewels = [tuple(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]

bags = [int(sys.stdin.readline().rstrip()) for _ in range(K)]

jewels.sort()
bags.sort()

result = 0
queue = []
i = 0

for bag in bags:
    while i < N and jewels[i][0] <= bag:
        heapq.heappush(queue, -jewels[i][1])
        i += 1
    
    if queue:
        result += -heapq.heappop(queue)

print(result)


