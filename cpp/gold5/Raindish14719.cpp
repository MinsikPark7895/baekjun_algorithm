#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);
    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }
    
    if (W == 0) {
        cout << 0;
        return 0;
    }

    stack<int> heights;
    stack<int> idx;

    heights.push(blocks[0]);
    idx.push(0);

    int result = 0;

    for (int i = 1; i < W; i++) {
        while (!heights.empty() && heights.top() < blocks[i]) {
            int bottom_height = heights.top();
            heights.pop();
            idx.pop();
            
            // 스택이 비어있으면 
            if (heights.empty()){
                break;
            }
            
            int width = i - idx.top() - 1;
            
            // 곱하는 건 좌우 높이 중 최소 값에서 아래 바닥을 뺀 값임 
            int trapped_height = min(blocks[i], heights.top()) - bottom_height;
        
            result += width * trapped_height;
        }
        
        heights.push(blocks[i]);
        idx.push(i);
    }

    cout << result;

    return 0;
}
