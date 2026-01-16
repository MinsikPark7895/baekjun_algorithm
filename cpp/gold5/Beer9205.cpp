#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(void){
    int test_case; // 테스트 케이스

    int cons; // 편의점 수
    int start_x, start_y; // 시작 위치

    vector<pair<int, int>> con; // 편의점 배열

    int end_x, end_y; // 도착 위치

    string result = "sad"; // 결과값

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        cin >> cons;  // 편의점 수 받기
        cin >> start_x >> start_y;  // 시작점 받기

        // 편의점 좌표 저장
        for (int j = 0; j < cons; j++) {
            int con_x, con_y;
            cin >> con_x >> con_y;
            con.push_back(make_pair(con_x, con_y));
        }

        // 도착 지점 저장
        cin >> end_x >> end_y;

        // 방문 확인
        vector<bool> visited(cons, false);

        // bfs를 위한 큐
        queue<pair<int, int>> q;

        q.push({start_x, start_y});

        // 
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            if(abs(x - end_x) + abs(y - end_y) <= 1000) {
                cout << "<<" << result << ',' << x << ',' << y << ">>";
                result = "happy";
                break;
            }

            for (int i = 0; i < cons; i++) {
                auto next = con[i];
                int next_x = next.first;
                int next_y = next.second;
                if (!visited[i] && (abs(x - next_x) + abs(y - next_y) <= 1000)) {
                    cout << '('<< result << ','<< next_x << ',' << next_y << ')';
                    q.push({next_x, next_y});
                    visited[i] = true;
                }
            }
        }
        cout << result << "\n";
    }

    return 0;
}