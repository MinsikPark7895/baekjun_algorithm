N = int(input())

result = 0

while N >= 5:
    result += N // 5
    N //= 5

print(result)