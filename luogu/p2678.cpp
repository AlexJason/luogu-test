#include <iostream>
#include <algorithm>

using namespace std;

inline bool bs(int *dis, int n, int m, int val) {
    int c = 0, t = 0;
    for (int i = 0; i < n + 1; ++i) {
        if (dis[i] + t < val) {
            ++c;
            if (c > m) return false;
            t += dis[i];
            continue;
        }
        t = 0;
    }
    return true;
}

int main() {
    int l, n, m;
    cin >> l >> n >> m;
    int *dis = new int[n + 2];
    dis[n + 1] = 0;
    int last = 0, cur;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        dis[i] = cur - last;
        last = cur;
    }
    dis[n] = l - last;
    int left = 0, right = l;
    while (true) {
        int val = (left + right + 1) >> 1;
        if (bs(dis, n, m, val)) {
            if (left == right) {
                cout << val << endl;
                break;
            }
            left = val;
        }
        else {
            right = val - 1;
        }
    }
    return 0;
}
