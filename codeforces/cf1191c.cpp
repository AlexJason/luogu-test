#include <iostream>

using namespace std;

int main() {
    unsigned long long n, m, k, p, c = 0;
    cin >> n >> m >> k;
    unsigned long long page_top = k, page_add = 0;
    for (int i = 0; i < m; ++i) {
        cin >> p;
        if (p <= page_top) {
            ++page_add;
        }
        else {
            if (page_add != 0) {
                page_top += page_add;
                ++c;
            }
            if (page_top < p) {
                page_top += ((p - page_top - 1) / k + 1) * k;
            }
            page_add = 1;
        }
    }
    if (page_add != 0) {
        ++c;
    }
    cout << c << endl;
    return 0;
}
