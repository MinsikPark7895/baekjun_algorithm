#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 좌표를 저장하는 배열
    vector<pair<long long, long long>> coordinate(N);

    // 좌표를 하나씩 저장
    for(int i = 0; i < N; i++){
        cin >> coordinate[i].first >> coordinate[i].second;
    }

    // S = (xi * y(i+1) - x(i+1) * yi) * N / 2
    long long sum = 0;
    for(int i = 0; i < N; i++){
        int j = (i + 1) % N;
        sum += (coordinate[i].first * coordinate[j].second);
        sum -= (coordinate[j].first * coordinate[i].second);
    }

    // 절대 값 함수 fabs
    double area = fabs(sum) / 2.0;
    // 소수점 고정 형식으로 출력
    cout << fixed;
    // 소수 첫째자리까지 출력
    cout.precision(1);
    cout << area << endl;

    return 0;
}
