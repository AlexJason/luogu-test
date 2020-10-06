#include <iostream>

using namespace std;

int a[40][40];

int main() {
    int n;
    cin >> n;
    int row = 1, col = n / 2 + 1;
    a[row][col] = 1;
    for (int i = 2; i <= n * n; ++i) {
        if (row == 1 && col != n) row = n, col = col + 1;
        else if (col == n && row != 1) row = row - 1, col = 1;
        else if (row == 1 && col == n) row = row + 1;
        else if (a[row - 1][col + 1] == 0) row = row - 1, col = col + 1;
        else row = row + 1;
        a[row][col] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
