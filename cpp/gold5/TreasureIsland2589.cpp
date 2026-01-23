#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<string> board;
vector<vector<int>> visited;

struct coor {
    int y;
    int x;
};

coor bfs_find_start(int find_start_row, int find_start_col, int N, int M) {
    queue<pair<int, int>> q;

    visited.assign(N, vector<int>(M, -1));        
    q.push({find_start_row, find_start_col});
    visited[find_start_row][find_start_col] = 0;

    coor find_start_axis = {find_start_row, find_start_col};

    while (!q.empty()) {
        auto now = q.front();
        int row_now = now.first;
        int col_now = now.second;
        q.pop();

        find_start_axis = {row_now, col_now};

        for(int i = 0; i < 4; i++) {
            int nxt_row = row_now + dy[i];
            int nxt_col = col_now + dx[i];

            if (nxt_row >= 0 && nxt_row < N && nxt_col >= 0 && nxt_col < M) {
                if (board[nxt_row][nxt_col] == 'L' && visited[nxt_row][nxt_col] == -1) {   
                    visited[nxt_row][nxt_col] = visited[row_now][col_now] + 1;          
                    q.push({nxt_row, nxt_col});
                }
            }
        }
    }
    return find_start_axis;
}

int bfs_find_len(int find_start_row, int find_start_col, int N, int M) {
    queue<pair<int, int>> q;

    visited.assign(N, vector<int>(M, -1)); 
    board_cp.resize(N, vector<bool>(M, false));

    q.push({find_start_row, find_start_col});
    visited[find_start_row][find_start_col] = 0;

    int max_dist = 0;

    while (!q.empty()) {
        auto now = q.front();
        int row_now = now.first;
        int col_now = now.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxt_row = row_now + dy[i];
            int nxt_col = col_now + dx[i];

            if (nxt_row >= 0 && nxt_row < N && nxt_col >= 0 && nxt_col < M) {
                
                if (board[nxt_row][nxt_col] == 'L' && visited[nxt_row][nxt_col] == -1) {
                    visited[nxt_row][nxt_col] = visited[row_now][col_now] + 1;  
                    _d = max(_d, visited[nxt_row][nxt_col]);          
                    q.push({nxt_row, nxt_col});
                }
            }
        }
    }

    return _d;
}

int max_num(int A, int B) {
    return (A >= B) ? A : B;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    board.resize(N);
    vector<pair<int, int>> find_start;

    for (int i = 0; i < N; i++) cin >> board[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cur_row = i;
            int cur_col = j;
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int next_row = cur_row + dy[k];
                int next_col = cur_col + dx[k];
                if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
                    if (board[cur_row][cur_col] == 'L' && board[next_row][next_col] == 'L') cnt += 1;
                }
            }
            if (cnt == 1) find_start.push_back({cur_row, cur_col});
        }
    }

    int result = 0;

    for (int i = 0; i < (int)find_start.size(); i++) {
        auto cur = find_start[i];
        int cur_row = cur.first;
        int cur_col = cur.second;

        coor far = bfs_find_start(cur_row, cur_col, N, M);  
        int len = bfs_find_len(far.y, far.x, N, M);                     
        result = max_num(result, len);
    }

    cout << result;
    return 0;
}
