#include "Graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph(const std::vector<std::vector<int>>& matrix) : matrix(matrix), n(matrix.size()) {}

void Graph::shortestDistance() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] < 0) {
            return;
        }
    }

    for (int via = 0; via < n; ++via) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][via] != 1e9 && matrix[via][j] != 1e9) {
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

void Graph::printMatrix() const {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}
