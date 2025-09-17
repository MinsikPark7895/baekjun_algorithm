import sys

covered = [[0]*101 for _ in range(101)]  

for _ in range(4):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    for x in range(x1, x2):
        for y in range(y1, y2):
            covered[x][y] = 1

area = 0
for x in range(101):
    for y in range(101):
        area += covered[x][y]

print(area)
