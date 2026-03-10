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

    stack<int> heights;
    stack<int> idx;

    heights.push(blocks[0]);
    idx.push(0);

    int result = 0;

    for (int i = 1; i < W; i++) {
        while (true) {
            if (heights.top() < blocks[i]) {
                result += (blocks[i] - heights.top()) * (i - idx.top());
                heights.pop();
                idx.pop();
            }
            else if (blocks.empty() || heights.top() >= blocks[i]) {
                heights.push(blocks[i]);
                idx.push(i);
                break;
            }
        }
    }

    cout << result;

    return 0;
}
