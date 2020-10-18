#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 50005

int a[MAX_N], dp[MAX_N];
int pqueue[MAX_N], pqueuen[MAX_N];
int pql = 0, pqr = 0;

void init() {
    pql = pqr = 0;
}

void push(int t, int n) {
    while (pqueue[pqr - 1] > t && pqr > pql) --pqr;
    pqueue[pqr] = t;
    pqueuen[pqr] = n;
    ++pqr;
}

int front(int n) {
    while (pqueuen[pql] < n && pql < pqr) ++pql;
    if (pqr == pql || n <= 0) return 0;
    return pqueue[pql];
}

int check(int n, int t) {
    for (int i = 0; i <= n + 1; ++i) dp[i] = 0;
    init();
    for (int i = 1; i <= n + 1; ++i) {
        dp[i] = a[i] + front(i - t - 1);
        push(dp[i], i);
    }
    return dp[n + 1];
}

int main() {
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = n, m;
    while (l != r) {
        m = (l + r) / 2;
        int x = check(n, m);
        if (x > t) l = m + 1;
        else r = m;
    }
    printf("%d\n", l);
    return 0;
}

