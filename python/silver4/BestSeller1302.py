import sys
input = sys.stdin.readline

n = int(input())
cnt = {}

for _ in range(n):
    title = input().strip()
    cnt[title] = cnt.get(title, 0) + 1

answer = min(( (-c, t) for t, c in cnt.items()))[1]

print(answer)
