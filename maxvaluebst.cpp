#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
};

int findMax(Node* root) {
    if (root == nullptr) {
        return INT_MIN;  // Tree is empty
    }

    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);

    if (lres > res) {
        res = lres;
    }
    if (rres > res) {
        res = rres;
    }

    return res;
}

int main() {
    // Example tree:
    //       8
    //      / \
    //     4   12
    //    / \  / \
    //   2  6  10 14
    Node* root = new Node {8,
        new Node {4, new Node {2, nullptr, nullptr}, new Node {6, nullptr, nullptr}},
        new Node {12, new Node {10, nullptr, nullptr}, new Node {14, nullptr, nullptr}}
    };

    std::cout << "Max: " << findMax(root) << std::endl;

    return 0;
}
