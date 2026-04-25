#include <iostream>
#include <string>

using namespace std;

int main(void){
    int test_case;
    string word;

    cin >> test_case;

    for (int i = 0; i < test_case; i++){
        cin >> word;
        cout << "String #" << (i + 1) << "\n";
        for (int j = 0; j < word.length(); j++){
            char c = word[j];
            if (c == 'Z'){
                c = 'A';
            }
            else {
                c = c + 1;
            }
            cout << c; 
        }
        cout << "\n\n";
    }
}