#ifndef AVLTree_H
#define AVLTree_H

#include <iostream>
#include "node.h"

template<typename TK, typename TV>
class AVLTree {
private:
    NodeAVL<TK, TV> *root;

public:
    AVLTree() : root(nullptr) {}

    void insert(TK key, TV value) {
        insert(this->root, key, value);
    }

    bool find(TK key) {
        return find(this->root, key);
    }

    void displayPreOrder() {
        displayPreOrder(this->root);
    }

    int height() {
        return height(this->root);
    }

    TK minValue() {
        return minValue(this->root);
    }

    TK maxValue() {
        return maxValue(this->root);
    }

    bool isBalanced() {
        return isBalanced(this->root);
    }

    int size() {
        return size(this->root);
    }

    void remove(TK key) {
        remove(this->root, key);
    }

    void displayPretty() {
        displayPretty(this->root, 1);
    }

    ~AVLTree() {
        if (this->root != nullptr) {
            this->root->killSelf();
        }
    }

private:
    void displayPreOrder(NodeAVL<TK, TV> *node);

    bool find(NodeAVL<TK, TV> *node, TK key);

    int height(NodeAVL<TK, TV> *node);

    bool isBalanced(NodeAVL<TK, TV> *node);

    TK minValue(NodeAVL<TK, TV> *node);

    TK maxValue(NodeAVL<TK, TV> *node);

    int size(NodeAVL<TK, TV> *node);

    void remove(NodeAVL<TK, TV> *&node, TK key);

    void displayPretty(NodeAVL<TK, TV> *node, int level);

    /*add for avl*/
    int balancingFactor(NodeAVL<TK, TV> *node);

    void insert(NodeAVL<TK, TV> *&node, TK key, TV value);

    void balance(NodeAVL<TK, TV> *&node);

    void rotateLeft(NodeAVL<TK, TV> *&parent);

    void rotateRight(NodeAVL<TK, TV> *&parent);
};

template<typename TK, typename TV>
bool AVLTree<TK, TV>::find(NodeAVL<TK, TV> *node, TK key) {
    if (node == nullptr)
        return false;
    else if (key < node->key)
        return find(node->left, key);
    else if (key > node->key)
        return find(node->right, key);
    else
        return true;
}

template<typename TK, typename TV>
bool AVLTree<TK, TV>::isBalanced(NodeAVL<TK, TV> *node) {
    if (node == nullptr)
        return true;
    else
        return abs(height(node->left) - height(node->right)) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::displayPreOrder(NodeAVL<TK, TV> *node) {
    if (node == nullptr)
        return;
    displayPreOrder(node->left);
    std::cout << node->key << "\n";
    displayPreOrder(node->right);
}

template<typename TK, typename TV>
TK AVLTree<TK, TV>::minValue(NodeAVL<TK, TV> *node) {
    if (node == nullptr)
        throw std::out_of_range("The tree is empty");
    else if (node->left == nullptr)
        return node->key;
    else
        return minValue(node->left);
}

template<typename TK, typename TV>
TK AVLTree<TK, TV>::maxValue(NodeAVL<TK, TV> *node) {
    if (node == nullptr)
        throw std::out_of_range("The tree is empty");
    else if (node->right == nullptr)
        return node->key;
    else
        return maxValue(node->right);
}

template<typename TK, typename TV>
int AVLTree<TK, TV>::size(NodeAVL<TK, TV> *node) {
    if (node == nullptr)
        return 0;
    else
        return 1 + size(node->left) + size(node->right);
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::displayPretty(NodeAVL<TK, TV> *node, int level) {
    if (node == nullptr)
        return;
    displayPretty(node->right, level + 1);
    std::cout << std::endl;
    if (node == this->root)
        std::cout << "Root->:  ";
    else {
        for (int i = 0; i < level; i++)
            std::cout << "       ";
    }
    std::cout << node->key;
    displayPretty(node->left, level + 1);
}

/* add for AVL*/
template<typename TK, typename TV>
void AVLTree<TK, TV>::insert(NodeAVL<TK, TV> *&node, TK key, TV value) {
    if (node == nullptr)
        node = new NodeAVL<TK, TV>(key, value);
    else if (key < node->key) {
        insert(node->left, key, value);
        balance(node);
    } else {
        insert(node->right, key, value);
        balance(node);
    }
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

template<typename TK, typename TV>
int AVLTree<TK, TV>::height(NodeAVL<TK, TV> *node) {
    if (node == nullptr) return -1;
    else return node->height;
}

template<typename TK, typename TV>
int AVLTree<TK, TV>::balancingFactor(NodeAVL<TK, TV> *node) {
    return height(node->left) - height(node->right);
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::balance(NodeAVL<TK, TV> *&node) {
    int hb = balancingFactor(node);
    if (hb >= 2) { //cargado por la izquierda
        if (balancingFactor(node->left) >= 1)
            rotateRight(node); //rotacion simple
        else {//<=-1, rotacion doble izquierda-derecha
            rotateLeft(node->left);
            rotateRight(node);
        }
    } else if (hb <= -2) { //cargado por la derecha
        if (balancingFactor(node->right) <= -1)
            rotateLeft(node);//rotacion simple
        else {//>=1, rotacion doble derecha-izquierda
            rotateRight(node->right);
            rotateLeft(node);
        }
    }
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::rotateLeft(NodeAVL<TK, TV> *&parent) {
    NodeAVL<TK, TV> *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent->height = std::max(height(parent->left), height(parent->right)) + 1;
    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    parent = temp;
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::rotateRight(NodeAVL<TK, TV> *&parent) {
    NodeAVL<TK, TV> *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent->height = std::max(height(parent->left), height(parent->right)) + 1;
    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    parent = temp;
}

template<typename TK, typename TV>
void AVLTree<TK, TV>::remove(NodeAVL<TK, TV> *&node, TK key) {
    if (node == nullptr)
        return;
    else if (key < node->key) {
        remove(node->left, key);
        balance(node);
    } else if (key > node->key) {
        remove(node->right, key);
        balance(node);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node; //free
            node = nullptr;
        } else if (node->left == nullptr) {
            NodeAVL<TK, TV> *temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            NodeAVL<TK, TV> *temp = node;
            node = node->left;
            delete temp;
        } else {
            TK temp = maxValue(node->left);
            node->key = temp;
            remove(node->left, temp);
        }
    }
}


#endif
