#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> clouds;
bool is_cloud[51][51]; // 구름이 사라진 위치를 체크하기 위한 배열

// 
int dir_dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dir_dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

// 물복사 4방향
int cloud_dx[] = {-1, 1, 1, -1};
int cloud_dy[] = {-1, -1, 1, 1};

int main(void) {
    int N, M;
    cin >> N >> M;

    board.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 초기 구름 위치
    clouds = {{N - 1, 0}, {N - 1, 1}, {N - 2, 0}, {N - 2, 1}};

    for (int cmd = 0; cmd < M; cmd++) {
        int dir, dist;
        cin >> dir >> dist;

        // 구름 위치 표시 배열 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) is_cloud[i][j] = false;
        }

        // 구름 이동 및 비 내림
        for (int idx = 0; idx < clouds.size(); idx++) {
            // N을 더하고 나머지 연산을 하여 경계 밖으로 나갔을 때 연결 처리
            int next_row = (clouds[idx].first + dir_dy[dir] * (dist % N) + N) % N;
            int next_col = (clouds[idx].second + dir_dx[dir] * (dist % N) + N) % N;

            board[next_row][next_col] += 1;
            clouds[idx] = {next_row, next_col}; // 이동한 위치로 업데이트
            is_cloud[next_row][next_col] = true; // 구름이 있었던 자리 표시
        }

        // 물복사 마법
        for (int idx = 0; idx < clouds.size(); idx++) {
            int cur_row = clouds[idx].first;
            int cur_col = clouds[idx].second;
            int count = 0;

            for (int i = 0; i < 4; i++) {
                int check_row = cur_row + cloud_dy[i];
                int check_col = cur_col + cloud_dx[i];

                // 대각선은 경계를 벗어나면 안 됨
                if (check_row >= 0 && check_row < N && check_col >= 0 && check_col < N) {
                    if (board[check_row][check_col] > 0) count++;
                }
            }
            board[cur_row][cur_col] += count;
        }

        // 새로운 구름 생성 (기존 clouds 벡터를 비우고 새로 채움)
        vector<pair<int, int>> next_clouds;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] >= 2 && !is_cloud[i][j]) {
                    board[i][j] -= 2;
                    next_clouds.push_back({i, j});
                }
            }
        }
        clouds = next_clouds;
    }

    // 최종 결과 계산
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) result += board[i][j];
    }
    cout << result << "\n";

    return 0;
}