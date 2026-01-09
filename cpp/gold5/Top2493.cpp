// 맨 오른쪽에서 가장 높은 타워를 찾는 것

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    int N;
    
    cin >> N;

    vector<int> arr(N);  // 주어진 입력값을 저장할 배열
    vector<int> answer(N, 0);  // 정답 배열, 내부값을 0으로 초기화

    stack<int> st; // 풀이를 위한 스택

    // 입력값 받기
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 인덱스를 뒤에서부터 확인
    for (int i = 0; i < N; i++) {
        // 스택이 비어있지 않고 현재 스택 맨 위에 있는 값이 arr 보다 작으면
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        // 남아있다면 그게 i의 왼쪽에서 가장 가까운 더 큰 값
        if (st.empty()) {
            answer[i] = 0;
        }
        else {
            answer[i] = st.top() + 1;
        }

        // i를 다음 원소들의 후보로 등록
        st.push(i);
    }
    
    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}