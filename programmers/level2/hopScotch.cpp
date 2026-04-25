#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp = land;

    for (int i = 1; i < land.size(); i++) {
        dp[i][0] += max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
        dp[i][1] += max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]});
        dp[i][2] += max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]});
        dp[i][3] += max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    }

    int answer = 0;

    for (int j = 0; j < 4; j++) {
        if (answer < dp[land.size() - 1][j]) {
            answer = dp[land.size() - 1][j];
        }
    }

    return answer;
}