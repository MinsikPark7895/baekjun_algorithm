#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;

    cin >> N >> M;

    vector<int> lecture;  // 주어진 배열
    vector<int> lecture_sum(N + 1, 0); // 누적합 배열

    int total_sum = 0; // 누적합 계산 
    int max_one = 0; // 강의 하나의 최대 길이

    lecture.push_back(0);

    // 입력값 받기
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        total_sum += j;
        if(j > max_one) {
            max_one = j;
        }
        lecture.push_back(j);
        lecture_sum[i + 1] = lecture_sum[i] + j;
    }


    int left = max_one;  // 초기값
    int right = total_sum;  // 초기값

    int result = right;

    while (left <= right) {
        int mid = (left + right) / 2;  // 현재 용량
        int cnt = 0;
        int idx = 0;

        while (idx < N) {
            cnt++;

            // 조건 : lecture_sum[end] - lecture_sum[idx] <= mid
            int limit = lecture_sum[idx] + mid;

            // limit 보다 처음으로 큰 값이 등장한 위치의 iterator을 반환
            int end = upper_bound(lecture_sum.begin(), lecture_sum.end(), limit) - lecture_sum.begin() - 1;

            idx = end;
            if(idx == N) {
                break;
            }
        }

        if (cnt <= M) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result;

    return 0;
}