#include <iostream>
#include <string>

#include "src/linked_list.h"

int main(int argc, char const *argv[]) {
    
    gf::LinkedList<int> list;
    std::cout << "List size: " << list.Size() << " | is Empty? " << list.Empty() << std::endl;
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);
    list.PushBack(40);
    list.PushBack(50);
    list.PushBack(60);
    list.PushBack(70);
    std::cout << "List size: " << list.Size() << " | is Empty? " << list.Empty() << std::endl;
    list.Print();

    int position = 5;
    std::cout << "\nValue at position: " << position << " -> " << list.ValueAt(position) << std::endl;

    return 0;
}
