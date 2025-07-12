#include <iostream>
#include <math.h>  

using namespace std;

int main(void){
    int up, down, length;
    cin >> up >> down >> length;

    int day = (length - down) / (up - down);

    if ((length - down) % (up - down) != 0) {
        day++;
    }

    cout << day;

    return 0;
}
