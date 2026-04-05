#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> cards;
    cards.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    
    sort(cards.begin(), cards.end());
    
    queue<int> q1;
    queue<int> q2;
    
    
    for (int i = 0; i < N; i++ ){
        q1.push(cards[i]);
    }
    
    int total_cost = 0;
    
    for (int i = 0; i < N - 1; i++) {
        int sum = 0;
        
        for (int j = 0; j < 2; j++) {
            int val;
            if (q1.empty()) {
                val = q2.front();
                q2.pop();
            }
            else if (q2.empty()) {
                val = q1.front();
                q1.pop();
            }
            else if (q1.front() < q2.front()) {
                val = q1.front();
                q1.pop();
            }
            else {
                val = q2.front();
                q2.pop();
            }
            sum += val;
        }
        total_cost += sum;
        
        q2.push(sum);
    }
    
    cout << total_cost << "\n";
    
    return 0;
}