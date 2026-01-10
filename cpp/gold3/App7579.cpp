#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int result = INT_MAX; // 출력값에 정수 최대 범위 수 지정

int N, M;  // N: 숫자의 개수, M: 필요한 메모리

vector<int> required_memory;  // 필요한 메모리 배열
vector<int> additional_memory;  // 활성화에 필요한 추가 메모리 배열

// 백트래킹을 통한 추적
void min_btye(int idx, int cur_sum, int cur_result) {
    // 필요한 메모리 이상의 값을 넘겨 받았을 경우
    if (cur_sum >= M) {
        result = min(result, cur_result);
        return;
    }

    // 들어온 인덱스를 기준으로 필요한 
    for (int i = idx; i < N; i++) {
        if (idx < N - 1) {
            min_btye(i + 1, cur_sum + required_memory[i], cur_result + additional_memory[i]);
        }
    }

    return;
}

int main(void) {

    cin >> N >> M;

    required_memory.resize(N);
    additional_memory.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> required_memory[i];
    }

    for (int i = 0; i < N; i++){
        cin >> additional_memory[i];
    }

    min_btye(0, 0, 0);
    
    cout << result;

    return 0;
}