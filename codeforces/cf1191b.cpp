#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct mahjong_t {
    char type;
    unsigned char size;
    bool operator<(const mahjong_t &op) const {
        if (size == op.size) return type < op.type;
        return size < op.size;
    }
};

int check_mentsu(mahjong_t *mahjong);
int check_size_2_s(mahjong_t &m0, mahjong_t &m1);
int check_size_2_d(mahjong_t &m0, mahjong_t &m1);

int main() {
    mahjong_t mahjong[3];
    for (int i = 0; i < 3; ++i) {
        mahjong[i].size = getchar() ^ '0';
        mahjong[i].type = getchar();
        if (i < 2) getchar();
    }
    sort(mahjong, mahjong + 3);
    cout << check_mentsu(mahjong) << endl;
    return 0;
}

int check_mentsu(mahjong_t *mahjong) {
    if (mahjong[0].type == mahjong[1].type) {
        if (mahjong[1].type == mahjong[2].type) {
            int r0 = check_size_2_s(mahjong[0], mahjong[1]), r1 = check_size_2_s(mahjong[1], mahjong[2]);
            if (r0 == r1 && r0 != 0) {
                return 0;
            }
            else if (r0 == 0 && r1 == 0) {
                if (check_size_2_d(mahjong[0], mahjong[1]) != 0 || check_size_2_d(mahjong[1], mahjong[2]) != 0) {
                    return 1;
                }
                else {
                    return 2;
                }
            }
            else {
                return 1;
            }
        }
        else {
            if (check_size_2_d(mahjong[0], mahjong[1]) != 0) {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    else {
        if (mahjong[1].type == mahjong[2].type) {
            if (check_size_2_d(mahjong[1], mahjong[2])) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (mahjong[0].type == mahjong[2].type) {
            if (check_size_2_d(mahjong[0], mahjong[2])) {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            return 2;
        }
    }
}

int check_size_2_s(mahjong_t &m0, mahjong_t &m1) {
    if (m0.size == m1.size) {
        return 1;
    }
    if (m0.size == m1.size - 1) {
        return 2;
    }
    return 0;
}

int check_size_2_d(mahjong_t &m0, mahjong_t &m1) {
    if (m0.size == m1.size) {
        return 1;
    }
    if (m0.size == m1.size - 1) {
        return 2;
    }
    if (m0.size == m1.size - 2) {
        return 2;
    }
    return 0;
}
