#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s[0] == '-') cout << '-';
    string::reverse_iterator iter = s.rbegin();
    while (iter != s.rend() && *iter == '0') ++iter;
    while (iter != s.rend() && *iter != '-') {
        cout << *iter;
        ++iter;
    }
    cout << endl;
    return 0;
}
