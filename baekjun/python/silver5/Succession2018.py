N = int(input().strip())

cnt = 0
s = 0
L = 1

for R in range(1, N + 1):
    s += R
    while s > N:
        s -= L
        L += 1
    if s == N:
        cnt += 1

print(cnt)
