#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    
    int test_cases;
    cin >> test_cases;
    
    vector<int> arr;
    vector<bool> used;
    vector<int> result;
    
    for (int tc = 0; tc < test_cases; tc++) {
        int N;
        cin >> N;
        
        arr.assign(2 * N, 0);
        used.assign(2 * N, false);
        result.assign(N, 0);
        
        for (int i = 0; i < 2 * N; i++) {
            cin >> arr[i];
        }
        
        int cur = 2 * N - 1;
        
        for (int i = 0; i < N; i++) {
            while(cur >= 0 && used[cur]) {
                cur--;
            }
            
            used[cur] = true;
            
            int target = arr[cur] / 4 * 3;
            
            for (int j = cur - 1; j >= 0; j--) {
                if (!used[j] && arr[j] == target) {
                    used[j] = true;
                    result[N - 1 - i] = arr[j];
                    break;
                }
            }
            
        }
        
        cout << "#" << tc + 1;
        
        for (int i = 0; i < N; i++) {
            cout << " " << result[i];
        }
        
        cout << "\n";
        
    }
    
    return 0;
}