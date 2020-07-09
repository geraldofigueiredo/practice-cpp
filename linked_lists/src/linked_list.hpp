#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "list_element.hpp"

namespace gf {

    template<class T>
    class LinkedList {
    private:
        ListElement<T> *head_;
        int size;
    public:
        LinkedList() : head_(nullptr), size(0) {};
        ~LinkedList();

        // int size() const;
        // bool empty() const;
        void PushFront(T data);
    };

} // namespace gf

#endif