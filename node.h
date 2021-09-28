#ifndef NODE_H
#define NODE_H

template<typename TK, typename TV>
struct NodeAVL {
    TK key;
    TV value;
    int height;
    NodeAVL<TK, TV> *left;
    NodeAVL<TK, TV> *right;

    NodeAVL() : left(nullptr), right(nullptr), height(0) {}

    NodeAVL(TK key, TV value) : key(key), value(value), left(nullptr), right(nullptr), height(0) {}

    void killSelf() {
        if (left != nullptr) left->killSelf();
        if (right != nullptr) right->killSelf();
        delete this;
    }
};

#endif