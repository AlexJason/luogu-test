#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    char *s = new char[n];
    int rblack = 0, rwhite = 0, lblack = 0, lwhite = 0;
    char c = getchar();
    while (c < 32)
        c = getchar();
    for (int i = 0; i < n; ++i) {
        s[i] = c;
        if (s[i] == '.')
            ++rwhite;
        else
            ++rblack;
        c = getchar();
    }
    int result = rwhite;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.')
            --rwhite, ++lwhite;
        else
            --rblack, ++lblack;
        result = min(result, rwhite + lblack);
    }
    cout << result << endl;
    return 0;    
}
