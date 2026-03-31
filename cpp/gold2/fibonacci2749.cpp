#include <iostream>
#include <vector>

using namespace std;

// 순환 큐
vector<int> arr(10, -1);

// 피사노의 주기 사용
int fibonnaci(int idx) {
    if (idx == 0) {
        arr[0] = 0;
        return arr[0];
    }
    else if (idx == 1) {
        arr[1] = 1;
        return arr[1];
    }
    else if (idx >= 2) {
        if (arr[idx % 10] < arr[(idx - 1) % 10]) {
            arr[idx % 10] = (fibonnaci(idx - 1) + fibonnaci(idx - 2)) % 1000000;
            
        }
        return arr[idx];
        
    }

    // 모든 조건문을 빠져나올 경우
    return 0;
    
}

int main(void) {
    
    long long N;
    cin >> N;
    
    arr[0] = 0;
    arr[1] = 1;
    
    cout << fibonnaci(N);
       

    
    return 0;
}