#include <iostream>
#include <vector>

enum Colors { White, Grey, Black };

class Graph {
private:
    std::vector<std::vector<int>> vertex_;
    std::vector<Colors> colors_;
    std::vector<int> parents_;

public:
    Graph(int n, int m) {
        vertex_.resize(n);
        colors_.resize(n, White);
        parents_.resize(n, -1);
        for (int i = 0; i < m; i++) {
            int v1 = 0;
            int v2 = 0;
            std::cin >> v1 >> v2;
            vertex_[--v1].push_back(--v2);
            vertex_[v2].push_back(v1);
        }
    }

    void DFS(int index) {
        colors_[index] = Grey;
        for (int children : vertex_[index]) {
            if (colors_[children] == White) {
                parents_[children] = index;
                DFS(children);
            }
        }
        colors_[index] = Black;
    }

    void PrintColors() {
        for (size_t i = 0; i < colors_.size(); i++) {
            std::cout << colors_[i] << ' ';
        }
    }
    int NumComponents() {
        int count = 0;
        DFS(0);
        for (size_t i = 0; i < colors_.size(); i++) {
            if (colors_[i] == White) {
                count++;
                DFS(i);
            }
        }
        return count;
    }
};

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    Graph graph(n, m);
    std::cout << "Минимальное число дополнительных ребёр: " << graph.NumComponents() << ' ';
}
