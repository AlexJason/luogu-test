#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
typedef unsigned long long ull_t;
 
#define MAX_N 205
char ss[MAX_N];
 
int n, k;
string s;
 
bool win[3][3] = {
    { true, false, true },
    { true, true, false },
    { false, true, true }
};
 
char c[3] = { 'R', 'P', 'S' };
 
inline int getn(char c) {
    switch (c) {
        case 'R': return 0;
        case 'P': return 1;
        case 'S': return 2;
    }
    return -1;
}
 
int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n * 2; ++i) {
        ss[i] = getn(s[i % n]);
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (win[ss[2 * j]][ss[2 * j + 1]]) ss[j] = ss[2 * j];
            else ss[j] = ss[2 * j + 1];
        }
        for (int j = 0; j < n; ++j) {
            ss[j + n] = ss[j];
        }
    }
    cout << c[ss[0]] << endl;
    return 0;
}
