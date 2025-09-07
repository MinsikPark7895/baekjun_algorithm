#include <iostream>

using namespace std;

int calculate(int a, int b){
    int r = a % b;
    if(r == 0) {
        return b;
    }
    return calculate(b, r);
}

int main() {
    int n;
    int radius[101];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> radius[i];
    }

    for(int i = 1; i < n; i++){
        int result = calculate(radius[0], radius[i]);
        cout << radius[0] / result << "/" << radius[i] / result << "\n";
    }

    return 0;
}
