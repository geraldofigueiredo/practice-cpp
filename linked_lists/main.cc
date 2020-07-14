#include <iostream>
#include <string>

#include "src/linked_list.h"

int main(int argc, char const *argv[]) {
    
    gf::LinkedList<int> list;
    std::cout << "List size: " << list.Size() << " | is Empty? " << list.Empty() << std::endl;
    list.PushFront(10);
    list.PushFront(20);
    list.PushFront(30);
    std::cout << "List size: " << list.Size() << " | is Empty? " << list.Empty() << std::endl;
    list.Print();

    return 0;
}
