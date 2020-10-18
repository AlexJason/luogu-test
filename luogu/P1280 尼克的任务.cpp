#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 10005
int f[MAX_N];

vector<int> v[MAX_N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < MAX_N; ++i) f[i] = -0x3f3f3f3f;
    for (int i = 0; i < k; ++i) {
        int p, t;
        scanf("%d%d", &p, &t);
        v[p].push_back(t);
    }
    f[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i].size() == 0) f[i + 1] = max(f[i + 1], f[i] + 1);
        else for (int j = 0; j < v[i].size(); ++j) {
            f[i + v[i][j]] = max(f[i + v[i][j]], f[i]);
        }
    }
    printf("%d\n", f[n + 1]);
    return 0;
}
