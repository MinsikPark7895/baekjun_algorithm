#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >>> str;
    
    stack<string> st;
    stack<int> num;
    
    int result = 0;
    
    for (int i = 0; i < st.size(); i++) {
        if (stack.empty()) {
            st.push(str[i]);
        } 
        else if (stack.top() == "(" {
            if (str[i] == ")") {
                if (i >= 1 && str[i - 1] == "(" ) {
                    result += 2;
                    st.pop();
                }
                else if (i >= 1 && str[i - 1] != "(") {
                    result *= 2;
                    st.pop();
                }
            }
            // (에서 ]가 올 수 없음 
            else if (str[i] == "]") {
                result = 0;
                break;
            }
            
        }
        else if (stack.top() == "["){
            if (str[i] == "[") {
                if (i >= 1 && str[i - 1] == "[") {
                    result += 3;
                    st.pop();
                }
                else if (i >= 1 && str[i - 1] != "[") {
                    result *= 3;
                }
            }
            else if (str[i] == '')
        }
        
    }
    
    
    
    return 0;
}