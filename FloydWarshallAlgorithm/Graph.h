#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(const std::vector<std::vector<int>>& matrix);
    void shortestDistance();
    void printMatrix() const;

private:
    std::vector<std::vector<int>> matrix;
    int n;
};

#endif
