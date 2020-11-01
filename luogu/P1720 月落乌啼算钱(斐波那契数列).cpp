#include <iostream>
#include <cstdio>

using namespace std;

long long f[50];

int main() {
    int n;
    cin >> n;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    printf("%.2lf", (double)f[n]);
    return 0;
}