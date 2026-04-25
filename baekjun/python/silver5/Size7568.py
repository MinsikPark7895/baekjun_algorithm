N = int(input())

students = [list(map(int, input().split())) for _ in range(N)]

for target in students:
    rank = 1
    for other in students:
        if target[0] < other[0] and target[1] < other[1]:
            rank += 1
    
    print(rank, end = " ")