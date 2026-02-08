#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int N, M;

    cin >> N >> M;

    vector<int> arr(N);
    vector<int> prefix(N, 0);   // 누적합
    vector<long long> remainders(M, 0);   // 각 누적합의 나머지

    long long prefix_sum = 0;  // 누적합을 구하는 변수

    // 누적합과 나머지를 구하는 식
    for (int i=0; i < N; i++) {
        int num;
        cin >> num;

        prefix_sum += num;
        prefix[i] = prefix_sum;

        int remain = prefix_sum % M;
        remainders[remain] += 1;
    }

    // 최종 결과 값
    long long result = 0;

    // 나머지가 0인 것은 그 자체로 1개의 경우
    result += remainders[0];
    
    // nC2를 통해 나머지가 동일한 2개를 선별
    for (int i = 0; i < M; i++){
        if (remainders[i] >= 2) {
            result += (remainders[i] - 1) * remainders[i] / 2;
        }
    }

    cout << result << '\n';
    

    return 0;
}