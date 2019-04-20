#include <iostream>

int main() {
    int a[10];
    for (int i = 0; i < 10; ++i) {
        std::cin >> a[i];
    }
    int h;
    std::cin >> h;
    h += 30;
    int c = 0;
    for (int i = 0; i < 10; ++i) {
        if (a[i] <= h) {
            ++c;
        }
    }
    std::cout << c;
    return 0;
}
