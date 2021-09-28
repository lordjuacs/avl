#include "avl.h"

int main(int argc, char const *argv[]) {
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
    delete avlTree;

    return EXIT_SUCCESS;
}
