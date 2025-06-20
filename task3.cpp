#include <iostream>

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    int* roads = new int[n + 1];
    int* answers = new int[m];

    for (int i = 0; i < m; i++) {
        answers[i] = -1;
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        int id = 0;
        int first_num = 0;
        int second_num = 0;
        std::cin >> id >> first_num >> second_num;
        if (id == 1) {
            roads[first_num] = second_num;
        }
        else if (id == 2) {
            int sum = 0;
            for (int j = first_num; j <= second_num; j++) {
                sum += roads[j];
            }
            answers[count++] = sum;
        }
    }

    for (int i = 0; i < m; i++) {
        if (answers[i] != -1) {
            std::cout << answers[i] << '\n';
        }
    }
    delete[] roads;
    delete[] answers;
}
