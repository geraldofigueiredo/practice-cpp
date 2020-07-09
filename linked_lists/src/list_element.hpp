#ifndef NODE_HPP
#define NODE_HPP

namespace gf {
    
    template <class T>
    class ListElement {
    private:
        ListElement<T> *next_;
        T data;
    public:
        ListElement(const T &value) : next_(nullptr), data(value) {};
        ~ListElement() {};

        ListElement* getNext() const { return next_; }
        const T& value() const { return data; }
        void setNext(ListElement *elem) { next_ = elem; }
        void setValue(const T &value) { data = value; }
    };

} // end namespace gf

#endif