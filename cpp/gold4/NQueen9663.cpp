#include <iostream>

using namespace std;

// 퀸의 최대 개수
int col[16];
int N;
int result = 0;

// 백트래킹
void backtrack(int x) {
    // 만약 백트래킹으로 마지막 깊이까지 도달하면 반환
    if(x == N) {
        result++;
        return;
    }

    else {
        // N개의 퀸에 대해
        for(int i = 0; i < N; i++){
            // 각 행 확인
            col[x] = i;
            // 현재 선택한 행이 퀸을 놓을 수 있는 위치인지
            bool ok = true;
            // 현재까지 들어온 깊이
            for(int j = 0; j < x; j++){
                // 현재 확인하는 위치가 이미 퀸을 놓은 x축 일 경우 혹은 대각선에 있을 경우
                if(col[x] == col[j] || abs(col[x] - col[j]) == x - j){
                    ok = false;
                    break;
                }
            }
            // 다음 깊이로 이동
            if(ok) {
                backtrack(x + 1);
            }
        }
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> N;
    backtrack(0);
    cout << result << '\n';
    return 0;
}

