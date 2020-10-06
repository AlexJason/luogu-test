#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s, s + n, comp);
    for (int i = 0; i < n; ++i) {
        cout << s[i];
    }
    cout << endl;
    delete[] s;
    return 0;
}
