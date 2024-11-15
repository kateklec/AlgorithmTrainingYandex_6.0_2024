#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> employees(n);

    for (int i = 0; i < n; i++) {
        std::cin >> employees[i];
    }

    std::vector<long long> left_sum(n, 0);
    std::vector<long long> right_sum(n, 0);

    long long current_left = 0;
    long long total_left_employees = 0;

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            left_sum[i] = left_sum[i - 1] + total_left_employees; // переходы из предыдущих кабинетов
        }
        total_left_employees += employees[i]; // обновляем общее количество сотрудников
        current_left += employees[i]; // сохраняем текущее количество сотрудников
    }

    long long current_right = 0;
    long long total_right_employees = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            right_sum[i] = right_sum[i + 1] + total_right_employees; // переходы из следующих кабинетов
        }
        total_right_employees += employees[i];
        current_right += employees[i];
    }

    // минимальная сумма переходов
    long long min_moves = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; i++) {
        long long total_moves = left_sum[i] + right_sum[i];
        min_moves = std::min(min_moves, total_moves);
    }

    std::cout << min_moves;

    return 0;
}