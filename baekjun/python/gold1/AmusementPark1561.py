import sys
input = sys.stdin.readline

N, M = map(int, input().split())
times = list(map(int, input().split()))

if N <= M:
    print(N)
    sys.exit(0)

lo, hi = 0, max(times) * N
while lo < hi:
    mid = (lo + hi) // 2
    served = M
    for time in times:
        served += mid // time
    if served >= N:
        hi = mid
    else:
        lo = mid + 1

t_star = lo

served_before = M
for time in times:
    served_before += (t_star - 1) // time

remain = N - served_before

for idx, time in enumerate(times, start=1):
    if t_star % time == 0:
        remain -= 1
        if remain == 0:
            print(idx)
            break
    
