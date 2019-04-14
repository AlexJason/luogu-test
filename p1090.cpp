#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n, t, a, r = 0;
    cin >> n;
    while (n--) {
        cin >> t;
        q.push(t);
    }
    while (q.size() > 1) {
        a = q.top();
        q.pop();
        a += q.top();
        q.pop();
        r += a;
        q.push(a);
    }
    cout << r << endl;
    return 0;
}
