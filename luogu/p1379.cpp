#include <iostream>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;

typedef unsigned long long ull_t;
typedef signed char byte_t;

#define pos(x, y) (y * 3 + x)

class map_t {
public:
    ull_t v;
    byte_t empty;
    int deepth;
    static const ull_t t = 23207117601ll;
    inline void change(byte_t i) {
        v ^= (v & (0x0fll << (i * 4)) | (((v >> (i * 4)) & 0xfll) << (empty * 4)));
        empty = i;
    }
    inline bool check() {
        return v == t;
    }
    bool operator<(const map_t &op) const {
        return v < op.v;
    }
};

int bfs(map_t m) {
    queue<map_t> q;
    set<map_t> s;
    map_t t, p;
    s.insert(m);
    q.push(m);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t.check()) {
            return t.deepth;
        }
        if (t.empty < 6) {
            (p = t).change(t.empty + 3);
            if (s.find(p) == s.end()) {
                ++p.deepth;
                q.push(p);
                s.insert(p);
            }
        }
        if (t.empty >= 3) {
            (p = t).change(t.empty - 3);
            if (s.find(p) == s.end()) {
                ++p.deepth;
                q.push(p);
                s.insert(p);
            }
        }
        if (t.empty % 3 != 0) {
            (p = t).change(t.empty - 1);
            if (s.find(p) == s.end()) {
                ++p.deepth;
                q.push(p);
            }
        }
        if ((t.empty + 1) % 3 != 0) {
            (p = t).change(t.empty + 1);
            if (s.find(p) == s.end()) {
                ++p.deepth;
                q.push(p);
            }
        }
    }
    return -1;
}

int main() {
    ull_t v = 0;
    byte_t idx = -1;
    ull_t c;
    for (ull_t i = 0; i < 9; ++i) {
        v |= (c = getchar() ^ '0') << (i * 4);
        if (!c)
            idx = i;
    }
    map_t m;
    m.v = v;
    m.deepth = 0;
    m.empty = idx;
    cout << bfs(m) << endl;
    return 0;
}

