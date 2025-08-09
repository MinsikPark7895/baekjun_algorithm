from collections import deque

A, B = map(int, input().split())

queue = deque()
queue.append((A, 1))  # (현재 숫자, 연산 횟수)

found = False

while queue:
    current, count = queue.popleft()

    if current == B:
        print(count)
        found = True
        break
    if current * 2 <= B:
        queue.append((current * 2, count + 1))
    if current * 10 + 1 <= B:
        queue.append((current * 10 + 1, count + 1))

if not found:
    print(-1)
