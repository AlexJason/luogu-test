#include <iostream>

using namespace std;

#define MAX_N 200005
#define MAX_K 55

int color[MAX_N];
int cost[MAX_N];
int last[MAX_N];
long long sum[MAX_N];
int kk[MAX_K];
int kc[MAX_K];

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> color[i] >> cost[i];
        last[i] = kk[color[i]];
        if (cost[i] <= p) sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
        kk[color[i]] = i;
        ++kc[color[i]];
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        int c = kc[i];
        for (int j = kk[i]; j; j = last[j]) {
            int t = c - 1;
            for (int s = last[j]; s; s = last[s]) {
                if (sum[j] - sum[s - 1] > 0) {
                    ans += t;
                    break;
                }
                --t;
            }
            --c;
        }
    }
    cout << ans << endl;
    return 0;
}
