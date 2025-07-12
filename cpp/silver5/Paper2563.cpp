#include <iostream>

using namespace std;

int main(void){
    //  x, y 좌표
    int x;
    int y;

    // 색종이의 수
    int papers;

    bool arr[101][101] = {false};
    int area = 0;

    cin >> papers;
    
    for (int i = 0; i < papers; i++){
        cin >> x >> y;
        for (int j = x; j < x + 10; j++){
            for (int k = y; k < y + 10; k++){
                if(!arr[j][k]){
                    arr[j][k] = true;
                    area++;
                }
            }
        }
    }

    cout << area << endl;


    return 0;
}