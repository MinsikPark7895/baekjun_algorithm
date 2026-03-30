#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(10, -1);

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
            arr[idx] = (fibonnaci(idx - 1) + fibonnaci(idx - 2)) % 1000000;
            
        }
        return arr[idx];
        
    }
    
}

int main(void) {
    
    long long N;
    cin >> N;
    
    arr[0] = 0;
    arr[1] = 1;
    
    cout << fibonnaci(N);
    
    // for (int i = 0; i < 10; i++) {
    //     cout << arr[i] << " ";
    // }
    

    
    return 0;
}