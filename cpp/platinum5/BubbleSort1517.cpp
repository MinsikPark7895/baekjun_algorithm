#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;  // 정렬된 데이터를 저장할 벡터

long long inv = 0; // swap의 총량

void merge(vector<int>& arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;  // 분할한 지점 + 1의 인덱스
    int k = start;  // 시작 지점

    // 작은 순서대로 삽입
    while (i <= mid && j <= end) { // 중간점과 배열의 끝 전에 닿기까지 진행
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else {
            sorted[k] = arr[j];
            j++;
            inv += (mid - i + 1); // 왼쪽에 남아있는 모든 값들이 arr[j]보다 큼
        }
        k++;
    }

    int entry;  // 남아있는 구간의 시작 인덱스
    int target;  // 남아있는 구간의 끝 인덱스

    // 왼쪽이 끝난 경우
    if(i > mid) {
        entry = j;
        target = end;
    }
    // 오른쪽이 끝난 경우
    else {
        entry = i;
        target = mid;
    }

    // 남은 원소 복사
    for (int t = entry; t <= target; t++) {
        sorted[k] = arr[t];
        k++;
    }

    // 원본 배열에 반영
    for (int t = start; t <= end; t++) {
        arr[t] = sorted[t];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if(sorted.size() == 0) {
        sorted = vector<int>(arr.size());
    }
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(void) {

    int N;

    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, arr.size() - 1);

    cout << inv << '\n';

    return 0;
}