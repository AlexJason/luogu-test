#include <iostream>

using namespace std;

#define INF 10000000

int main() {
    int n, t, s, d, usen = 0, uset = INF;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> s >> d;
        while (s < t)
            s += d;
        if (s < uset) {
            uset = s;
            usen = i;
        }
    }
    cout << usen + 1 << endl;
    return 0;
}
