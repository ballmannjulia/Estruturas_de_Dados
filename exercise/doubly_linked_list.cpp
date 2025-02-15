#include "../include/doubly_linked_list.hpp"

int main() {
    DoublyLinkedList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.print();

    std::cout << "Removendo o primeiro elemento..." << std::endl;
    list.pop_front();
    list.print();

    std::cout << "Removendo o último elemento..." << std::endl;
    list.pop_back();
    list.print();

    return 0;
}
