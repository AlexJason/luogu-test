#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

long long read() {
    long long res = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) res = res * 10 + (ch ^ 48), ch = getchar();
    return res;
}

void write(long long t) {
    if (t >= 10) write(t / 10);
    putchar(t % 10 + 48);
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long p = exgcd(b, a % b, x, y);
    long long t = y;
    y = x - a / b * y, x = t;
    return p;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long a = read(), b = read(), c = read();
        long long x, y, g;
        if (c % (g = exgcd(a, b, x, y)) != 0) {
            putchar('-'), putchar('1'), putchar('\n');
        }
        else {
            //cout << a << " " << b << " " << c << " " << g << endl;
            //cout << x << " " << y << endl;
            x *= (c / g), y *= (c / g);
            long long x0 = (x % (b / g) + (b / g)) % (b / g), y0 = (c - a * x0) / b;
            long long y1 = (y % (a / g) + (a / g)) % (a / g), x1 = (c - b * y1) / a;
            if (x0 == 0) x0 += b / g, y0 -= a / g;
            if (y1 == 0) y1 += a / g, x1 -= b / g;
            //cout << x << " " << y << "/" << x0 << " " << y0 << "/" << x1 << " " << y1 << endl;
            if (x1 < x0) {
                write(x0), putchar(' '), write(y1), putchar('\n');
            }
            else {
                write((x1 - x0) / (b / g) + 1), putchar(' ');
                write(x0), putchar(' '), write(y1), putchar(' ');
                write(x1), putchar(' '), write(y0), putchar('\n');
            }
        }
    }
    return 0;
}
