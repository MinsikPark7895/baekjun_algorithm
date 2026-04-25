#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void){
    int num1, num2;
    cin >> num1;
    cin >> num2;

    int total_sum = 0;
    int min_num = -1;

    for (int i = num1; i <= num2; i++){
        if (isPrime(i)) {
            total_sum += i;
            if (min_num == -1){
                min_num = i;
            }
        }
    }
    
    if (min_num == -1){
        cout << -1 << endl;
    } else {
        cout << total_sum << endl;
        cout << min_num << endl;
    }
    return 0;
}