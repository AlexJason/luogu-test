#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef unsigned long long hash_t;

hash_t hash(string str, hash_t base, hash_t mod);

int main() {
    const hash_t base = 97;
    const hash_t mod = 998244353;
    int m, c = 0;
    string str;
    set<hash_t> l;
    cin >> m;
    while (m--) {
        cin >> str;
        hash_t h = ::hash(str);
        if (l.find(h) == l.end()) {
            l.insert(h);
            ++c;
        }
    }
    cout << c << endl;
    return 0;
}

hash_t hash(string str, hash_t base = 97, hash_t mod = 998244353) {
    hash_t result = 0;
    for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter) {
        result = (result * base + *iter) % mod;
    }
    return result;
}



