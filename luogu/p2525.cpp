#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *l = new int[n];
    for (int i = 0; i < n; ++i) cin >> l[i];
    if (prev_permutation(l, l + n)) for (int i = 0; i < n; ++i) cout << l[i] << " ";
    else cout << "ERROR";
    return 0;
}
