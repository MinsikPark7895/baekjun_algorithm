#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    stack<char> st;
    int result = 0;
    int temp = 1;   // 곱셈을 누적할 변수
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            temp *= 2;      // 분배 법칙을 위해 2를 곱함
            st.push('(');
        }
        else if (str[i] == '[') {
            temp *= 3;      // 분배 법칙을 위해 3을 곱함
            st.push('[');
        }
        else if (str[i] == ')') {
            if (st.empty() || st.top() != '(') {
                result = 0; // 짝이 안 맞는 경우
                break;
            }
            if (str[i - 1] == '(') {
                result += temp; 
            }
            st.pop();
            temp /= 2;      // 곱했던 2를 다시 나눔
        }
        else if (str[i] == ']') {
            if (st.empty() || st.top() != '[') {
                result = 0; // 짝이 안 맞는 경우
                break;
            }
            if (str[i - 1] == '[') {
                result += temp;
            }
            st.pop();
            temp /= 3;      // 곱했던 3을 다시 나눔
        }
    }
    
    // 예외 처리
    if (!st.empty()) {
        cout << 0 << "\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}