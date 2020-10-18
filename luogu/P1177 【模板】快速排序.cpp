#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void swap_value(T &a, T &b);
template <typename T, typename Index>
void quick_sort(T *arr, Index beg, Index end);

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; ++i)
        printf("%d ", arr[i]);
    printf("%d", arr[n - 1]);
    return 0;
}

template <typename T, typename Index>
void quick_sort(T *arr, Index beg, Index end) {
    if (beg >= end)
        return;
    Index idx = rand() % (end - beg) + beg;
    //Index idx = (end + beg) / 2;
    T key = arr[idx];
    swap(arr[idx], arr[beg]);
    Index i = beg, j = end;
    while (i < j) {
        while (arr[j] >= key && i < j)
            --j;
        while (arr[i] <= key && i < j)
            ++i;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[beg], arr[i]);
    quick_sort(arr, beg, i - 1);
    quick_sort(arr, i + 1, end);
}

