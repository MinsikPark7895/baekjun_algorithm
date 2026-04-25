#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string>&a, const pair<int, string>&b) {
    return a.first < b.first;
}

int main(void) {
    int N;
    int age;
    string name;

    vector<pair<int, string>>member;
    vector<pair<int, string>>answer;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> age >> name;

        member.push_back({age, name});
    }

    stable_sort(member.begin(), member.end(), compare);
    for (int i = 0; i < N; i++) {
        cout << member[i].first << ' ' << member[i].second << '\n';
    }
    
}