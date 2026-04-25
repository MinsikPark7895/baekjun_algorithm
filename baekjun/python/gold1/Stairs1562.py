N = int(input())
num_range = 10
bit_range = 1 << num_range

MOD = 10**9

dp = [[[0] * (bit_range) for _ in range(num_range)] for _ in range(N + 1)]

for k in range(num_range):
    dp[1][k][1<<k] = 1

for i in range(1, N):
    for j in range(num_range):
        for b in range(bit_range):
            if 0 <= j < 9:
                more = b | 1 << (j + 1)
                dp[i + 1][j + 1][more] += dp[i][j][b]
                dp[i + 1][j + 1][more] %= MOD
            if 0 <j <=9:
                less = b | 1 << (j - 1)
                dp[i + 1][j - 1][less] += dp[i][j][b]
                dp[i + 1][j - 1][less] %= MOD

total = 0
for k in range(1, num_range):
    total += dp[N][k][0b1111111111]
    total %= MOD

print(total)

