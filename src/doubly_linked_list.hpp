#include <iostream>

#include "../include/doubly_linked_list.hpp"

//Construtor da classe Node
template <class T>
DoublyLinkedList<T>::Node::Node(const T& value)
    : value{value}, next{nullptr}, prev{nullptr} {}

// Destrutor da classe Node
template <class T>
DoublyLinkedList<T>::Node::~Node(){
    next = nullptr; 
    prev = nullptr;
}

//Construtor da classe DoublyLinkedList
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
    : head(nullptr),tail(nullptr), _size(0) {}

//Destrutor da classe DoublyLinkedList
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (!empty()) {
        pop_back();
    }
}


// tamanho da lista DoublyLinkedList
template <class T> 
size_t DoublyLinkedList<T>::size() const{
    return _size;
}

// Verifica se a lista está vazia
template <class T>
bool DoublyLinkedList<T>::empty() const{
    return _size == 0;
}

// Insere um elemento no início da lista
template <class T>
void DoublyLinkedList<T>::push_front(const T& value) {
    auto new_node = new Node(value);
    if (empty()) {
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
    }
    head = new_node;
    _size++;
}

// Imprime a lista
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

// Insere um elemento no final da lista
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

// Remove o primeiro elemento da lista
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

    delete tmp;

    _size--;
}

// Remove o último elemento da lista
template <class T>
void DoublyLinkedList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }

    Node* old_tail = tail;  // Guarda o ponteiro do nó que será removido

    if (head == tail) {  // Se há apenas um elemento na lista
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;  // Atualiza `tail` para o penúltimo nó
        if (tail) { 
            tail->next = nullptr;  // Remove a referência para `old_tail`
        }
    }

    delete old_tail;
    _size--;

    // Garantia extra para evitar ponteiros inválidos
    if (_size == 0) {  
        head = nullptr;
        tail = nullptr;
    }
}

// Iterador da lista DoublyLinkedList
template <class T>
template <class U>
DoublyLinkedList<T>::Iterator<U>::Iterator(U* ptr, bool end)
    : node{ptr}, end{end} {}

// Begin iterator
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return iterator(head, empty());
}

template <class T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const{
    return const_iterator(head, empty());
}


// End iterator
template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return iterator(tail, true);
}

template <class T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const{
    return const_iterator(tail, true);
}


// Função para o iterador de adição
template <class T>
template <class U>
typename DoublyLinkedList<T>::template Iterator<U> 
DoublyLinkedList<T>::Iterator<U>::operator+(size_t n) const {
    auto result = *this;
    for (size_t i = 0; i < n && result.node != nullptr; ++i) {
        ++result;
    }
    return result;
}

template <class T>
template <class U>
typename DoublyLinkedList<T>::template Iterator<U> 
DoublyLinkedList<T>::Iterator<U>::operator-(size_t n) const {
    auto result = *this;
    for (size_t i = 0; i < n && result.node != nullptr; ++i) {
        --result;
    }
    return result;
}


// Função que Desreferencia o iterador e retorna o valor armazenado no nó atual * -> ponteio para o nó atual
template <class T>
template <class U>
auto& DoublyLinkedList<T>::Iterator<U>::operator*() const{
    return node->value;
}

// Avança o iterador para o próximo nó
template <class T>
template <class U>
typename DoublyLinkedList<T>::template Iterator<U>&
DoublyLinkedList<T>::Iterator<U>::operator++() {
    if (node->next == nullptr) {
        end = true;
    } else {
        node = node->next;
    }
    return *this;
}


// Função que retrocede o iterador para o nó anterior -> decrementa o ponteiro para o nó anterior
template <class T>
template <class U>
DoublyLinkedList<T>::Iterator<U> & DoublyLinkedList<T>::Iterator<U>::operator--(){
    if(end){
        end = false;
    } else {
        node = node->prev;
    }
    return *this;
}

