#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BinarySearchTree {
private:
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    int treeSize;
    void insert(TreeNode*& node, T val);
    void copyTree(TreeNode*& node, TreeNode* otherNode);
    void deleteTree(TreeNode* node);
    void printInOrder(TreeNode* node) const;
    void printPreOrder(TreeNode* node) const;
    void printPostOrder(TreeNode* node) const;
    int calculateHeight(TreeNode* node) const;
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);
    void insert(const T val);
    int size() const;
    void printInOrder() const;
    void printPreOrder() const;
    void printPostOrder() const;
    void printBreadthOrder() const;
    void printDepthOrder() const;
    void printByLevels() const;
    int height() const;
};


template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr), treeSize(0) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) : root(nullptr), treeSize(0) {
    copyTree(root, other.root);
    treeSize = other.treeSize;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    deleteTree(root);
    root = nullptr;
    treeSize = 0;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other) {
    if (this != &other) {
        deleteTree(root);
        root = nullptr;
        treeSize = 0;
        copyTree(root, other.root);
        treeSize = other.treeSize;
    }
    return *this;
}

template <typename T>
void BinarySearchTree<T>::insert(const T val) {
    insert(root, val);
    ++treeSize;
}

template <typename T>
int BinarySearchTree<T>::size() const {
    return treeSize;
}

template <typename T>
void BinarySearchTree<T>::insert(TreeNode*& node, T val) {
    if (node == nullptr) {
        node = new TreeNode;
        node->value=val;
        node->right=nullptr;
        node->left=nullptr;
        return;
    }
    if (val < node->value) {
        insert(node->left, val);
    } else {
        insert(node->right, val);
    }
}

template <typename T>
void BinarySearchTree<T>::copyTree(TreeNode*& node, TreeNode* otherNode) {
    if (otherNode == nullptr) {
        node = nullptr;
        return;
    }
    node = new TreeNode(otherNode->value);
    copyTree(node->left, otherNode->left);
    copyTree(node->right, otherNode->right);
}

template <typename T>
void BinarySearchTree<T>::deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template <typename T>
void BinarySearchTree<T>::printInOrder(TreeNode* node) const {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->value << " ";
    printInOrder(node->right);
}

template <typename T>
void BinarySearchTree<T>::printPreOrder(TreeNode* node) const {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template <typename T>
void BinarySearchTree<T>::printPostOrder(TreeNode* node) const {
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->value << " ";
}

template <typename T>
void BinarySearchTree<T>::printInOrder() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printPreOrder() const {
    printPreOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printPostOrder() const {
    printPostOrder(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printBreadthOrder() const {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        std::cout << node->value << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printDepthOrder() const {
    if (root == nullptr) return;

    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();

        std::cout << node->value << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }

    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::printByLevels() const {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);
    int level=1;
    while (!q.empty()) {
        int levelSize = q.size();
        std::cout << "Level " << level << ": ";
        level++;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            std::cout << node->value << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        std::cout << std::endl;
    }
}

template <typename T>
int BinarySearchTree<T>::calculateHeight(TreeNode* node) const {
    if (node == nullptr) return 0;
    return 1 + std::max(calculateHeight(node->left), calculateHeight(node->right));
}

template <typename T>
int BinarySearchTree<T>::height() const {
    return calculateHeight(root);
}

#endif
