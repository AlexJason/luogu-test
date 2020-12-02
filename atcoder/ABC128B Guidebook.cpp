#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct restaruant {
    string city;
    short score;
    short order;
    bool operator<(const restaruant &op) const {
        if (city == op.city)
            return score > op.score;
        return city < op.city;
    }
};

int main() {
    int n;
    cin >> n;
    restaruant *lst = new restaruant[n];
    for (int i = 0; i < n; ++i) {
        cin >> lst[i].city >> lst[i].score;
        lst[i].order = i + 1;
    }
    sort(lst, lst + n);
    for (int i = 0; i < n; ++i) {
        cout << lst[i].order << endl;
    }
    return 0;
}
