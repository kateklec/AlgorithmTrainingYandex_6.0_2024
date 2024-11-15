#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> pref_sum(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    pref_sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pref_sum[i] = pref_sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            std::cout << pref_sum[i] << " ";
        else
            std::cout << pref_sum[i];
    }

    return 0;
}