import sys
input = sys.stdin.readline

def nCr(n, r):
    if r < 0 or r > n:
        return 0
    r = min(r, n - r)
    res = 1
    for i in range(1, r + 1):
        res = res * (n - i + 1) // i
    return res

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    print(nCr(M, N))
