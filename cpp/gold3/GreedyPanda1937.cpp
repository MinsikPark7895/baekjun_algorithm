#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int n;  // 들어오는 입력값 받기
vector<vector<int>> field;  // 팬더의 이동 영역
vector<vector<int>> dp;  // 현재 위치에서 최대 이동 거리 확인 필드

// 4방향 델타 탐색을 위한 배열
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// 재귀함수 dfs
int dfs(int cur_row, int cur_col) {
    // 현재 위치에 이미 이동한 흔적이 있으면
    if (dp[cur_row][cur_col] > 0) {
        return dp[cur_row][cur_col];
    }

    // 초기 dp값 설정
    dp[cur_row][cur_col] = 1;

    // 4방향 확인
    for (int i = 0; i < 4; i++) {
        // 팬더 field 다음 행렬 좌표
        int next_row = cur_row + dy[i];
        int next_col = cur_col + dx[i];

        // 다음 확인하는 위치가 field 내부에 있을 경우
        if (0 <= next_row && next_row < n && 0 <= next_col && next_col < n){
            // 다음 확인하는 위치의 음식량이 현재 위치의 음식보다 많을 경우
            if (field[next_row][next_col] > field[cur_row][cur_col]){
                int depth = dfs(next_row, next_col) + 1; // 1칸 이동
                // 현재 이동한 dfs 거리가 현재 위치의 dp 값보다 큰 경우
                if(dp[cur_row][cur_col] < depth) {
                    dp[cur_row][cur_col] = depth;
                }
            } 
        }
    }

    return dp[cur_row][cur_col];
}

int main(void) {
    cin >> n;

    field.assign(n, vector<int>(n));  // 팬더의 음식 영역
    dp.assign(n, vector<int>(n, 0));  // 각 위치에서 갈 수 있는 최대 거리 확인 필드

    // 입력값 받기
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> field[i][j];
        }
    }

    int NINF = numeric_limits<int>::min(); // 음의 정수 임계값

    int result = NINF; // 출력 결과 최소값으로 설정

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(i, j));
        }
    }

    cout << result;
    
    return 0;
}