#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    int N, M;

    cin >> N >> M;

    vector<int> required(N);
    vector<int> additional(N);

    // 사용중인 메모리
    for (int i = 0; i < N; i++) {
        cin >> required[i];
    }

    // 추가적인 메모리
    for (int i = 0; i < N; i++) {
        cin >> additional[i];
    }

    // 모든 추가 메모리의 값을 더한 값
    int total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += additional[i];
    }

    // 추가 메모리의 합을 기준으로 만든 dp
    vector<int> dp(total_cost + 1, 0);

    for (int i = 0; i < N; i++) {
        int cost = additional[i];  // 상태축(비용)에 더해지는 값
        int mem = required[i];  // 최적화 대상

        // 뒤에서 앞으로 갱신
        for (int j = total_cost; j >= cost; j--) {
            dp[j] = max(dp[j], dp[j - cost] + mem);
        }
    }

    int answer = -1;
    for (int i = 0; i <= total_cost; i++) {
        if (dp[i] >= M) {
            answer = i;
            break;
        }
    }

    cout << answer;

    return 0;
}