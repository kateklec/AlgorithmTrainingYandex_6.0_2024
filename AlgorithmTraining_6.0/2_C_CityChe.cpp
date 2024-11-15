#include <iostream>
#include <vector>

int main() {
    size_t n, r;
    std::cin >> n >> r;
    std::vector<size_t> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    size_t res = 0, j = 0;

    for (int i = 0; i < n; ++i) {
        // проходим по циклу пока расстояние между arr[j] и arr[i] не станет больше r
        while (j < n && arr[j] - arr[i] <= r) {
            ++j;
        }
        // элементы от j до n нам подходят
        res += n - j;
    }

    std::cout << res;
    return 0;
}