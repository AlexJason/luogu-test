#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int main() {
    int ra = 0, rb = 0;
    bool pa = true;
    char c = getchar();
    while (c == '0' || c == '1') {
        c -= '0';
        if ((bool)c == pa) {
            ++rb;
        }
        else {
            ++ra;
        }
        pa = !pa;
        c = getchar();
    }
    cout << min(ra, rb) << endl;
    return 0;
}
