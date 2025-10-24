import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

time = {}

dp = {}

for _ in range(N):
    start, end = map(int, input().split())
    if start not in time.keys():
        time[start] = end
    else:
        time[start] = min(end, time[start])

queue = deque([])
    
for i in range(N):
    if i in time.keys():
        if time[i] not in dp.keys():
            dp[i] = 1
        else:
            if time[i] in dp.keys():
                dp[time[i]] = max(dp[i] + 1, dp[time[i]])

print(max(dp.values()))


