#include <iostream>
#include <stdexcept>

#include "../include/vector_list.hpp"

//construtor 
template <class T>
VectorList<T>::VectorList(size_t capacity) 
  : data{new T[capacity]},_size{0},_capacity{capacity} {
    std::cout<<"Criando lista!\n ";
  }

//destrutor
template  <class T>
VectorList<T>::~VectorList() {
  delete[] data;
   std::cout<<"Deletando lista!\n ";
}

// maxima capacidade
template <class T>
size_t VectorList<T>::capacity() const {
    return _capacity;
}

// retorna a quantidade de elementos da lista
template <class T>
size_t VectorList<T>::size() const {
  return _size;
}

// adiciona um elemento no final da lista
template <class T>
void VectorList<T>::push_back(const T& value){
    if(size()>=capacity()){
        throw std::length_error("Lista cheia");
    }

    data[size()] = value;

    _size++;
}

// verifica se a lista está vazia
template <class T> 
bool VectorList<T>::empty() const {
    return size() == 0;
}

// remove o último elemento da lista
template <class T>
void VectorList<T>::pop_back()  {
    if(empty()){
        throw std::out_of_range("Lista vazia");
    }
    _size--;
}

// printa todos os elementos da lista
template <class T>
void VectorList<T>::print() const {
    for(size_t i = 0; i < size(); i++){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// insere um elemento na posição especificada
template <class T>
void VectorList<T>::insert(size_t index,const T& value) {
    if(size() >= capacity()){
        throw std::length_error("Lista cheia");
    } else if (index > size()){
        throw std::out_of_range("Posição inválida");
    }

    if(index == size()){
        return push_back(value);
    }

    for(size_t i = size(); i<=index ;i--){
        data[i] = data[i-1];
    }
    data[index] = value;

    _size++;
}

// remove um elemento na posição especificada
template <class T>
void VectorList<T>::remove(size_t index) {
    if(index >= size()){
        throw std::out_of_range("Posição inválida");
    }

    if(index == size()-1){
        return pop_back();
    }

    for (size_t i = index; i < size()-1; i++) {
        data[i] = data[i+1];
    }
    _size--;
}

// função auxiliar para encontrar um elemento na lista
template <class T> 
T* find_item_in_data(T* data, size_t size, const T& item) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] == item) {
            return &data[i];
        }
    }
    return nullptr;
}

// acha e retorna uma referencia para o elemento encontrado
template <class T>
T& VectorList<T>::find(const T& item){
    auto elemento = find_item_in_data(data, size(), item);

    if(elemento == nullptr){
        throw std::out_of_range("Item não encontrado");
    } else {
        return *elemento;
    }
}

// constante para encontrar uma função
template <class T>
const T& VectorList<T>::find(const T& item) const {
    auto elemento = find_item_in_data(data, size(), item);

    if(elemento == nullptr){
        throw std::out_of_range("Item não encontrado");
    } else {
        return *elemento;
    }
}


// verifica se o elemento existe na lista
template <class T>
bool VectorList<T>::contains(const T& item) const {
    auto elemento = find_item_in_data(data, size(), item);

    return elemento != nullptr;
}

// remove todos os elementos da lista
template <class T>
void VectorList<T>::clear() {
    _size = 0;
}

// Cria uma cópia da lista
template <class T>
VectorList<T>::VectorList(const VectorList &list) 
    : data{new T[list._capacity]}, _size{list._size}, _capacity{list._capacity} {
    for (size_t i = 0; i < list._size; i++) {
        data[i] = list.data[i];
    }
}

// Adiciona uma lista a outra
template <class T>
VectorList<T> &VectorList<T>::operator=(const VectorList &list) {
    if (this != &list) {
        delete[] data;
        _capacity = list._capacity;
        _size = list._size;
        data = new T[_capacity];
        for (size_t i = 0; i < _size; i++) {
            data[i] = list.data[i];
        }
    }
    return *this;
}

// Deixa acessar elementos usando []
template <class T>
T &VectorList<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Índice inválido");
    }
    return data[index];
}

// Deixa acessar elementos const usando [] 
template <class T>
const T &VectorList<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Índice inválido");
    }
    return data[index];
}
