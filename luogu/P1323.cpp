#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void push_deque(deque<int> &d, int n, int &m) {
    if (n >= 10) push_deque(d, n / 10, m);
    while (m && !d.empty() && d.back() < n % 10) d.pop_back(), --m;
    d.push_back(n % 10);
}

int main() {
    int k, m;
    cin >> k >> m;
    vector<int> n;
    deque<int> d;
    n.push_back(1);
    d.push_back(1);
    int n1 = 0, n2 = 0, t1 = 3, t2 = 9;
    int c = 0;
    while (c < k - 1) {
        if (t1 < t2) {
            if (n[c] != t1) n.push_back(t1), push_deque(d, t1, m), ++c;
            ++n1;
            t1 = n[n1] * 2 + 1;
        }
        else {
            if (n[c] != t2) n.push_back(t2), push_deque(d, t2, m), ++c;
            ++n2;
            t2 = n[n2] * 4 + 5;
        }
    }
    for (vector<int>::iterator i = n.begin(); i != n.end(); ++i) cout << *i;
    cout << endl;
    for (deque<int>::iterator i = d.begin(); i != d.end(); ++i) cout << *i;
    cout << endl;
    return 0;
}