// Função Insert 
template <class T>
void DoublyLinkedList<T>::insert(iterator pos, const T& value) {
    if (pos == begin()) {
        push_front(value);
        return;
    } 
    if (pos == end()) {
        push_back(value);
        return;
    }

    Node* node_pos = pos.node;
    Node* node_prev = node_pos->prev;  // Store previous node safely

    auto new_node = new Node(value);
    new_node->next = node_pos;
    new_node->prev = node_prev;

    if (node_prev) {
        node_prev->next = new_node;
    }
    node_pos->prev = new_node;

    _size++;
}


// Função que verifica se dois iteradores são iguais -> compara os ponteiros dos nós dos iteradores
template <class T>
template <class U>
bool DoublyLinkedList<T>::Iterator<U>::operator==(
    const Iterator<U>& other) const{
        return node == other.node && end == other.end;
    }

// Função que verifica se dois iteradores são diferentes -> inverso da função acima
template <class T>
template <class U>
bool DoublyLinkedList<T>::Iterator<U>::operator!=(
    const Iterator<U>& other) const{
        return !(*this == other);
    }

//Função para remover uma faixa de elementos da lista, definida pelos iteradores.
template <class T>
void DoublyLinkedList<T>::erase(iterator first, iterator last) {
    if (empty() || first == last) {
        return;
    }

    Node* atual = first.node;
    Node* final = last.end? nullptr: last.node;

    // Se estamos removendo do início da lista
    if (atual == head) {
        head = final;
    } else if (atual->prev) {
        atual->prev->next = final;
    }

    // Se estamos removendo até o final da lista
    if (final == nullptr || last.end) {
        tail = atual->prev;
        if (tail) {
            tail->next = nullptr;
        }
    } else {
        final->prev = atual->prev;
    }

    // Deletar os nós no intervalo
    while (atual && atual != final) {
        Node* next = atual->next;
        delete atual;
        _size--;
        atual = next;
    }

    // Garantir que se a lista estiver vazia, os ponteiros sejam resetados
    if (_size == 0) {
        head = nullptr;
        tail = nullptr;
    }
}

// Second overload - for calculating distance between iterators
template <class T>
template <class U>
size_t DoublyLinkedList<T>::Iterator<U>::operator-(Iterator<U> other) const {
    if (this->node == other.node) {
        return 0;
    }

    size_t distance = 0;
    auto it = other;

    while (it.node && it.node != this->node) {
        it.node = it.node->next;
        ++distance;
    }

    if (it.node == this->node) {
        return distance;
    }

    distance = 0;
    it = other;
    while (it.node && it.node != this->node) {
        it.node = it.node->prev;
        ++distance;
    }

    return (it.node == this->node) ? distance : static_cast<size_t>(-1);
}

template <class T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::find(const T& item) {
    auto it = begin();
    while (it != end()) {
        if (*it == item) {
            break;
        }
        ++it;
    }

    return it;
}

							
template <class T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::find(const T& item) const{
    auto it = begin();
    while (it != end()) {
        if (*it == item) {
            break;
        }
        ++it;
    }
    return it;
}

								 
template <class T>
bool DoublyLinkedList<T>::contains(const T& item) const{
    return find(item) != end();
}

template <class T>
T& DoublyLinkedList<T>::operator[](size_t index){
    if( index >= size()){
        throw std::out_of_range("Índice invalido!!");
    }
    auto it = begin();
    for(size_t i=0; i<index; ++i){
        ++it;
    }
    return *it;
}

				
template <class T>
const T& DoublyLinkedList<T>::operator[](size_t index) const{
    if( index >= size()){
        throw std::out_of_range("Índice invalido!!");
    }
    return *(begin() + index);
}

// Limpa a lista
template <class T>
void DoublyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    _size = 0;
}
					   
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
    : head(nullptr), tail(nullptr), _size(0) {
    for (const auto& i : list) {
        push_back(i);
    }
}
