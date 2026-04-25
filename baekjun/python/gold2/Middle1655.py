import sys
import heapq

input = sys.stdin.readline

N = int(input())

max_heap = []
min_heap = []

for _ in range(N):
    num = int(input())

    if not max_heap or num <= -max_heap[0]:
        heapq.heappush(max_heap, -num)
    else:
        heapq.heappush(min_heap, num)

    if len(max_heap) < len(min_heap):
        value = heapq.heappop(min_heap)
        heapq.heappush(max_heap, -value)
    
    if len(max_heap) > len(min_heap) + 1:
        value = -heapq.heappop(max_heap)
        heapq.heappush(min_heap, value)

    print(-max_heap[0]) 