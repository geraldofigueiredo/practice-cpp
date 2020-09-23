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
    T Front() const;
    T Back() const;
    void Insert(const unsigned int index, const T value);
    void Erase(const unsigned int index);
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
    ListElement<T> *node = head_;
    int position = 0;
    while (node) {
        if (position == index){
            break;
        }
        
        node = node->GetNext();
        position++;
    }

    if (node == nullptr) {
        std::cerr << "index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return node->Value();
}

// O(1) front insertion
template<typename T>
void LinkedList<T>::PushFront(T data) {
    auto *newNode = new ListElement<T>{data};
    newNode->SetNext(head_);
    head_ = newNode;
    this->size++;
}

// O(1) Front remotion
template<typename T>
T LinkedList<T>::PopFront() {
    if (head_ == nullptr) {
        std::cerr << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }
    ListElement<T> *node = head_;
    T value = head_->Value();
    head_ = head_->GetNext();

    delete node;
    return value;
}

// O(1) end insertion
template<typename T>
void LinkedList<T>::PushBack(T data) {
    auto *new_node = new ListElement<T>{data};
    
    if (tail_ == nullptr) {
        head_ = new_node;
        tail_ = new_node;
        return;
    }

    tail_->SetNext(new_node);
    tail_ = new_node;
    this->size++;
}

template<typename T>
T LinkedList<T>::PopBack() {
    if (head_ == nullptr) {
        std::cerr << "Empty list!" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto *currentNode = head_;
    ListElement<T> *previousNode = nullptr;
    while(currentNode->GetNext()){
        previousNode = currentNode;
        currentNode = currentNode->GetNext();
    }

    if (previousNode == nullptr) {
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        tail_ = previousNode;
        previousNode->SetNext(nullptr);
    }

    T value = currentNode->Value();
    delete currentNode;
    return value;
}

template<typename T>
T LinkedList<T>::Front() const {
    return head_->Value();
}

template<typename T>
T LinkedList<T>::Back() const {
    return tail_->Value();
}

template<typename T>
void LinkedList<T>::Insert(const unsigned int index, const T value) {
    // front insertion
    if (index == 0) {
        this->PushFront(value);
        return;
    } 
    // back insertion (this->size()-1 => 'tail index')
    if (index == this->size()-1) {
        this->PushBack(value);
        return;
    }

    // middle insertion
    auto *new_node = new ListElement<T>{value};
    ListElement<T> *node = head_;
    ListElement<T> *prev = nullptr;
    // search the index
    int position = 0;
    while (node) {
        if (position == index) {
            break;
        }

        prev = node;
        node = node->GetNext();
        position++;
    }

    // index not found
    if (node == nullptr) {
        std::cerr << "index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }

    new_node->SetNext(node);
    prev->SetNext(new_node);
}

template<typename T>
void LinkedList<T>::Erase(const unsigned int index) {
    if (index == 0) {
        this->PushFront();
    }
}

template<typename T>
void LinkedList<T>::Print() const {
    auto *currentNode = head_;
    while (currentNode != nullptr) {
        currentNode->Print();
        currentNode = currentNode->GetNext();
        if (currentNode != nullptr)
            std::cout << " -> ";
    }
}

} // namespace gf
