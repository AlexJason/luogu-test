#include <iostream>
#include <cstring>

using namespace std;

struct bulb {
    int *light_connected;
    int k;
};

int dfs(int i, int n, int m, bool *p, bool *lights, bulb *bulbs);

int main() {
    int n, m, k;
    cin >> n >> m;
    bulb *bulbs = new bulb[m];
    bool *lights = new bool[n];
    bool *p = new bool[m];
    memset(lights, 0, sizeof(bool) * n);
    for (int i = 0; i < m; ++i) {
        cin >> bulbs[i].k;
        bulbs[i].light_connected = new int[bulbs[i].k];
        for (int j = 0; j < bulbs[i].k; ++j) {
            cin >> bulbs[i].light_connected[j];
            --bulbs[i].light_connected[j];
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> k;
        p[i] = k & 1;
    }
    cout << dfs(0, n, m, p, lights, bulbs) << endl;
    return 0;
}

int dfs(int i, int n, int m, bool *p, bool *lights, bulb *bulbs) {
    int result = 0;
    if (i == n) {
        cout << endl;
        bool flag = true;
        for (int i = 0; i < m; ++i) {
            int k = 0;
            for (int j = 0; j < bulbs[i].k; ++j)
                k += lights[bulbs[i].light_connected[j]];
            if ((k & 1) ^ p[i])
                flag = false;
        }
        if (flag)
            ++result;
        return result;
    }
    lights[i] = false;
    result += dfs(i + 1, n, m, p, lights, bulbs);
    lights[i] = true;
    result += dfs(i + 1, n, m, p, lights, bulbs);
    return result;
}
