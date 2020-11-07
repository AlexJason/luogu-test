#include <iostream>

using namespace std;

char str[80];

int dfs(int cur, int &n, int l);
bool check(int cur);

int main() {
    int n, l;
    cin >> n >> l;
    while (n != 0 && l != 0) {
        l += 'A';
        for (char i = 'A'; i < l; ++i) {
            str[0] = i;
            if (dfs(1, n, l))
                break;
        }
        cin >> n >> l;
    }
    return 0;
}

int dfs(int cur, int &n, int l) {
    //cout << cur << " " << n << " " << check(cur) << "\t" << str << endl;
    if (!check(cur))
        return 0;
    --n;
    if (!n) {
        int i;
        for (i = 0; i < cur; ++i) {
            putchar(str[i]);
            if (i + 1 < cur && !((i + 1) % 4))
                if (!((i + 1) % 64))
                    putchar('\n');
                else
                    putchar(' ');
        }
        cout << endl << cur << endl;
        return 1;
    }
    for (char i = 'A'; i < l; ++i) {
        if (i != str[cur - 1]) {
            str[cur] = i;
            if (dfs(cur + 1, n, l))
                return 1;
        }
    }
    return 0;
}

bool check(int len) {
    if (len > 1) {
        for (int i = 1; i <= len / 2; ++i) {
            bool is_easy = true;
            for (int j = 1; j <= i; ++j) {
                if (str[len - j] != str[len - j - i]) {
                    is_easy = false;
                    break;
                }
            }
            if (is_easy) {
                return false;
            }
        }
    }
    return true;
}

