#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;       // 숫자 범위
    int K;       // 더하는 숫자의 개수
    
    cin >> N >> K;  // 입력 받기
    
    // 보드 선언 및 0으로 초기화
    vector<vector<int>> board(N + 1, vector<int>(K + 1, 0));

    // dp를 위한 기본 값 설정
    for (int i = 0; i < K + 1; i++ ) {
        for (int j = 0; j < N + 1; j++) {
            if(i == 1) {
                board[j][i] = 1;
            }
            else if (j == 0){
                board[j][i] = 1;
            }
            else {
                board[j][i] = 0;
            }
        }
    }

    // 값 선언
    for (int i = 2; i < K + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            board[j][i] = (board[j - 1][i] + board[j][i - 1]) % 1000000000;
        }
    }

    cout << board[N][K];

    return 0;
}