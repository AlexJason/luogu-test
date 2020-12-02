#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX_N 205
map<string, int> smap;
vector<int> son[MAX_N];
int f[MAX_N][2];

int dfs(int i) {
    //cout << "dfs1 " << i << endl;
    f[i][0] = 0;
    f[i][1] = 1;
    for (int e = 0; e < son[i].size(); ++e) {
        const int u = son[i][e];
        dfs(u);
        f[i][0] += max(f[u][0], f[u][1]);
        f[i][1] += f[u][0];
    }
    return max(f[i][0], f[i][1]);
}

bool dfs2(int i, int k) {
    //cout << "dfs2 " << i << " " << k << endl;
    if (k == 0) {
        for (int e = 0; e < son[i].size(); ++e) {
            const int u = son[i][e];
            if (dfs2(u, 1)) return true;
        }
        return false;
    }
    if (f[i][1] == f[i][0]) return true;
    for (int e = 0; e < son[i].size(); ++e) {
        const int u = son[i][e];
        if (f[i][1] > f[i][0]) {
            if (dfs2(u, 0)) return true;
        }
        else {
            if (dfs2(u, 1)) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        string s1, s2;
        cin >> s1;
        smap[s1] = 1;
        for (int i = 1; i < n; ++i) {
            cin >> s1 >> s2;
            if (smap.find(s1) == smap.end()) {
                smap[s1] = smap.size() + 1;
            }
            if (smap.find(s2) == smap.end()) {
                smap[s2] = smap.size() + 1;
            }
            //cout << s1 << smap[s1] << " " << s2 << smap[s2] << endl;
            son[smap[s2]].push_back(smap[s1]);
        }
        cout << dfs(1) << " ";
        cout << (dfs2(1, f[1][1] >= f[1][0]) ? "No" : "Yes") << endl;
        for (int i = 1; i <= smap.size(); ++i) son[i].clear();
        smap.clear();
        cin >> n;
    }
    return 0;
}
