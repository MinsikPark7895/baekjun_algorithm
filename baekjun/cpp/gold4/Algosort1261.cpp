#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited; 

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int M, N;

int bfs(int start_row, int start_col) {
    deque<pair<int, int>> dq;
    dq.push_back({start_row, start_col});
    
    visited[start_row][start_col] = 0; 
    
    while (!dq.empty()) {
        auto cur = dq.front();
        dq.pop_front();
        
        int cur_row = cur.first;
        int cur_col = cur.second;
        
        if (cur_row == N - 1 && cur_col == M - 1) {
            return visited[cur_row][cur_col];
        }
        
        for (int i = 0; i < 4; i++) {
            int next_row = cur_row + dy[i];
            int next_col = cur_col + dx[i];
            
            if (0 <= next_row && next_row < N && 0 <= next_col && next_col < M) {
                
                if (visited[next_row][next_col] == -1) {
                    
                    // 0이므로 앞에 넣음
                    if (board[next_row][next_col] == 0) {
                        visited[next_row][next_col] = visited[cur_row][cur_col];
                        dq.push_front({next_row, next_col});
                    }
                    // 1이므로 뒤에 넣음
                    else if (board[next_row][next_col] == 1) {
                        visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
                        dq.push_back({next_row, next_col});
                    }
                }
            }
        }
    }
    
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    
    board.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<int>(M, -1)); 
    
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            board[i][j] = line[j] - '0'; 
        }
    }
    
    cout << bfs(0, 0) << "\n";
    
    return 0;
}