#include <iostream>
#include <vector>

const long long MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long sum1 = 0; // сумма всех элементов
    long long sum2 = 0; // сумма произведений всех пар
    long long res = 0;  // итоговая сумма тройных произведений

    for (int i = 0; i < n; i++) {
        res = (res + a[i] * sum2 % MOD) % MOD;
        sum2 = (sum2 + a[i] * sum1 % MOD) % MOD;
        sum1 = (sum1 + a[i]) % MOD;
    }

    std::cout << res;

    return 0;
}