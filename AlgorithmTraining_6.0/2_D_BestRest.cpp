#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int left = 0, maxWindow = 0;

    for (int right = 1; right < n; ++right) {

        while (std::abs(a[right] - a[left]) > k) {
            left++;
        }

        maxWindow = std::max(maxWindow, right - left);
    }

    std::cout << maxWindow + 1;

    return 0;
}