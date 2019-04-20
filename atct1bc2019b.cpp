#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    const char key = s[k - 1];
    for (string::iterator i = s.begin(); i != s.end(); ++i)
        putchar(*i == key ? *i : '*');
    cout << endl;
    return 0;    
}
