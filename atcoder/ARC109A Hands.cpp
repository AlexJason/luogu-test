#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
 
int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << (abs(a - b) - (int)(a > b)) * min(2 * x, y) + x << endl;
    return 0;
}
