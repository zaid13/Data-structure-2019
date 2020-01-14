//
// Created by zaid on 9/25/2019.
//

#ifndef UNTITLED3_NODE_H
#define UNTITLED3_NODE_H

template  <class T>
class Node {
public:
    T getData() const;

    void setData(T data);

    Node *getNext() const;

    void setNext(Node *next);

public:
    T data;
    Node* next;


};

template<class T>
T Node<T>::getData() const {
    return data;
}

template<class T>
void Node<T>::setData(T data) {
    Node::data = data;
}

template<class T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<class T>
void Node<T>::setNext(Node *next) {
    Node::next = next;
}

#endif //UNTITLED3_NODE_H
