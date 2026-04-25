#include <iostream>
using namespace std;

int countNum(int n) {
    if (n == 0) return 1; 
    if (n < 0) return 0;  

    return countNum(n - 1) + countNum(n - 2) + countNum(n - 3);
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << countNum(n) << '\n';
    }

    return 0;
}
