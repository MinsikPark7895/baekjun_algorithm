#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    stack<string> st;
    stack<int> num;
    
    for (int i = 0; i < str.size(); i++) {
        // 여는 괄호일 때
        if (str[i] == '(') {
            st.push(string(1, str[i]));
        }
        else if (str[i] == '[') {
            st.push(string(1, str[i]));
        }
        // 닫는 소괄호일 때 ')'
        else if (str[i] == ')') {
            if (st.empty()) {
                num.push(0); 
                break;
            }
            if (i >= 1 && str[i - 1] == '(') {
                num.push(2);
                st.pop();
            }
            else if (i >= 1 && (str[i - 1] == ')' || str[i - 1] == ']')) {
                // num 스택에서 2개를 빼서 더하고 2를 곱한 후 다시 넣기
                if (num.size() >= 2) {
                    int a = num.top(); 
                    num.pop();
                    int b = num.top(); 
                    num.pop();
                    num.push(2 * (a + b));
                } else if (num.size() == 1) {
                    int a = num.top(); 
                    num.pop();
                    num.push(2 * a);
                }
                
                if (!st.empty()) {
                    st.pop();
                    
                }
            }
            else if (i >= 1 && str[i - 1] == '['){
                num.push(0); // 짝이 맞지 않는 실패 케이스
                break;
            }
        }
        // 닫는 대괄호일 때 ']' (새로 구현된 부분)
        else if (str[i] == ']') {
            if (st.empty()) {
                num.push(0);
                break;
            }
            if (i >= 1 && str[i - 1] == '[') {
                num.push(3);
                st.pop();
            }
            else if (i >= 1 && (str[i - 1] == ']' || str[i - 1] == ')')) {
                // num 스택에서 2개를 빼서 더하고 3을 곱한 후 다시 넣기
                if (num.size() >= 2) {
                    int a = num.top(); 
                    num.pop();
                    int b = num.top(); 
                    num.pop();
                    num.push(3 * (a + b));
                } else if (num.size() == 1) {
                    int a = num.top(); 
                    num.pop();
                    num.push(3 * a);
                }
                
                if (!st.empty()) {
                    st.pop();
                }
            }
            else if (i >= 1 && str[i - 1] == '('){
                num.push(0); // 짝이 맞지 않는 실패 케이스
                break;
            }
        }
    }
    
    if (num.empty()) {
        cout << 0 << "\n";
    } else {
        cout << num.top() << "\n";
    }
    
    return 0;
}