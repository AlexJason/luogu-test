#include <iostream>
#include <cmath>

using namespace std;

int getl(int n) {
    int r = (sqrt(1 + 8 * n) - 1) / 2;
    if ((r + 1) * r / 2 == n) return r;
    return r + 1;
}

int main() {
    int n;
    cin >> n;
    int l = getl(n);
    int c = n - l * (l - 1) / 2;
    if (l & 1) cout << l - c + 1 << "/" << c << endl;
    else cout << c << "/" << l - c + 1 << endl;
    return 0;
}