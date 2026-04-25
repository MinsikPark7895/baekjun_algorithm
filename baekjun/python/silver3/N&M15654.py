import sys
from collections import deque

N, M = list(map(int, sys.stdin.readline().rstrip().split()))

arr = list(map(int, sys.stdin.readline().rstrip().split()))
arr.sort()

result = deque([])
visited = [False] * N

def backtrack(level):
    if level == M:
        print(*result)
        return

    
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            result.append(arr[i])
            backtrack(level + 1)
            result.pop()
            visited[i] = False


backtrack(0)


