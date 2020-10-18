#include <iostream>
#include <algorithm>

using namespace std;

struct score_t {
    int n;
    int sum;
    int chinese;
    bool operator>(const score_t &op) const {
        if (sum == op.sum)
            if (chinese == op.chinese) return n < op.n;
            else return chinese > op.chinese;
        else
            return sum > op.sum;
    }
};

int main() {
    int n, t;
    cin >> n;
    score_t *sc = new score_t[n];
    for (int i = 0; i < n; ++i) {
        sc[i].n = i + 1;
        cin >> sc[i].chinese >> sc[i].sum >> t;
        sc[i].sum += t + sc[i].chinese;
    }
    sort(sc, sc + n, greater<score_t>());
    for (int i = 0; i < 5; ++i) {
        cout << sc[i].n << " " << sc[i].sum << endl;
    }
    return 0;
}