#ifndef LIST_ELEMENT_HPP
#define LIST_ELEMENT_HPP

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

        ListElement* getNext() const { return next_; }
        const T& value() const { return data; }
        void setNext(ListElement *elem) { next_ = elem; }
        void setValue(const T &value) { data = value; }

        void print() const {
            std::cout << "[" << this->id << " (" << data << ")]";
        }
    };

    template<typename T>
    int ListElement<T>::id_counter = 0;

} // end namespace gf

#endif