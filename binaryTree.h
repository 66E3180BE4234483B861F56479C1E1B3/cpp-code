#ifndef DEMO_BINARYTREE_H
#define DEMO_BINARYTREE_H

#include <iostream>
#include <functional>

class Node {
public:
    char data;
    Node *lChild, *rChild;
};

void createBinaryTree(Node* &node)
{
    char ch;
    std::cin >> ch;

    if (ch == '#')
        node = NULL;
    else {
        node = (Node*)malloc(sizeof(Node));
        node->data = ch;
        createBinaryTree(node->lChild);
        createBinaryTree(node->rChild);
    }
}

void preOrder(Node* &node, const std::function<void(char)> &func)
{
    if (NULL == node)
        return;

    func(node->data);
    preOrder(node->lChild, func);
    preOrder(node->rChild, func);
}


void inOrder(Node* &node, const std::function<void(char)> &func)
{
    if (NULL == node)
        return;

    inOrder(node->lChild, func);
    func(node->data);
    inOrder(node->rChild, func);
}

void postOrder(Node* &node, const std::function<void(char)> &func)
{
    if (NULL == node)
        return;

    postOrder(node->lChild, func);
    postOrder(node->rChild, func);
    func(node->data);
}

#endif //DEMO_BINARYTREE_H
