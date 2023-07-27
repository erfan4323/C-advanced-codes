#include <iostream>
#include <vector>

struct Node {
    char color;
    int value;
    std::vector<int> children;

    Node(char c, int v) : color(c), value(v) {}
    Node() : color(' '), value(0) {}
};

int calculateMaxSubtreeSum(const std::vector<Node>& tree, int root) {
    int maxSum = tree[root].color == 'R' ? tree[root].value : 0;

    for (int child : tree[root].children) {
        int childSum = calculateMaxSubtreeSum(tree, child);
        maxSum = std::max(maxSum, childSum);
    }

    return maxSum + (maxSum > 0 ? tree[root].value : 0);
}

int main() {
    int n;

    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::vector<Node> tree(n);

    std::cout << "Enter the colors of the nodes ('R' or 'B') separated by spaces: ";
    for (int i = 0; i < n; i++) {
        char color;
        std::cin >> color;
        tree[i].color = color;
    }

    std::cout << "Enter the values of the nodes separated by spaces: ";
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        tree[i].value = value;
    }

    std::cout << "Enter the edges (u and v) separating them by spaces:\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        tree[u].children.push_back(v);
    }

    std::vector<int> redNodes;
    for (int i = 0; i < n; i++) {
        if (tree[i].color == 'R') {
            redNodes.push_back(i);
        }
    }

    int maxSum = 0;

    for (int node : redNodes) {
        int subtreeSum = calculateMaxSubtreeSum(tree, node);
        maxSum = std::max(maxSum, subtreeSum);
    }

    std::cout << "Maximum sum of subtree values: " << maxSum << std::endl;

    return 0;
}
