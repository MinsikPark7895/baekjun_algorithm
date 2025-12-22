#include <iostream>

using namespace std;

int main(void) {
    int n;            // 입력값
    int result = 0;   // 출력값
    cin >> n;         // 입력 받기
    
    // 돈을 나눌 수 없는 경우
    if (n == 1 || n == 3) {
        result = -1;
        cout << result;
        return 0;
    }

    // 돈을 나눌 수 있는 경우
    int five_mul;
    int remaining_num;

    five_mul = n / 5;         // 5원 최대 개수
    remaining_num = n % 5;    // 그 외 거스름돈

    // 거스름돈이 없다면
    if (remaining_num == 0) {
        cout << five_mul;
    }
    else // 거스름돈이 존재한다면
    {
        // 이미 위에서 나눠지지 않는 경우 제외, 남은 돈 계산
        if (remaining_num == 1 || remaining_num == 3) {
            result = five_mul - 1 + (remaining_num + 5) / 2;
        }
        else  
        {
            result = five_mul + remaining_num / 2;
        }
        cout << result;
    }

    return 0;
}