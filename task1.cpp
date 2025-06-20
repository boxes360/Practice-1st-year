#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int N;
    std::cout << "Введите высоту пирамиды (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> pyramid(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            pyramid[i][j] = rand() % 1000 + 1;
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << pyramid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Динамическое программирование (снизу вверх)
    std::vector<std::vector<int>> dp = pyramid;
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // Восстановление пути
    std::vector<int> path;
    int current_j = 0;
    path.push_back(pyramid[0][current_j]);

    for (int i = 1; i < N; i++) {
        if (dp[i][current_j] < dp[i][current_j + 1]) {
        }
        else {
            current_j++;
        }
        path.push_back(pyramid[i][current_j]);
    }

    std::cout << "\nМинимальная сумма: " << dp[0][0] << std::endl;
    std::cout << "Путь: ";
    for (int num : path) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
