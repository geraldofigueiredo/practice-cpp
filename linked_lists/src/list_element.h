#pragma once

#include <iostream>

namespace gf {
    
    template <typename T>
    class ListElement {
    private:
        ListElement<T> *next_;
        T data;
        static int id_counter;
        const int id;
    public:
        ListElement(const T &value) : next_(nullptr), data(value), id(id_counter++) {};
        ~ListElement() {};

        ListElement* GetNext() const { return next_; }
        const T& Value() const { return data; }
        void SetNext(ListElement *elem) { next_ = elem; }
        void SetValue(const T &value) { data = value; }

        void Print() const {
            std::cout << "[" << this->id << " (" << data << ")]";
        }
    };

    template<typename T>
    int ListElement<T>::id_counter = 0;

} // end namespace gf
