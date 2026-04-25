import sys

input = sys.stdin.readline

n = int(input())

ports = list(map(int, input().split()))

tails = []

def lower_bound(arr, target):
    left = 0
    right = len(arr)

    while left < right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid

    return left

for x in ports:
    if not tails or x > tails[-1]:
        tails.append(x)
    else:
        pos = lower_bound(tails, x)
        tails[pos] = x

print(len(tails))