#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> dp(N, 1);
    vector<int> prev_idx(N, -1);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int max_len = 0;
    int last_idx = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev_idx[i] = j;
            }
        }
        
        if (max_len < dp[i]) {
            max_len = dp[i];
            last_idx = i;
        }
    }
    
    stack<int> st;
    int curr = last_idx;
    
    while (curr != -1) {
        st.push(A[curr]);
        curr = prev_idx[curr];
    }
    
    cout << max_len << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}