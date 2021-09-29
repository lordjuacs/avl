#include "avl.h"
#include <algorithm>
#include <iostream>
int main(int argc, char const *argv[]) {
    /*
    AVLTree<int, std::string> *avlTree = new AVLTree<int, std::string>();
    int n, key;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> key;
        avlTree->insert(key, "Juan");
    }

    char option = argv[1][0];
    switch (option) {
        case '1':
            avlTree->displayPreOrder();
            break;
        case '2':
            std::cout << avlTree->height();
            break;
        case '3':
            std::cout << avlTree->isBalanced();
            break;
        case '4': {
            std::cin >> key;
            avlTree->remove(key);
            std::cout << avlTree->height();
            break;
        }
        case '5': {
            avlTree->remove(avlTree->minValue());
            avlTree->remove(avlTree->minValue());
            avlTree->remove(avlTree->minValue());
            std::cout << avlTree->height();
            break;
        }
        default:
            std::cout << "option not found";
            break;
    }
    delete avlTree;*/
    AVLTree<int, int> avl;
    avl.insert(3, 1);
    avl.insert(10, 1);
    avl.insert(19, 1);
    avl.insert(23, 1);
    avl.insert(30, 1);
    avl.insert(37, 1);
    avl.insert(49, 1);
    avl.insert(59, 1);
    avl.insert(62, 1);
    avl.insert(70, 1);
    avl.insert(80, 1);
    avl.insert(89, 1);
    avl.insert(93, 1);
    avl.insert(97, 1);
    int a = 25, b = 90;
    auto rango = avl.range(a, b);
    std::sort(rango.begin(), rango.end());
    for(auto f : rango)
        std::cout << f << " ";
    avl.displayPretty();
    return EXIT_SUCCESS;
}
