import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

# NlogN
arr.sort()

min_sum = float('inf')
answer = []

for i in range(N - 2):
    # 투포인터
    left = i + 1
    right = N - 1
    
    # 1개 점은 현재 인덱스 다음 값, 다른 1개는 제일 큰 값
    while left < right:
        current_sum = arr[i] + arr[left] + arr[right]
        
        if abs(current_sum) < min_sum:
            min_sum = abs(current_sum)
            answer = [arr[i], arr[left], arr[right]]
        
        # 즉시 종료
        if current_sum == 0:
            break
            
        # 값을 키워야 함
        if current_sum < 0:
            left += 1
        # 값을 작게 해야 함
        else:
            right -= 1
            
    if min_sum == 0:
        break

print(*answer)