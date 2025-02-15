#include <iostream>

#include "../include/doubly_linked_list.hpp"

template <class T>
DoublyLinkedList<T>::Node::Node(const T& value)
    : value{value}, next{nullptr}, prev{nullptr} {}


template <class T>
DoublyLinkedList<T>::Node::~Node(){
    if(next != nullptr){
        delete next;
    }
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
    : head(nullptr),tail(nullptr), _size(0) {}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    if(head != nullptr){
        delete head;
    }
}

template <class T> 
size_t DoublyLinkedList<T>::size() const{
    return _size;
}

template <class T>
bool DoublyLinkedList<T>::empty() const{
    return _size == 0;
}

template <class T>
void DoublyLinkedList<T>::push_front(const T& value){
auto new_node = new Node(value);
    if(empty()){
        tail = new_node;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
    }

    head = new_node;

    _size++;
}

template <class T>
void DoublyLinkedList<T>::print() const {
    auto pos = head;
    if (!pos) {
        std::cout << "A lista está vazia!\n";
        return;
    }

    while (pos != nullptr) {
        std::cout << pos->value;
        if (pos->next != nullptr) {
            std::cout << " <-> ";
        }
        pos = pos->next;
    }
    std::cout << " -> NULL\n";
}

template <class T>
void DoublyLinkedList<T>::push_back(const T& value){
    auto new_node = new Node(value);
    if(empty()){
        head = new_node;
    }
    else{
      new_node->prev = tail;
      tail->next = new_node;
    }
    tail = new_node;

    _size++;
}

template <class T>
void DoublyLinkedList<T>::pop_front(){
    if(empty()){
        throw std::out_of_range("List is empty");
    }
    auto tmp = head;
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
    else{
        tail = nullptr;
    }

    tmp->next = nullptr;
    delete tmp;

    _size--;
}

template <class T>
void DoublyLinkedList<T>::pop_back(){
    if(empty()){
        throw std::out_of_range("Lista está vazia");
    } else if(size() == 1){
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        auto tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        tmp->prev = nullptr;


        delete tmp;
    }
    _size--;
}

template <class T>
template <class U>
DoublyLinkedList<T>::Iterator<U>::Iterator(U* ptr, bool end)
    : node{ptr}, end{end} {}

template <class T>
template <class U>
auto& DoublyLinkedList<T>::Iterator<U>::operator*() const{
    return node->value;
}

template <class T>
template <class U>
DoublyLinkedList<T>::Iterator<U>
& DoublyLinkedList<T>::Iterator<U>::operator++(){
   if(node->next == nullptr){
    end = true;
   } else {
    node = node->next;
   }
   return *this;
}

template <class T>
template <class U>
DoublyLinkedList<T>::Iterator<U>
& DoublyLinkedList<T>::Iterator<U>::operator--(){
    if(end){
        end = false;
    } else {
        node = node->prev;
    }
    return *this;
}
    
template <class T>
template <class U>
bool DoublyLinkedList<T>::Iterator<U>::operator==(
    const Iterator<U>& other) const{
        return node == other.node && end == other.end;
    }


template <class T>
template <class U>
bool DoublyLinkedList<T>::Iterator<U>::operator!=(
    const Iterator<U>& other) const{
        return !(*this == other);
    }

