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
    ~LinkedList();

    int Size() const;
    bool Empty() const;
    T ValueAt(const unsigned int index) const;
    void PushFront(T data);
    T PopFront();
    void PushBack(T data);
    T PopBack();
    void Print() const;
};

template<typename T>
LinkedList<T>::~LinkedList(){
    ListElement<T> *current = head_;
    ListElement<T> *next = nullptr;

    while(current) {
        next = current->GetNext();
        delete current;
        current = next;
    }
}

// Methods definition
template<typename T>
int LinkedList<T>::Size() const {
    return this->size;
}

template<typename T>
bool LinkedList<T>::Empty() const {
    return this->size == 0;
}

template<typename T>
T LinkedList<T>::ValueAt(const unsigned int index) const {
    if (this->Empty()) {
        std::cerr << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T> *node = head_;
    while (node->getNext()) {
        
    }
}

// O(1) front insertion
template<typename T>
void LinkedList<T>::PushFront(T data) {
    auto *newNode = new ListElement<T>{data};
    newNode->setNext(head_);
    head_ = newNode;
    this->Size++;
}

// O(1) Front remotion
template<typename T>
T LinkedList<T>::PopFront() {
    if (head_ == nullptr) {
        std::cerr << "Empty list!" << std::endl;
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
    this->Size++;
}

template<typename T>
T LinkedList<T>::PopBack() {
    if (head_ == nullptr) {
        std::cerr << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto *currentNode = head_;
    ListElement<T> *previousNode = nullptr;
    while(currentNode->getNext()){
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }

    if (previousNode == nullptr) {
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        tail_ = previousNode;
        previousNode->setNext(nullptr);
    }

    T value = currentNode->getValue();
    delete currentNode;
    return value;
}

template<typename T>
void LinkedList<T>::Print() const {
    auto *currentNode = head_;
    while (currentNode != nullptr) {
        currentNode->Print();
        currentNode = currentNode->getNext();
        if (currentNode != nullptr)
            std::cout << " -> ";
    }
}

} // namespace gf
