#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int cur = 0;
    bool now;
    int len = 0;
    int *s = new int[n + 1];
    bool *sb = new bool[n + 1];
    char c = getchar();
    while (c != '0' && c != '1')
        c = getchar();
    now = c - '0';
    for (int i = 0; i < n; ++i) {
        c -= '0';
        if ((bool)c == now) {
            ++len;
        }
        else {
            s[cur] = len;
            sb[cur] = now;
            ++cur;
            len = 1;
            now = c;
        }
        c = getchar();
    }
    s[cur] = len;
    sb[cur] = now;
    ++cur;
    int maxlen = 0, tmp = 0, remain, j;
    for (int i = 0; i < cur; ++i) {
        if (sb[i]) {
            tmp = s[i];
            continue;
        }
        remain = k;
        for (j = i; j < cur && remain > 0; ++j) {
            tmp += s[j];
            if (!sb[j])
                --remain;
        }
        if (j < cur)
            tmp += s[j];
        if (maxlen < tmp)
            maxlen = tmp;
    }
    cout << (maxlen > tmp ? maxlen : tmp) << endl;
    return 0;
}
