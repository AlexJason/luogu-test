#include <iostream>
#include <vector>

using namespace std;

template <class T>
class heap {
public:
    heap() { }
    ~heap() { }
    size_t size() {
        return data.size();
    }
    T top() {
        return data[0];
    }
    void insert(const T &v) {
        size_t i = data.size();
        data.push_back(v);
        while (data[i] <= data[(i - 1) / 2] && i >= 0) {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void erase() {
        if (data.empty())
            return;
        size_t i = data.size() - 1;
        data[0] = data[i];
        data.pop_back();
        size_t idx = 0;
        while (true) {
            if (idx * 2 + 2 < i) {
                if (data[idx * 2 + 2] < data[idx * 2 + 1]) {
                    if (data[idx] > data[idx * 2 + 2]) {
                        swap(data[idx], data[idx * 2 + 2]);
                        idx = idx * 2 + 2;
                    }
                    else
                        break;
                }
                else {
                    if (data[idx] > data[idx * 2 + 1]) {
                        swap(data[idx], data[idx * 2 + 1]);
                        idx = idx * 2 + 1;
                    }
                    else
                        break;
                }
            }
            else if (idx * 2 + 1 < i) {
                if (data[idx] > data[idx * 2 + 1]) {
                    swap(data[idx], data[idx * 2 + 1]);
                    idx = idx * 2 + 1;
                }
                else
                    break;
            }
            else {
                break;
            }
        }
    }
private:
    vector<T> data;
};

int main() {
    long long n, x, y;
    cin >> n;
    heap<long long> h;
    while (n--) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            h.insert(y);
        }
        else if (x == 2) {
            cout << h.top() << endl;
        }
        else {
            h.erase();
        }
    }
    return 0;
}
