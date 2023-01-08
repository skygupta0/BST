//Write a program to insert a node in bst
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node* insertNode(Node* root, int data) {
  if (root == nullptr) {
    root = createNode(data);
  } else if (data <= root->data) {
    root->left = insertNode(root->left, data);
  } else {
    root->right = insertNode(root->right, data);
  }
  return root;
}

Node* findMinNode(Node* root) {
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

Node* deleteNode(Node* root, int data) {
  if (root == nullptr) {
    return root;
  } else if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    } else if (root->left == nullptr) {
      Node* temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == nullptr) {
      Node* temp = root;
      root = root->left;
      delete temp;
    } else {
      Node* temp = findMinNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}
void inorder(Node*root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }
    
}

int main() {
  Node* root = nullptr;
  root = insertNode(root, 5);
  root = insertNode(root, 10);
  root = insertNode(root, 3);
  root = insertNode(root, 4);
  root = insertNode(root, 1);
  root = insertNode(root, 11);
  inorder(root);
  cout<<" "<<endl;
  // Delete node with value 5
 // root = deleteNode(root, 5);
  //inorder(root);
  return 0;
}
