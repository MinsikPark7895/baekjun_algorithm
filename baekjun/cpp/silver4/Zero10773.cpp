#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int K;
    vector<int>money;
    int result = 0;

    cin >> K;

    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            int last = money.back();
            result -= last;
            money.pop_back();
        }
        else {
            money.push_back(num);
            result += num;
        }
        // cout << "Sum : " << result <<'\n';
    }

    cout << result;

    return 0;
}