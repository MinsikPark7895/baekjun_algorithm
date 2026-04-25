#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> used;
char last_letter;

// 진위 여부 확인
// 해시 테이블을 사용하기에는 구현이 복잡함
bool find(vector<string> used_words, string cur_word) {
    for (int i = 0; i < used_words.size(); i++) {
        if (used_words[i] == cur_word) {
            return true;
        }
    }
    return false;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    // 첫 단어는 무조건 넣음
    used.push_back(words[0]);
    // 첫 단어의 마지막 문자
    last_letter = words[0][words[0].size() - 1];

    // 초기값
    answer.push_back(0);
    answer.push_back(0);

    // 배열 순회
    for (int i = 1; i < words.size(); i++) {

        // 
        if (last_letter != words[i][0] || find(used, words[i])) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            // cout << i << " ,  " << words[i] << endl;
            // cout << answer[0] << "  ,   " << answer[1] << endl;
            break;
        }

        used.push_back(words[i]);
        last_letter = words[i][words[i].size() - 1];
    }

    return answer;
}