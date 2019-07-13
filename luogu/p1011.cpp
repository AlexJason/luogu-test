#include <iostream>
#include <algorithm>

using namespace std;

int calc_a(int n);
int calc_k(int n);
int sum_a(int n);
int sum_k(int n);

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    --n;
    cout << sum_a(x) * a + sum_k(x) * ((m - sum_a(n) * a) / sum_k(n)) << endl;
    return 0;
}

int calc_a(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 0;
    else if (n == 3) return 1;
    else if (n == 4) return 0;
    else return calc_a(n - 1) + calc_a(n - 2);
}

int sum_a(int n) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += calc_a(i);
    }
    return ret;
}

int calc_k(int n) {
    if (n <= 3) return 0;
    else if (n == 4) return 1;
    else return calc_k(n - 1) + calc_k(n - 2);
}

int sum_k(int n) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        ret += calc_k(i);
    }
    return ret;
}
