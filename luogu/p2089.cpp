#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> result;

void dfs(int n, int remain, string s) {
    if (remain >= 0) {
        if (n == 10) {
            if (remain < 3) {
                s.push_back(remain + 1 + '0');
                result.insert(s);
            }
        }
        else {
            dfs(n + 1, remain, s + "1 ");
            dfs(n + 1, remain - 1, s + "2 ");
            dfs(n + 1, remain - 2, s + "3 ");
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 10 || n > 30) {
        cout << 0 << endl;
    }
    else {
        dfs(1, n - 10, "");
        cout << result.size() << endl;
        for (set<string>::iterator iter = result.begin(); iter != result.end(); ++iter) {
            cout << *iter << endl;
        }
    }
    return 0;
}
