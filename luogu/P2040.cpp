// 涉及内容: 广度优先搜索(BFS), 位运算

#include <iostream>
#include <queue>

using namespace std;

const int c[] = {
    0x1a0, 0x1d0, 0x0c8,
    0x134, 0x0ba, 0x059,
    0x026, 0x017, 0x00b
};

int main() {
    int state = 0, t;
    for (int i = 0; i < 9; ++i) {
        cin >> t;
        state |= t << i;
    }
    
    // BFS
    queue<int> q;
    t = 0;
    q.push(state);
    q.push(0);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        t = q.front();
        q.pop();
        if (s == 0x1ff) break;
        for (int i = 0; i < 9; ++i) {
            q.push(s ^ c[i]);
            q.push(t + 1);
        }
    }

    cout << t << endl;
    return 0;
}
