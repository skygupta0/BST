//Write a program to find minimum value in bst.
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node* newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return newNode(data);
  } else {
    if (data <= root->data) {
      root->left = insert(root->left, data);
    } else {
      root->right = insert(root->right, data);
    }
    return root;
  }
}

int findMin(Node* root) {
  if (root == NULL) {
    cout << "Error: Tree is empty" << endl;
    return -1;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}

int main() {
  Node* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);
  cout << "Minimum value in BST: " << findMin(root) << endl;
  return 0;
}
