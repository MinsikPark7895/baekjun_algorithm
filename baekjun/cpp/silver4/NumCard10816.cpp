#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int M; 
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x; 
        cin >> x;
        auto lo = lower_bound(a.begin(), a.end(), x);
        auto hi = upper_bound(a.begin(), a.end(), x);
        cout << (hi - lo);
        if (i + 1 < M) cout << ' ';
    }
    cout << '\n';
    return 0;
}
