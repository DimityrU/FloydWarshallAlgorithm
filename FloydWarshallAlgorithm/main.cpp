#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"

std::vector<std::vector<int>> readMatrixFromFile(std::ifstream& file, int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    std::ifstream file("input.txt");

    int num_cases;
    file >> num_cases;

    std::vector<std::vector<std::vector<int>>> matrices;
    for (int case_num = 0; case_num < num_cases; ++case_num) {
        int n;
        file >> n;
        std::vector<std::vector<int>> matrix = readMatrixFromFile(file, n);
        matrices.push_back(matrix);
    }

    file.close();

    for (int case_num = 0; case_num < num_cases; ++case_num) {
        std::cout << "Case " << case_num + 1 << ":\n";
        Graph graph(matrices[case_num]);

        std::cout << "Original Matrix:\n";
        graph.printMatrix();

        graph.shortestDistance();

        std::cout << "\nShortest Distance Matrix:\n";
        graph.printMatrix();

        std::cout << "\n";
    }

    return 0;
}
