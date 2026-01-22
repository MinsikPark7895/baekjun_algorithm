#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int start_row, int start_col) {
    queue<pair<int, int>> q;

    q.push({start_row, start_col});

    while (!q.empty()) {
        auto now = q.front();
        int row_now = now.first;
        int col_now = now.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxt_row = row_now + dy[i];
            int nxt_col = col_now + dx[i];
            if (nxt_row >= 0 && nxt_col>=0) {
                // 조건 다시 설정
            }
        }
    }


    return 0;
}

int main(void) {

    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<pair<int, int>> start;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cur_row = i;
            int cur_col = j;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int next_row = cur_row + dy[k];
                int next_col = cur_col + dx[k];
                if (next_row >=0 && next_row < N && next_col >= 0 && next_col < M){
                    if (board[cur_row][cur_col] == 'L' && board[next_row][next_col] == 'L') {
                        cnt += 1;
                    }
                }

            }
            if (cnt == 1) {
               start.push_back({cur_row, cur_col}); 
            }
        }
    }

    int result = 0;

    for (int i = 0; i < start.size(); i++) {
        auto cur = start[i];

        int len = bfs();

    }

    return 0;
}