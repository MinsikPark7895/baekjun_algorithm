import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    a = [0] + list(map(int, input().split()))  # 위 줄
    b = [0] + list(map(int, input().split()))  # 아래 줄

    # dp[i][0]: i열에서 선택 안 함
    # dp[i][1]: i열에서 위 선택
    # dp[i][2]: i열에서 아래 선택
    dp = [[0, 0, 0] for _ in range(n + 1)]

    for i in range(1, n + 1):
        dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i]
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + b[i]

    print(max(dp[n]))
