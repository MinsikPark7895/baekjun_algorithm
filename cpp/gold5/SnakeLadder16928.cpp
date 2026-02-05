#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int dp[100] = {0, };

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < 6; i++) {
        dp[i] = 1;
    }

    map<int, int> dict;

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        dict[a] = b;
    }

    

    return 0;
}