#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int left = 0, right = 0, count = 0;
    int current_sum = 0;// хранит сумму элементов между left и right

    while (right < n) {
        current_sum += nums[right];
        right++;

        while (current_sum > k && left < right) {
            current_sum -= nums[left];
            left++;
        }

        if (current_sum == k) {
            count++;
        }
    }

    std::cout << count;
    return 0;
}