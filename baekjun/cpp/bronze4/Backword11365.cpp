#include <iostream>
#include <string>

using namespace std;

int main(void){
    string sentence;
    while (true){
        getline(cin, sentence);
        if (sentence == "END"){
            break;
        }
        for(int i = 0; i < sentence.length(); i++){
            cout << sentence[sentence.length() - 1 - i];
        }
        cout << '\n';
    }
}