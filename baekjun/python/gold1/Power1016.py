import sys
import math

input = sys.stdin.readline

Min, Max = map(int, input().split())

length = Max - Min + 1
is_squarefree = [1] * length

limit = math.isqrt(Max)
for i in range(2, limit + 1):
    sq = i ** 2
    start = ((Min + sq - 1) // sq) * sq
    for x in range(start, Max + 1, sq):
        is_squarefree[x - Min] = 0
    
print(sum(is_squarefree))