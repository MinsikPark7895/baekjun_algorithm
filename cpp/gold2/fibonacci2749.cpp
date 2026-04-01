#include <iostream>
#include <vector>

using namespace std;

// 순환 큐 => 피사노의 주기
vector<int> arr(1500000, -1);

// 피사노의 주기 사용
int fibonnaci(int idx) {
    if (idx == 0) {
        arr[0] = 0;
    }
    else if (idx == 1) {
        arr[1] = 1;
    }
    else if (idx >= 2) {
        if (arr[idx % 1500000] == -1) {
            arr[idx % 1500000] = (fibonnaci(idx - 1) + fibonnaci(idx - 2)) % 1000000;
        }
    }
    return arr[idx % 1500000];            
}

int main(void) {
    
    long long N;
    cin >> N;

    int target = N % 1500000;
    
    arr[0] = 0;
    arr[1] = 1;
    
    cout << fibonnaci(target);
       

    
    return 0;
}