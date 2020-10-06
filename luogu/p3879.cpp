#include <iostream>
#include <map>
#include <list>

using namespace std;

int main() {
    int n, m, l;
    string word;
    cin >> n;
    map<string, list<int> > w;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> word;
            w[word].push_back(i + 1);
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> word;
        bool f = true;
        int last = 0;
        if (w.find(word) != w.end()) {
            list<int> &lst = w.find(word)->second;
            list<int>::iterator iter = lst.begin();
            while (iter != lst.end()) {
                if (*iter == last) {
                    ++iter;
                    continue;
                }
                if (f) f = false;
                else cout << " ";
                cout << (last = *iter);
                ++iter;
            }
        }
        cout << endl;
    }
    return 0;
}
