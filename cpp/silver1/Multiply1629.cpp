#include <iostream>

using namespace std;

typedef long long ll;

ll power(ll A, ll B, ll C) {
    if(B == 0) {
        return 1;
    }
    if(B == 1) {
        return A % C;
    }

    ll half = power(A, B/2, C);
    ll result = (half * half) % C;

    if (B % 2 == 1) {
        result = (result * A) % C;
    }

    return result;
}

int main(void) {
    ll A, B, C;
    cin >> A >> B >> C;

    cout << power(A, B, C) << endl;

    return 0;
}


