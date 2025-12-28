#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(int me, int bro) {
    vector<int> visited(200001, -1);  // 방문 확인용
    vector<int> before(200001, -1);  // 경로 저장용

    queue<int> q;   // bfs를 위한 큐

    visited[me] = 0;  // 초기값 선언
    q.push(me);

    while(!q.empty()) {
        int cur = q.front();  // 맨 앞에 있는 숫자 추출
        q.pop();  // 맨 앞 제거

        // 현재 위치가 동생의 위치와 같을 경우
        if (cur == bro) {
            vector<int> path;

            // 현재 위치에서 시작 점까지의 경로 검색
            while(cur != -1) {
                path.push_back(cur);
                cur = before[cur];
            }

            // 경로 뒤집기
            reverse(path.begin(), path.end());

            // 경로 길이 출력
            cout << path.size() - 1 << "\n";

            // path에 존재하는 숫자 차례대로 출력
            for (auto node: path) {
                cout << node << " ";
            }

            return;         
        }

        // 동생과 위치가 다를 경우
        int nexts[] = {cur - 1, cur + 1, cur * 2};  // 다음 위치 연산

        // 다음 위치에 대해서 
        for (auto next: nexts) {
            // 다음 위치가 불가능한 위치에 있으면
            if (next < 0 || next > 200000) {
                continue;
            }
            // 다음 위치가 이미 방문한 지역이면
            if (visited[next] != -1) {
                continue;
            }

            visited[next] = visited[cur] + 1; // 다음 방문 위치에 원점으로부터 길이 저장
            before[next] = cur; // 경로 추척용으로 다음 위치 index에 현재 위치 저장
            q.push(next);  // bfs용 큐에 더함
        }
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    bfs(N, K);

    return 0;
}