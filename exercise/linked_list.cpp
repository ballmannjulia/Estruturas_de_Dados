#include "../include/linked_list.hpp"
#include <iostream>

int main(int argc, char const* argv[]) {
    LinkedList<int> list;

    // Adding elements to front
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_front(50);

    std::cout << "Lista original: ";
    std::cout << "tamanho da lista original:" << list.size() << std::endl;
    list.print();

    std::cout << "-----------------------------------\n";

    // Inserting elements at specific positions
    list.insert(2, 11);
    list.insert(3, 12);
    list.insert(7, 14);

    std::cout << "Depois da inserção: ";
    list.print();

    std::cout << "-----------------------------------\n";

    // Testing removal
    list.remove(2);
    std::cout << "depois de remover o i[2]: ";
    list.print();

    std::cout << "-----------------------------------\n";

    // Testing element access
    std::cout << "Elemento no i[3]: " << list[3] << std::endl;
    list.print();

    std::cout << "-----------------------------------\n";

    // Testing search
    if (list.contains(12)) {
        std::cout << "Verificando elemento 12" << std::endl;
        std::cout << (list.contains(12) ? "12 está na lista" : "12 não está na lista") << std::endl;
    }
    list.print();

    std::cout << "-----------------------------------\n";

    // Testing copy
    LinkedList<int> list2 = list;
    std::cout << "Copied list: ";
    list2.print();

    std::cout << "-----------------------------------\n";

    // Testing size
    std::cout << "Tamanho da lista: " << list.size() << std::endl;

    std::cout << "-----------------------------------\n";

    // Testing pop_front
    list.pop_front();
    std::cout << "Lista depois do pop_front: ";
    list.print();

    std::cout << "-----------------------------------\n";


    std::cout << "Lista depois das mudanças\n: ";
    list.print();

    std::cout << "-----------------------------------\n";
    return 0;
}
