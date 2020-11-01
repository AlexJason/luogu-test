#include <iostream>

using namespace std;

namespace ac {
    int queue[200];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
    	ac::queue[i] = i + 1;
    }
    int cur = 0, tal = n;
    int cnt = 1, sum = n;
    while (sum) {
        if (cnt != m) {
            ac::queue[tal] = ac::queue[cur];
            tal = (tal + 1) % n;
        }
        else {
            cnt = 0;
            --sum;
            cout << ac::queue[cur] << " ";
        }
        cur = (cur + 1) % n;
        ++cnt;
    }
    cout << endl;
    return 0;
}
