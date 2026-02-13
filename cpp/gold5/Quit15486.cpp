#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int N;
    int time, money;

    cin >> N;

    vector<pair<int, int>> arr;
    vector<int> dp(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> time >> money;
        arr.push_back({time, money});
    }

    int result = 0;  // 현재까지 최대 값

    for (int i = 0; i <= N; i++) {
        // i일까지의 최대 수익 갱신
        result = max(result, dp[i]);

        if (i == N) {
            break;
        }

        int day, cost;
        day = arr[i].first;
        cost = arr[i].second;

        if (i + day <= N){
            // 현재까지의 최대 수익에 더한 값과 비교
            dp[i + day] = max(result + cost, dp[i + day]);
        }

    }

    cout << result;

    return 0;
}