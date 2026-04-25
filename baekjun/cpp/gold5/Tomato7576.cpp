#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 토마토 위치 저장
struct tomato {
    int y, x;
};

// 4방향 델타 확인
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 들어올 가로, 세로 길이와 박스, bfs를 위한 큐 선언
int m, n;
int box[1001][1001];
queue<tomato> q;

// 델타 탐색이 박스 범위 내에 있을 경우
bool is_inside(int ny, int nx) {
    return (0 <= ny && ny < n && 0 <= nx && nx < m);
}

void bfs(void) {
    while(!q.empty()){
        int row = q.front().y;
        int col = q.front().x;
        q.pop();

        for(int i=0; i<4; i++){
            int cur_row = row + dy[i];
            int cur_col = col + dx[i];

            if(is_inside(cur_row, cur_col) == 1 && box[cur_row][cur_col] == 0){
                box[cur_row][cur_col] = box[row][col] + 1;
                q.push({ cur_row, cur_col });
            }
        }
    }
}

int main(void) {

    cin >> m >> n;

    // 박스 받기
    for(int i = 0; i < n; i++){
        for(int j=0; j < m; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    // 박스 확인
    int max = 0;
    for(int i = 0; i < n; i++){
        for (int j=0; j < m; j++){
            // 아직 익지 않은 토마토 발견 시 바로 -1 출력 후 종료
            if(box[i][j] == 0){
                cout << -1 << "\n";
                return 0;
            }

            // 그렇지 않으면 최대 값 저장
            if(max < box[i][j]) {
                max = box[i][j];
            }
        }
    }

    cout << max - 1 << '\n';

    return 0;
}