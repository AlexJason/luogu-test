#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

int n;
int a[500002], b[500002], c[500002];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit(x);
    }
}

int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int read() {
    int x = 0, y = 0, z = getchar();
    while (!isdigit(z) && (y = z == '-', 1)) z = getchar();
    while (isdigit(z)) x = (x << 3) + (x << 1) + (z ^ 48), z = getchar();
    return y ? -x : x;
}

void write(long long x) {
    if (x >= 10) write(x / 10);
    putchar(x % 10 + 48);
}

bool cmp(const int &i, const int &j) {
    if (a[i] == a[j]) return j < i;
    return a[i] > a[j];
}

int main() {
    n = read();
    long long res = 0;
    for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = i;
    sort(b + 1, b + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        add(b[i], 1);
        res += sum(b[i] - 1);
    }
    write(res), putchar('\n');
    return 0;
}