#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;  // 나중에 바꿀 함수
vector<int> parent;   // 나중에 바꿀 부모 함수
vector<int> depth; 

void dfs(int cur, int par) {
    parent[cur] = par;
    for (int next : tree[cur]) {
        if (next == par) {
            continue;
        }
        depth[next] = depth[cur] + 1;
        dfs(next, cur);
    }
}

// 현재 노드에서 루트까지의 노드 집합
vector<int> single_path(int node) {
    vector<int> path;
    while (node != 0) {
        path.push_back(node);
        node = parent[node];
    }
    
    return path;
}

// 현재 노드가 다른 노드 배열에 있는지 
int find_root(int current, int N) { 
    vector<char> arr(N + 1, 0);
    while(current != 0)  {
        arr[current] = 1;
        current = parent[current];
    }

    return current;
}

// 1개의 path를 만들고 나머지 1개를 개별적으로 확인
int same_root(int a, int b, int N) {
    vector<char> mark(N + 1, 0);   // 해당 path를 지나쳤는지 확인
    // 지나친 path 표시
    while(a != 0) {
        mark[a] = 1;
        a = parent[a];
    }
    // 지나친 흔적 발견 시 값 반환
    while (b != 0) {
        if(mark[b]) {
            return b;         
        }
        b = parent[b];
    }

    return 0;
}

int main(void) {
    int N;

    cin >> N;

    tree.resize(N + 1);  // 들어온 함수의 숫자에 따라 그래프 변경
    parent.resize(N + 1, -1);  // 들어온 함수를 숫자에 따라 다시 그래프 변환
    depth.resize(N + 1, 0);  // 루트 깊이
    depth[1] = 0;

    // 무방향 그래프 생성
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // int root = find_root(1, N);
    dfs(1, 0);

    // 확인할 두 점의 개수
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        // 
        int result = same_root(node1, node2, N);
        cout << result << '\n';
    }

    return 0;
}