#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<int> arr(n);        // 들어올 값을 담을 배열
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stack<int> stck;        // 스택 선언
    vector<char> result;    // 결과를 담을 배열
    int num = 1;            // 1부터 시작
    bool possible = true;   // 스택이 가능한지에 대한 여부 판별

    for(int i=0; i< n; i++){
        int current = arr[i];    // 현재 값을 저장

        while(num <= current){   // 현재 값보다 작을 경우
            stck.push(num++);       // 배열에 더해줌
            result.push_back('+');
        }

        if(stck.top() == current) {   // 만약 현재 값과 동일하면 맨 위에 있는 값을 뺌
            stck.pop();
            result.push_back('-');
        } else {
            possible = false;
            break;
        }
    }

    // 스택 형성이 불가능한 경우
    if(!possible) {
        cout << "NO\n";
    } else {
        for (char c : result) {
            cout << c << "\n";
        }
    }

    return 0;
}

