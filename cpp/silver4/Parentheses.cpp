#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        stack<char> st;
        bool isValid = true;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if (!st.empty()) isValid = false;

        cout << (isValid ? "YES" : "NO") << '\n';
    }

    return 0;
}
