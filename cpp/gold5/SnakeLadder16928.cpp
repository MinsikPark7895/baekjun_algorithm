#include <iostream>
#include <map>
#include <limits>
#include <math.h>

using namespace std;

int main(void) {
    int inf = numeric_limits<int>::max();
    int dp[100] = {inf, };

    int N, M;
    cin >> N >> M;

    map<int, int> dict_ladder;
    map<int, int> dict_snake;

    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        dict_ladder[a] = b;
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        dict_snake[a] = b;
    }

    for (int i = 0; i < N; i++){
        if (dict_snake.find(i) != dict_snake.end()){
            continue;
        }
        else if (i < 6) {
            dp[i] = 1;
        }
        else {
            for (int j = 0; j < 6; j++) {
                if (dict_snake.find(i) != dict_snake.end()){
                    continue;
                }                
                dp[i] = min(dp[i - j - 1] + 1, dp[i]);
            }
        }
        // C++20이상은 contains() 사용
        if (dict_ladder.find(i) != dict_ladder.end()) {
            if (dict_snake.find(i) != dict_snake.end()){
                continue;
            }
            dp[dict_ladder[i]] = dp[i];
        }

    }

    cout << dp[99];

    return 0;
}