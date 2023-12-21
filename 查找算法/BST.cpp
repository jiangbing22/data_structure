#include "BST.h"


TreeNode* BinarySearchTree::search(TreeNode* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}
TreeNode* BinarySearchTree::insert(TreeNode* node, int key) {
    if (node == nullptr) {
        return new TreeNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}
