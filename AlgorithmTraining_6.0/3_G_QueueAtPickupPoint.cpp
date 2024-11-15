#include <iostream>
#include <vector>

int main() {
    int n;
    long long b;
    std::cin >> n >> b;

    std::vector<long long> clients(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> clients[i];
    }

    long long totalTime = 0;
    long long queueLength = 0;

    for (int i = 0; i < n; ++i) {
        queueLength += clients[i];

        long long served = std::min(queueLength, b);
        totalTime += served;

        long long remainingClients = queueLength - served;
        totalTime += remainingClients;

        queueLength -= served;
    }

    totalTime += queueLength;

    std::cout << totalTime << std::endl;
    return 0;
}