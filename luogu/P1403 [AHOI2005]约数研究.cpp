#include <iostream>

using namespace std;

typedef unsigned long long integer;

int main() {
    integer n, s = 0;
    cin >> n;
    for (integer i = 1, j = 0; i <= n; i = j + 1) {
        integer t = n / i;
        j = n / t;
        s += t * (j - i + 1);
    }
    cout << s << endl;
    return 0;
}