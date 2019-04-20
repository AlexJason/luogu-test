#include <iostream>

using namespace std;

constexpr bool result[5][5] = {
    { 0, 0, 1, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 0, 1, 0, 0, 1 },
    { 0, 0, 1, 0, 1 },
    { 1, 1, 0, 0, 0 }
};

int main() {
    short n, na, nb;
    cin >> n >> na >> nb;
    short *ra = new short[na], *rb = new short[nb];
    for (int i = 0; i < na; ++i)
        cin >> ra[i];
    for (int i = 0; i < nb; ++i)
        cin >> rb[i];
    short sa = 0, sb = 0;
    while (n--) {
        sa += result[ra[n % na]][rb[n % nb]];
        sb += result[rb[n % nb]][ra[n % na]];
    }
    cout << sa << ' ' << sb << endl;
    return 0;
}
