#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> clouds;

// 방향 관련 델타 탐색
// index 0은 무시
int dir_dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dir_dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

// 물복사 대각선 4방향 더하기
int cloud_dx[] = {-1, 1, 1, -1};
int cloud_dy[] = {-1, -1, 1, 1};

int main(void) {

    int N;  // 영역의 가로, 세로 길이
    int M;  // 명령어 수

    int result = 0; // 최종 결과값

    cin >> N >> M;

    board.assign(N, vector<int>(N));

    // 영역 입력값 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            result += board[i][j];
        }
    }

    // 초기 구름 위치
    clouds = {{N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1}};

    // 명령입력 받기 
    for (int cmd = 0; cmd < M; cmd++) {
        int dir;  // 방향
        int dist;  // 거리
        cin >> dir >> dist;

        int next_row;
        int next_col;
        int clouds_len = clouds.size();  // 구름의 길이

        // 구름의 개수를 다음 이동 방향까지 이동
        for (int idx = 0; idx < clouds_len; idx++) {
            next_row = dir_dy[dir - 1] * dist + clouds[idx].first;
            next_col = dir_dx[dir - 1] * dist + clouds[idx].second;

            if (next_row < 0 || next_row >= 8 || next_col < 0 || next_col >= 8) {
                next_row = (next_row + 64) % 8;
                next_col = (next_col + 64) % 8;
            }

            // 구름에서 비가 내림
            board[next_row][next_col] += 1;
            result += 1;
        }

        // 물복사 마법
        for (int idx = 0; idx < clouds_len; idx++) {
            auto cur = clouds[clouds_len - idx];
            clouds.pop_back();

            int cur_row = cur.first;
            int cur_col = cur.second;

            // 대각 4방향 확인
            for (int i = 0; i < 4; i++) {
                int check_row = cur_row + cloud_dy[i];
                int check_col = cur_col + cloud_dx[i];

                // 확인 위치가 보드 위에 있을 때
                if (0 <= check_row && check_row < 8 && 0 <= check_col && check_col < 8  ) {
                    // 해당 위치의 물이 존재한다면
                    if (board[check_row][check_col]) {
                        board[cur_row][cur_col] += 1;
                        result += 1;
                    }
                }
            }
        }

        // 다음 구름 저장
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] >= 2) {
                    board[i][j] -= 2;
                    result -= 2;
                    clouds.push_back({i , j});
                }
            }
        }

    }

    cout << result << "\n";
    

    return 0;
}