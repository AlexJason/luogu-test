#include <iostream>

using namespace std;

int main() {
    int n, last, d, r = 0;
    cin >> n >> last;
    r = last;
    while (--n) {
        cin >> d;
        if (d > last) r += d - last;
        last = d;
    }
    cout << r << endl;
    return 0;
}


