#include <iostream>
#include <string>

using namespace std;

const char num[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int to_num(char a) {
    if (a >= '0' && a <= '9') return a - '0';
    return a - 'A' + 10;
}

string add(const string &a, int n) {
    string result;
    int t = 0, p;
    string::const_reverse_iterator itera = a.rbegin();
    string::const_iterator iterb = a.begin();
    while (itera != a.rend()) {
        p = to_num(*itera) + to_num(*iterb) + t;
        if (p >= n) t = 1, p -= n;
        else t = 0;
        result.insert(result.begin(), num[p]);
        ++itera, ++iterb;
    }
    if (t) result.insert(result.begin(), num[t]);
    return result;
}

string reverse(const string &a) {
    string t;
    for (string::const_reverse_iterator iter = a.rbegin(); iter != a.rend(); ++iter) {
        t.push_back(*iter);
    }
    return t;
}

int main() {
    int n;
    string m, t;
    cin >> n >> m;
    for (int i = 1; i <= 30; ++i) {
        m = add(m, n);
        t = reverse(m);
        if (t == m) {
            cout << "STEP=" << i << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
    return 0;
}
