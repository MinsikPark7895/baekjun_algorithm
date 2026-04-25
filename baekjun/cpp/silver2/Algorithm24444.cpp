#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    
    int N, M, R;
    
    cin >> N >> M >> R;
    
    vector<vector<int>> arr;
    vector<int> visited;
    
    arr.assign(N + 1, vector<int>(0));
    visited.assign(N + 1, 0);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
        
    }
    
    for (int i = 0; i < N + 1; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    
    queue<int> q;
    q.push(R);
    
    int cnt = 1;
    visited[R] = cnt;
    int cur;
    
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        
        for (int i = 0; i < arr[cur].size(); i++) {
            int next = arr[cur][i];
            if (visited[next] == 0) {
                visited[next] = ++cnt;
                q.push(next);
            }
        }
    }
    
    for (int i = 1; i < N + 1; i++) {
        cout << visited[i] << "\n";
    }
    
    
    return 0;
}