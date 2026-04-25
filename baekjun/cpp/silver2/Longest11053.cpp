#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    vector<int> dp(N, 1);

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int answer = 1;
    for(int i = 0; i < N; i++){
        for(int j=0; j < i; j++){
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer << endl;
    return 0;
}

