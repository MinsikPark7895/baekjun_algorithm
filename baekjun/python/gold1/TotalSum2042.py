import sys

input = sys.stdin.readline

N, M, K = map(int, input().split())

def make_tree(start, end, idx):
    if start == end:
        tree[idx] = arr[start]
        return tree[idx]

    mid = (start + end) // 2
    tree[idx] = make_tree(start, mid, idx * 2) + make_tree(mid + 1, end, idx * 2 + 1)
    return tree[idx]


def update_tree(start, end, idx, target, value):
    if target < start or target > end:
        return
    
    tree[idx] += value

    if start == end:
        return
    
    mid = (start + end) // 2
    update_tree(start, mid, idx * 2, target, value)
    update_tree(mid + 1, end, idx * 2 + 1, target, value)


def sum_tree(start, end, idx, left, right):
    if right < start or left > end:
        return 0
    if left <= start and right >= end:
        return tree[idx]
    
    mid = (start + end) // 2
    return sum_tree(start, mid, idx * 2, left, right) + sum_tree(mid + 1, end, idx * 2 + 1, left, right)



arr = []
tree = [0] * (N * 4)
for _ in range(N):
    arr.append(int(input()))

make_tree(0, N - 1, 1)

for _ in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        update_tree(0, N - 1, 1, b - 1, c - arr[b - 1])
        arr[b - 1] = c
    else:
        print(sum_tree(0, N - 1, 1, b - 1, c - 1))


