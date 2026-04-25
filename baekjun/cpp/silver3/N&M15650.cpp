#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;
bool visited[9];

void dfs(int level, int start) {
    if(level == M) {
        for (int i = 0; i < M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = start; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            selected.push_back(i);
            dfs(level + 1, i + 1);
            selected.pop_back();
            visited[i] = false;
        }
    }
}

int main(void){
    cin >> N >> M;
    dfs(0, 1);
    return 0;
}