#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;  // 입력값
vector<vector<int>> visited;  // 방문한 곳
vector<int> linked;  // 분류된 그룹

// bfs를 통해 linked에 현재 그룹 넘버를 표시
void bfs(int start_node, int group_id, int N, const vector<vector<int>>& board, vector<int>& linked){
    queue<int> q;
    q.push(start_node);
    linked[start_node] = group_id;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 0; next < N; next++) {
            if (board[cur][next] == 1 && linked[next] == 0) {
                linked[next] = group_id;
                q.push(next);
            }
        }
    }
}

int main(void) {

    int N; // 도시의 수
    int M; // 여행 계획에 속한 도시들의 수

    cin >> N;
    cin >> M;

    board.assign(N, vector<int>(N));  //  도시 연결 정보
    visited.assign(N, vector<int>(N));  // 방문한 곳 확인
    linked.assign(N, 0);

    vector<int> route;  // 여행 계획표

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int city;
        cin >> city;
        route.push_back(city - 1);  // 인덱스 조정을 위한 -1
    }

    int group_id = 1;
    for (int i = 0; i < N; i++) {
        if (linked[i] == 0) {
            bfs(i, group_id, N, board, linked);
            group_id++;
        }
    }

    string result = "YES";


    int first_group = linked[route[0]];
    for (int i = 0; i < M; i++) {
        if (linked[route[i]] != first_group) {
            result = "NO";
            break;
        }
    }
    

    cout << result << "\n";


    return 0;
}

