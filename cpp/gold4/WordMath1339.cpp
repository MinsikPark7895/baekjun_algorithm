#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<string> words(N);
    
    for (int i = 0; i < N; i++) {
        cin >> words[i];    
    }
    
    // 가중치 
    vector<int> alphabet(26, 0);
    
    
    // 각 단어를 순회하며 가중치 계산
    for (int i = 0; i < N; i++) {
        int power = 1;
        
        for (int j = words[i].length() - 1; j >= 0; j--) {
            int idx = words[i][j] - 'A';
            alphabet[idx] += power;
            power *= 10;
        }
    }
    
    // 버블 소트
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (alphabet[i] < alphabet[j]) {
                int temp = alphabet[i];
                alphabet[i] = alphabet[j];
                alphabet[j] = temp;
            }
        }
    }
    
    int max_sum = 0;  // 결과
    int num = 9;  // 큰수부터 차례대로 더하기
    
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            break;
        }
        
        max_sum += alphabet[i] * num;
        num--;
    }
    
    cout << max_sum;
    
    

    return 0;
}