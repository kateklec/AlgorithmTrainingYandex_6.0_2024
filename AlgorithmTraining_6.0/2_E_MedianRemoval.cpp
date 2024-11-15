#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    if (n % 2 == 0) {

        int left_median = (n / 2) - 1;
        int right_median = n / 2;

        std::cout << arr[left_median] << " " << arr[right_median] << " ";

        int left = left_median - 1;
        int right = right_median + 1;

        while (left >= 0 || right < n) {
            if (left >= 0) {
                std::cout << arr[left] << " ";
                left--;
            }
            if (right < n) {
                std::cout << arr[right] << " ";
                right++;
            }
        }
    }
    else {

        int median = n / 2;
        std::cout << arr[median] << " ";

        int left = median - 1;
        int right = median + 1;

        while (left >= 0 || right < n) {
            if (left >= 0) {
                std::cout << arr[left] << " ";
                left--;
            }
            if (right < n) {
                std::cout << arr[right] << " ";
                right++;
            }
        }
    }

    return 0;
}