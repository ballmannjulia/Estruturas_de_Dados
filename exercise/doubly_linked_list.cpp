#include "../include/doubly_linked_list.hpp"

int main() {
    DoublyLinkedList<int> list;


    list.push_back(10);
    std::cout <<"push_back1" << std::endl;
    list.push_back(20);
    std::cout <<"push_back2" << std::endl;
    list.pop_back();
    std::cout <<"pop_back1" << std::endl;

    (list.size(), 1);
    std::cout <<"lista tamanho" << std::endl;
    (list.empty());
    std::cout <<"lista vazia" << std::endl;

    auto it = list.find(20);
    std::cout <<"find" << std::endl;
    (
        it, list.end()); // After pop_back, 20 should no longer be in the list
        std::cout <<"find2" << std::endl;
    }
/*
int main() {
    DoublyLinkedList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.push_back(50);
    list.push_back(60);
    list.push_back(70);

    std::cout << "Lista: ";
    list.print();
    std::cout << std::endl;

    std::cout << "-----------------------------------\n";

    std::cout << "Removendo o primeiro elemento:" << std::endl;
    list.pop_front();
    list.print();
    std::cout << std::endl;

    std::cout << "-----------------------------------\n";

    std::cout << "Removendo o último elemento:" << std::endl;
    list.pop_back();
    list.print();
    std::cout << std::endl;

    std::cout << "-----------------------------------\n";

    auto it_begin = list.begin();
    ++it_begin;
    
    auto it_end = list.begin();
    it_end = it_begin + 2;


    std::cout << "Removendo os elementos da lista do segundo ao quarto:" << std::endl;
    list.erase(it_begin, it_end);
    list.print();
    std::cout << std::endl;

    std::cout << "-----------------------------------\n";

    std::cout << "Verificando elemento 20: ";
    std::cout << (list.contains(20) ? "20 está na lista" : "20 não está na lista") << std::endl;

    auto pos = list.find(20);
    list.erase(pos, pos+1);
    list.print();
    std::cout << std::endl;

    std::cout << "Estado final da lista:" << std::endl;
    list.print();
    std::cout << std::endl;

    return 0;
}*/
