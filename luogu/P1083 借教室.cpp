#include <algorithm>
#include <cstdio>
using namespace std;

#define INF 0x7fffffff
#define MAX_N 1000005
#define LSON(x) ((x) << 1)
#define RSON(x) (((x) << 1) | 1)
#define GET_MID(l, r) (((l) + (r)) >> 1)

struct node_t {
    int v;
    int lazy_tag;
};

node_t tree[MAX_N * 4];
int v[MAX_N];
int n, m;

void build_tree(int root, int l, int r) {
    if (l == r) {
        tree[root].v = v[l];
        tree[root].lazy_tag = 0;
        return;
    }
    const int mid = GET_MID(l, r);
    build_tree(LSON(root), l, mid);
    build_tree(RSON(root), mid + 1, r);
    tree[root].v = min(tree[LSON(root)].v, tree[RSON(root)].v);
}

inline void push_down(int root) {
    if (tree[root].lazy_tag != 0) {
        tree[LSON(root)].v += tree[root].lazy_tag;
        tree[LSON(root)].lazy_tag += tree[root].lazy_tag;
        tree[RSON(root)].v += tree[root].lazy_tag;
        tree[RSON(root)].lazy_tag += tree[root].lazy_tag;
        tree[root].lazy_tag = 0;
    }
}

int add(int ll, int rr, int data, int root, int l, int r) {
    if (ll <= l && r <= rr) {
        tree[root].v += data;
        tree[root].lazy_tag += data;
        return tree[root].v;
    }
    push_down(root);
    const int mid = GET_MID(l, r);
    int res = INF;
    if (ll <= mid) res = min(res, add(ll, rr, data, LSON(root), l, mid));
    if (mid < rr) res = min(res, add(ll, rr, data, RSON(root), mid + 1, r));
    tree[root].v = min(tree[LSON(root)].v, tree[RSON(root)].v);
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    build_tree(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int d, s, t;
        scanf("%d%d%d", &d, &s, &t);
        if (add(s, t, -d, 1, 1, n) < 0) {
            printf("-1\n%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
