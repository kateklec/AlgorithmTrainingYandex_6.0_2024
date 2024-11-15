#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int m, k;
    std::cin >> m >> k;
    std::vector<int> x(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i];
        x[i]--;
    }

    std::vector<int> left(n, 0);
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            left[i] = left[i - 1];
        }
        else if (arr[i - 1] > arr[i]) {
            left[i] = i;
            count = 0;
        }
        else {
            count++;
            left[i] = left[i - 1];
            while (count > k) {
                count -= (arr[left[i]] == arr[left[i] + 1]);
                left[i]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        std::cout << left[x[i]] + 1 << ' ';
    }

    return 0;
}