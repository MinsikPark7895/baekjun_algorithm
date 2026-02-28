#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    vector<int> dp(N + 1, 0);
    
    for (int i = 0; i < N + 1; i = i + 2) {
        if (i == 2) {
            dp[2] = 3;
        }
        else {
            for (int j = 2; j <= i; j = j + 2){
                if (i == j) {
                    dp[i] += 2;
                }
                else if(i - j == 2) {
                    dp[i] += dp[j] * 3;
                }
                else {
                    dp[i] += dp[j] * 2;
                }
            }
        }
    }
    cout << dp[N];

    return 0;
}