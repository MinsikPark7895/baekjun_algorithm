#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> students;
vector<bool> visited;  // 방문 여부
vector<bool> finished;  // 탐색이 완전히 끝난 노드이닞 확인
int cnt;  // 팀이 이룬 학생 수

void dfs(int cur) {
    
    visited[cur] = true;  // 현재 노드 방문 처리
    int next = students[cur];  // 다음 학생 지목

    if (!visited[next]) {
        dfs(next);
    }
    else if (!finished[next]) {
        // 다음 학생을 방문은 했지만, 아직 탐색이 끝나지 않은 경우

        for(int i = next; i != cur; i = students[i]) {
            cnt++;
        }
        cnt++;
    }

    finished[cur] = true;

}

int main(void) {
    
    int T;
    cin >> T;
  
    for (int tc = 0; tc < T; tc++) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int N;
        cin >> N;

        students.assign(N + 1, 0);
        finished.assign(N + 1, false);
        visited.assign(N + 1, false);
        cnt = 0;

        for (int i = 1; i <= N; i++) {
            cin >> students[i];
        }

        for(int i = 1; i < N + 1; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }

        cout << N - cnt << "\n";

    }

    return 0;
}