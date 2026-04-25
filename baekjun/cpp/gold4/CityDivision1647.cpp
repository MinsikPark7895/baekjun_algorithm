#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> parent;

// 경로 압축 
int Find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = Find(parent[a]);
}

// 부모를 갱신하며 연결 
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, pair<int, int>>> edges;
    
    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({weight, {u, v}});
    }
    
    parent.resize(N);
    
    // 부모 초기화 
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
    
    // 간선을 가중치 기준으로 결정
    sort(edges.begin(), edges.end());
    int max_weight = numeric_limits<int>::min();  // 단일 최대 가중치
    int mst_weight = 0; // 총 최소 가중치 
    vector<pair<int, int>> mst_edges;
    
    for (const auto& edge: edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (Find(u) != Find(v)) {
            Union(u, v);
            mst_weight += weight;
            if (max_weight < weight) {
                max_weight = weight;
            }
            mst_edges.push_back({u, v});
        }
    }
    
    cout << mst_weight - max_weight << "\n";
    
    
    return 0;
}