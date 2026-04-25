import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))

pre = [0]
tmp_sum = []
mysum = 0

for i in range(N):
    mysum += nums[i]
    pre.append(mysum)

for i in range(N - M + 1):
    tmp_sum.append(pre[i+M] - pre[i])

print(max(tmp_sum))