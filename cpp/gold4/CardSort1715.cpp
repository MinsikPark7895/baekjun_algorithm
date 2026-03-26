#include <iostream>
#include <vector>

using namespace std;

void merge(int left, int right) {
    int mid = (left + right) / 2;
    
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            arr2[k++] = arr[i++];
        }
        else {
            
        }
    }
}

void merge_sort(int left, int right){
    
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, right);
    }
}

int main(void) {
    
    
    int N;
    vector<int> arr;
    
    cin >> N;
    arr.assign(N);
    
    for (int i = 0; i < N; i++) {
        
        cin >> arr[i];
    }
    
    
    
    return 0;
}