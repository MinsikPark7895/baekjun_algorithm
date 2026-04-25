import sys

input = sys.stdin.readline

N, Q = map(int, input().split())

arr = [0] + list(map(int, input().split()))

bit = [0] * (N + 1)

def bit_add(i, delta):
    while i <= N:
        bit[i] += delta
        i += i & -i

def bit_sum(i):
    s = 0
    while i > 0:
        s += bit[i]
        i -= i & -i
    return s

for i in range(1, N + 1):
    bit_add(i, arr[i])

for _ in range(Q):
    x, y, a, b = map(int, input().split())
    if x > y:
        x, y = y, x
    
    print(bit_sum(y) - bit_sum(x - 1))

    diff = b - arr[a]
    arr[a] = b
    bit_add(a, diff)
