#include <iostream>

using namespace std;

int main(void){
    string word;
    cin >> word;

    int alphabet[26] = { 0, };

    for (int i = 0; i < word.length(); i++){
        alphabet[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        cout << alphabet[i] << ' ';
    }
}