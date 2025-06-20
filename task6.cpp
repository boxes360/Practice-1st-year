#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    int a, b, x, y, sum = 0;
    int* result = new int[n];

    for (int i = 0; i < n; i++) {
        sum = 0;
        a, b, x, y = 0;
        std::cin >> a >> b >> x >> y;
        if (b - x >= 0) {
            sum += x;
            x = 0;
        }
        else {
            sum += b;
            x = x - b;
        }

        if (a - x > 0) {
            sum += x;
            a = a - x;
            if (a - y >= 0) {
                sum += y;
                y = 0;
            }
            else {
                sum += a;
                y = y - a;
            }
        }
        else {
            sum += a;
            y = y - a;
        }

        result[i] = sum;
    }

    std::cout << "\nResult\n";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << ' ';
    }
    delete[] result;
}
