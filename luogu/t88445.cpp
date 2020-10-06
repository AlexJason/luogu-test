#include <iostream>
#include <cstdio>
#include <cstdlib>

#ifndef CXX20
#define Integral typename
#endif

using namespace std;

typedef unsigned int uint;

template <Integral SizeType = uint, Integral DataType = int, DataType sign = -1>
class SegmentTree {
public:
    SegmentTree(DataType l[], SizeType s) {
        tree_size = s << 2;
        tag = static_cast<DataType *>(malloc(tree_size * sizeof(DataType)));
        tree = static_cast<DataType *>(malloc(tree_size * sizeof(DataType)));
        create_tree(l - 1, 1, 1, s);
    }
    ~SegmentTree() {
        if (tag != nullptr) delete tag;
        if (tree != nullptr) delete tree;
    }
    void create_tree(DataType data[], SizeType root, SizeType l, SizeType r) {
        if (l == r) {
            tree[root] = data[l];
            tag[root] = sign;
        }
        else {
            const SizeType m = (l + r) >> 1;
            create_tree(data, (root << 1), l, m);
            create_tree(data, (root << 1) | 1, m + 1 , r);
            tree[root] = tree[root << 1] + tree[(root << 1) | 1];
            tag[root] = sign;
        }
    }
    inline void push_down(SizeType root, SizeType l, SizeType r) {
        if (tag[root] != sign) {
            const SizeType m = (l + r) >> 1;
            tree[root << 1] = tag[root] * (m - l + 1);
            tree[(root << 1) | 1] = tag[root] * (r - m);
            tag[root << 1] = tag[root];
            tag[(root << 1) | 1] = tag[root];
            tag[root] = sign;
        }
    }
    DataType search(SizeType l, SizeType r, SizeType root, SizeType ll, SizeType rr) {
        if (ll >= l && rr <= r) return tree[root];
        push_down(root, ll, rr);
        DataType s = 0;
        const SizeType m = (ll + rr) >> 1;
        if (m >= l) s += search(l, r, root << 1, ll, m);
        if (m < r) s += search(l, r, (root << 1) | 1, m + 1, rr);
        return s;
    }
    void update(SizeType l, SizeType r, DataType val, SizeType root, SizeType ll, SizeType rr) {
        if (ll >= l && rr <= r) {
            tree[root] = val * (rr - ll + 1);
            tag[root] = val;
            return;
        }
        push_down(root, ll, rr);
        SizeType m = (ll + rr) >> 1;
        if (m >= l) update(l, r, val, root << 1, ll, m);
        if (m < r) update(l, r, val, (root << 1) | 1, m + 1, rr);
        tree[root] = tree[root << 1] + tree[(root << 1) | 1];
    }
    void debug() {
        for (int i = 0; i < tree_size; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
private:
    DataType *tree;
    DataType *tag;
    SizeType tree_size;
    SizeType tag_size;
};

inline char get_char() {
    //return cin.get();
    static char buffer[65536];
    static int t0 = 0, t1 = 0;
    if (t0 == t1) {
        if (cin.eof()) return EOF;
        cin.read(buffer, 65536);
        t0 = 0;
        t1 = cin.gcount();
    }
    return buffer[t0++];
}

inline void put_char(const char &ch) {
    cout.put(ch);
}

template <Integral Ty>
inline void read(Ty &res) {
    res = 0;
    char ipt = get_char();
    while (ipt < '0' || ipt > '9') ipt = get_char();
    while (ipt >= '0' && ipt <= '9') {
        res = (res << 3) + (res << 1) + (ipt ^ '0');
        ipt = get_char();
    }
}

template <Integral Ty>
inline void print(Ty val) {
    while (val) {
        put_char((val % 10) | '0');
        val /= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    read(n), read(m);
    int *l = static_cast<int *>(malloc(n * sizeof(int)));
    for (int i = 0; i < n; ++i)
        read(l[i]);
    SegmentTree<> tree(l, n);
    //tree.debug();
    int op, ll, rr;
    for (int i = 0; i < m; ++i) {
        read(op), read(ll), read(rr);
        if (op == 1) tree.update(ll, rr, 0, 1, 1, n);
        else if (op == 2) tree.update(ll, rr, 1, 1, 1, n);
        //else print(tree.search(ll, rr, 1, 1, n)), put_char('\n');
        else cout << tree.search(ll, rr, 1, 1, n) << '\n';
    }
    cout.flush();
    return 0;
}

