#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(void){
    int test_case;

    int cons;
    int start_x, start_y;

    vector<pair<int, int>> con;

    int end_x, end_y;

    string result = "sad";

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        cin >> cons;
        cin >> start_x >> start_y;

        for (int j = 0; j < cons; j++) {
            int con_x, con_y;
            cin >> con_x >> con_y;
            con.push_back(make_pair(con_x, con_y));
        }

        cin >> end_x >> end_y;

        vector<bool> visited(cons, false);

        queue<pair<int, int>> q;

        q.push({start_x, start_y});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            if(abs(x - end_x) + abs(y - end_y)) {
                result = "happy";
                break;
            }

            for (int i = 0; i < cons; i++) {
                auto next = con[i];
                int next_x = next.first;
                int next_y = next.second;
                if (!visited[i] && (abs(x - next_x) + abs(y - next_y) <= 1000)) {
                    q.push({next_x, next_y});
                    visited[i] = true;
                }
            }

        }

        cout << result << "\n";

    }

    return 0;
}