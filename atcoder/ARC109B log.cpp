#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
typedef unsigned long long ull_t;
 
int main() {
    ull_t n;
    cin >> n;
    //cout << n - (int)((sqrt(8 * (double)n + 9) - 3) / 2) << endl;
    ull_t t = n + 1, i = 1;
    while (t >= i) {
        t -= i;
        --n;
        ++i;
    }
    cout << n + 1 << endl;
    return 0;
}
