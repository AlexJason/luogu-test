#include <cstdio>
using namespace std;

#define MAX_N 100005
int a[MAX_N], b[MAX_N];

int check(int mm, int n) {
    int c = 0, p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > mm) return 0;
        p += a[i];
        if (p > mm) {
            ++c;
            p = a[i];
        }
    }
    return c + 1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] + a[i];
    }
    int ml = 1, mr = b[n], mm = (ml + mr) / 2;
    while (ml != mr) {
        int t = check(mm, n);
        //printf("D: %d %d %d %d\n", ml, mm, mr, t);
        if (t == 0) {
            ml = mm + 1;
        }
        else {
            if (t > m) ml = mm + 1;
            else mr = mm;
        }
        mm = (ml + mr) / 2;
    }
    printf("%d\n", mm);
    return 0;
}
