#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 200005
#define LSON(r) ((r) << 1)
#define RSON(r) (LSON(r) | 1)
#define MID(l, r) (((l) + (r)) >> 1)

int n, m;
struct node {
    int d;
    int tag;
} node[MAX_N * 4];
bool d[MAX_N];

void build_tree(int l, int r, int root) {
    if (l == r) {
        node[root].d = d[l] ? 1 : 0;
        return;
    }
    const int mid = MID(l, r);
    build_tree(l, mid, LSON(root));
    build_tree(mid + 1, r, RSON(root));
    node[root].d = node[LSON(root)].d + node[RSON(root)].d;
}

inline void push_down(int l, int r, int mid, int root) {
    if (node[root].tag) {
        node[root].tag = 0;
        node[LSON(root)].d = mid - l + 1 - node[LSON(root)].d;
        node[LSON(root)].tag ^= 1;
        node[RSON(root)].d = r - mid - node[RSON(root)].d;
        node[RSON(root)].tag ^= 1;
    }
}

void reverse(int ll, int rr, int l, int r, int root) {
    if (ll <= l && r <= rr) {
        if (l != r) push_down(l, r, MID(l, r), root);
        node[root].tag ^= 1;
        node[root].d = r - l + 1 - node[root].d;
    //printf("|%d %d:%d %d\n", l, r, root, node[root].d);
        return;
    }
    const int mid = MID(l, r);
    push_down(l, r, mid, root);
    if (ll <= mid) reverse(ll, rr, l, mid, LSON(root));
    if (mid < rr) reverse(ll, rr, mid + 1, r, RSON(root));
    node[root].d = node[LSON(root)].d + node[RSON(root)].d;
    //printf("|%d %d:%d %d\n", l, r, root, node[root].d);
}

int search(int ll, int rr, int l, int r, int root) {
    if (ll <= l && r <= rr) {
    //printf("%d %d:%d %d\n", l, r, root, node[root].d);
        return node[root].d;
    }
    const int mid = MID(l, r);
    int res = 0;
    push_down(l, r, mid, root);
    if (ll <= mid) res += search(ll, rr, l, mid, LSON(root));
    if (mid < rr) res += search(ll, rr, mid + 1, r, RSON(root));
    //printf("%d %d:%d %d\n", l, r, root, res);
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        char c;
        scanf(" %c", &c);
        d[i] = (c == '1');
    }
    build_tree(1, n, 1);
    for (int i = 1; i <= m; ++i) {
        int o, l, r;
        scanf("%d%d%d", &o, &l, &r);
        if (o == 0) reverse(l, r, 1, n, 1);
        else printf("%d\n", search(l, r, 1, n, 1));
    }
    return 0;
}
