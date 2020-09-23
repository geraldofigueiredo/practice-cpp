#pragma once

#include <iostream>
#include "list_element.h"

namespace gf {

// LinkedList class definition
template<typename T>
class LinkedList {
private:
    ListElement<T> *head_;
    ListElement<T> *tail_;
    int size;
public:
    LinkedList() : head_(nullptr), tail_(nullptr), size(0) {};
    ~LinkedList() = default;

    int Size() const;
    bool Empty() const;
    void PushFront(T data);
    T PopFront();
    void PushBack(T data);
    T PopBack();
    void Print() const;
};

// Methods definition
template<typename T>
int LinkedList<T>::Size() const {
    return this->size;
}

template<typename T>
bool LinkedList<T>::Empty() const {
    return this->size == 0;
}

// O(1) front insertion
template<typename T>
void LinkedList<T>::PushFront(T data) {
    auto *newNode = new ListElement<T>{data};
    newNode->setNext(head_);
    head_ = newNode;
    this->size++;
}

// O(1) Front remotion
template<typename T>
T LinkedList<T>::PopFront() {
    if (head_ == nullptr) {
        std::cerr << "empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }
    ListElement<T> *node = head_;
    T value = head_->getValue();
    head_ = head_->getNext();

    delete node;
    return value;
}

// O(1) end insertion
template<typename T>
void LinkedList<T>::PushBack(T data) {
    auto *newNode = new ListElement<T>{data};
    newNode->setNext(tail_);
    tail_ = newNode;
    this->size++;
}

template<typename T>
void LinkedList<T>::Print() const {
    auto *currentNode = head_;
    while (currentNode != nullptr) {
        currentNode->print();
        currentNode = currentNode->getNext();
        if (currentNode != nullptr)
            std::cout << " -> ";
    }
}

} // namespace gf