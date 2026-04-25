#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int N, M;
    cin >> N >> M;

    int ladder[101] = {0, };
    int snake[101] = {0, };

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }

    int arr[101];
    for(int i=0; i<=100; i++) arr[i] = -1;

    queue<int> q;
    q.push(1);
    arr[1] = 0;

    while (!q.empty()) {
        int cur_num = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++){
            int next_num = cur_num + i;

            // 100번 칸을 넘어가면 무시
            if (next_num > 100) continue;

            // 이동한 칸에 사다리나 뱀이 있는지 확인
            if (ladder[next_num] != 0) {
                next_num = ladder[next_num];
            }
            else if (snake[next_num] != 0) {
                next_num = snake[next_num];
            }

            // 아직 방문하지 않은 곳이라면 거리 갱신
            if (arr[next_num] == -1) {
                arr[next_num] = arr[cur_num] + 1;
                q.push(next_num);
            }
        }
    }

    cout << arr[100];

    return 0;
}