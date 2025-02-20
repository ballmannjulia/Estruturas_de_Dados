#include "../include/linked_list.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>


// Implementação dos métodos da classe LinkedList

// função Construtor
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), _size(0) {}

// função Destrutor
template <class T>
LinkedList<T>::~LinkedList() {
    clear();
}

//função para ver o tamanho da lista
template <class T>
size_t LinkedList<T>::size() const {
  return _size;
}

//função para verificar se a lista está vazia
template <class T>
bool LinkedList<T>::empty() const {
  return _size == 0;
}

//função para inserir um elemento em uma posição especifica
template <class T>
void LinkedList<T>::insert(size_t index, const T &value) {
    if (index > _size) {
        throw std::out_of_range("Índice invalido");
    }
    
    if (index == 0 || head == nullptr) {
        push_front(value);
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    
    for (size_t i = 0; i < index && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }
    
    Node* new_node = new Node(value);
    new_node->next = current;
    prev->next = new_node;
    _size++;
}

// função para imprimir a lista
template <class T>
void LinkedList<T>::print() const {
    auto atual = head;
    while (atual != nullptr) {
        std::cout << atual->value << " -> "; // Changed data to value
        atual = atual->next;
    }
    std::cout << "NULL" << std::endl;
}


// função para adicionar um elemento no incio
template <class T>
void LinkedList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    _size++;
}

// Operador de atribuição
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &list) {
    if (this != &list) {
        clear();
        
        if (list.head == nullptr) {
            return *this;
        }
        
        // Copy elements in correct order using temporary storage
        T* temp = new T[list._size];
        Node* current = list.head;
        size_t i = 0;
        
        // Store elements in temporary array
        while (current != nullptr) {
            temp[i++] = current->value;
            current = current->next;
        }
        
        // Add elements in reverse order to maintain original order
        for (size_t j = list._size; j > 0; j--) {
            push_front(temp[j-1]);
        }
        
        delete[] temp;
    }
    return *this;
}


// Remove o primeiro elemento
template <class T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    _size--;
}

// Remove elemento em uma posição específica
template <class T>
void LinkedList<T>::remove(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Índice inválido");
    }
    if (index == 0) {
        pop_front();
        return;
    }
    
    Node* current = head;
    Node* prev = nullptr;
    for (size_t i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    _size--;
}

// Limpa a lista
template <class T>
void LinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

// Encontra um elemento
template <class T>
T& LinkedList<T>::find(const T &item) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == item) {
            return current->value;
        }
        current = current->next;
    }
    throw std::out_of_range("Elemento não encontrado");
}

// Encontra um elemento (const)
template <class T>
const T& LinkedList<T>::find(const T &item) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == item) {
            return current->value;
        }
        current = current->next;
    }
    throw std::out_of_range("Elemento não encontrado");
}

// Verifica se contém um elemento
template <class T>
bool LinkedList<T>::contains(const T &item) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Operador de acesso []
template <class T>
T& LinkedList<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Índice inválido");
    }
    Node* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

// Operador de acesso [] const
template <class T>
const T& LinkedList<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Índice inválido");
    }
    Node* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

// Construtor do Node
template <class T>
LinkedList<T>::Node::Node(const T &value) : value(value), next(nullptr) {}

// Destrutor do Node
template <class T>
LinkedList<T>::Node::~Node() {
    next = nullptr;
}

// Copia do construtor
template <class T>
LinkedList<T>::LinkedList(const LinkedList &list) : head(nullptr), _size(0) {
    if (list.head == nullptr) return;
    
    Node* current = list.head;
    Node* tail = nullptr;
    head = new Node(current->value);
    tail = head;
    current = current->next;
    
    while (current != nullptr) {
        tail->next = new Node(current->value);
        tail = tail->next;
        current = current->next;
        _size++;
    }
    _size++;
}

