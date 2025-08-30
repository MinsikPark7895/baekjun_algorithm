#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int move_cost(int from, int to) {
    if (from == to) return 1;
    if (from == 0) return 2;
    if (abs(from - to) == 2) return 4;
    return 3;
}

int main() {
    int n;

    vector<int> steps;

    while (cin >> n && n != 0){
        steps.push_back(n);
    }

    int M = (int)steps.size();

    const int INF = numeric_limits<int>::max() / 4;

    vector<vector<vector<int>>> dist(M + 1, vector<vector<int>>(5, vector<int>(5, INF)));
    // dist[i][l][r] = i번째 스텝까지 처리했을 때(왼발 = l, 오른발 = r)의 최소 비용
    dist[0][0][0] = 0;

    // 다익스트라: (총비용, i, l, r)
    using State = tuple<int, int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    pq.emplace(0, 0, 0, 0);

    while(!pq.empty()){
        auto[d, i, l, r] = pq.top();
        pq.pop();
        if(d != dist[i][l][r]) continue;
        if(i == M) {
            cout << d << '\n';
            return 0;
        }
        int s = steps[i];

        // 왼발로 s 밟기 
        {
            int nl = s;
            int nr = r;
            int ni = i + 1;
            int nd = d + move_cost(l, s);
            if(nd < dist[ni][nl][nr]) {
                dist[ni][nl][nr] = nd;
                pq.emplace(nd, ni, nl, nr);
            }
        }

        {
            int nl = l;
            int nr = s;
            int ni = i + 1;
            int nd = d + move_cost(r, s);
            if(nd < dist[ni][nl][nr]){
                dist[ni][nl][nr] = nd;
                pq.emplace(nd, ni, nl, nr);
            }
        }
    }

    return 0;
}
