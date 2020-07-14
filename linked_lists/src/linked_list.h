#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include "list_element.h"

namespace gf {

    template<typename T>
    class LinkedList {
    private:
        ListElement<T> *head_;
        int size;
    public:
        LinkedList() : head_(nullptr), size(0) {};
        ~LinkedList() = default;

        int Size() const;
        bool Empty() const;
        void PushFront(T data);
        void Print() const;
    };

    template<typename T>
    int LinkedList<T>::Size() const {
        return this->size;
    }

    template<typename T>
    bool LinkedList<T>::Empty() const {
        return this->size == 0;
    }

    template <typename T>
    void LinkedList<T>::PushFront(T data) {
        auto *newNode = new ListElement<T>{data};
        newNode->setNext(head_);
        head_ = newNode;
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

#endif