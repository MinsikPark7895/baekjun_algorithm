#include <iostream>
#include <limits>

using namespace std;

int N;  // 수식의 길이
string formula;  // 전체 수식
int max_result = std::numeric_limits<int>::min();  // 결과 저장(음의 정수 무한대)

// 두 숫자를 연산하는 함수
int calculate(int a, int b, char oper) {
    if (oper == '+') {
        return a + b;
    }
    else if (oper == '-') {
        return a - b;
    }
    else if (oper == '*') {
        return a * b;
    }
    return 0;
}

// idx: 현재 인덱스 위치
// cur_sum: 지금까지 계산된 결과값
void backtrack(int idx, int cur_sum) {
    // 1. 종료 조건: 모든 숫자를 다 처리했을 때
    if (idx >= N) {
        max_result = max(max_result, cur_sum);
        return;
    }

    // 현재 위치의 연산자
    char oper;
    if (idx == 0) {
        oper = '+';
    }
    else {
        oper = formula[idx - 1];
    }

    // 이건 c++ 아스키 코드 해당 연산임
    // python 에서는 그냥 int(formula[idx])를 의미
    int next_val = formula[idx] - '0';
    backtrack(idx + 2, calculate(cur_sum, next_val, oper));

    if (idx + 2 < N) {
        int next_parentheses = calculate(formula[idx] - '0', formula[idx + 2] - '0', formula[idx + 1]);
        backtrack(idx + 4, calculate(cur_sum, next_parentheses, oper));
    }


}

int main(void) {

    cin >> N;

    cin >> formula;

    backtrack(0, 0);

    cout << max_result;

    return 0;
}