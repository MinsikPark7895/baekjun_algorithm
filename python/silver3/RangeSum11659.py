import sys
input = sys.stdin.readline

# N: 수의 개수, M: 구간의 개수
N, M = map(int, input().split())
nums = list(map(int, input().split()))

# 누적 합 배열 생성
prefix = [0] * (N + 1)
for i in range(1, N + 1):
    prefix[i] = prefix[i - 1] + nums[i - 1]

# 구간 합 출력
for _ in range(M):
    i, j = map(int, input().split())
    print(prefix[j] - prefix[i - 1])
