#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int test_case;
    cin >> test_case;
    
    for (int i = 0; i < test_case; i++){
        
        // 재료수, 제한 칼로리 
        vector<int> limits(2, 0);
        cin >> limits[0] >> limits[1];
        
        vector<pair<int, int>> ingredients;
        
        for (int j = 0; j < limits[0]; j++) {
            int T, K;
            cin >> T >> K;
            ingredients.push_back({T, K});
        }
        
        vector<int> dp;
        dp.assign(limits[1] + 1, 0);
        
        for (int j = 0; j < limits[0]; j++) {
            int taste = ingredients[j].first;
            int cal = ingredients[j].second;
            
            for (int k = limits[1]; k >= cal; k--) {
                if (dp[k] < dp[k - cal] + taste) {
                    dp[k] = dp[k - cal] + taste; 
                }
            }
        }
        
        cout << "#" << i + 1 << " " << dp[limits[1]] << "\n";
        
    }
    
    
    return 0;
}