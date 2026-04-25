import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    clothes = {}

    for _ in range(n):
        name, type_ = input().split()
        clothes[type_] = clothes.get(type_, 0) + 1

    result = 1
    for count in clothes.values():
        result *= (count + 1)  

    print(result - 1)