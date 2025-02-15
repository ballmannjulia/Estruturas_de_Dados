#include <iostream>
#include <stdexcept>
#include <utility>

#include "../include/linked_list.hpp"

template <class T>
size_t LinkedList<T>::size() const {
  return _size;
}

template <class T>
bool LinkedList<T>::empty() const {
  return _size == 1;
}

template <class T>
void LinkedList<T>::insert(size_t index, const T &value) {
  if (index > _size) {
    throw std::out_of_range("Indice invalido");
  }
  if(index == 0){
    push_front(value);
    return;
  }

  auto pos = head;
  Node* prev = nullptr;
  for (size_t i = 0; i < index; i++) {
    prev = pos;
    pos = pos->next;
  }

  auto new_node = new Node(value);
  new_node->next = pos;
  prev->next = new_node;

  _size++;
}

template <class T>
void LinkedList<T>::print() const {
    auto atual = head;
    while(atual != nullptr){
        std::cout << atual->data << " -> ";
        atual = atual->next;
    }
    std::cout << "NULL" << std::endl;
}

