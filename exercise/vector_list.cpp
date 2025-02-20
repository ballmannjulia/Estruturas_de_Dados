#include "../include/vector_list.hpp"

/*IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE VECTORLIST*/
/*METODO: CONSTRUTOR*/

int main(int argc, char const* argv[]) {
    VectorList<int> lista(11);
    std::cout << "lista criada\n";
    
    try {
        lista.push_back(10);
        lista.push_back(20);
        lista.push_back(30);
        lista.push_back(40);
        lista.push_back(50);
        lista.push_back(60);
        lista.push_back(70);
        lista.push_back(80);
        lista.push_back(90);
        lista.push_back(100);
        lista.push_back(110);
    } catch(std::length_error erro) {
        std::cout << "Erro:" << erro.what() << std::endl;
    }
    
    lista.print();
    return 0;
}

/*METODO: INSERÇÃO*/
/*
int main(int argc, char const* argv[]) {
    VectorList<int> lista(11);
    std::cout << "Lista -> ";
    
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);
    lista.push_back(50);

    lista.print();
    
    std::cout << std::endl;

    std::cout << "Inserindo 100 na posição [1] \n";
    lista.insert(1, 100);
    
    std::cout<<std::endl;

    std::cout << "tamanho da lista após inserção: " << lista.size() << "\nLista após inserção: ";lista.print();
    
    std::cout << std::endl;
    return 0;
}

*/
/*METODO: REMOÇÃO*/
/*
int main(int argc, char const* argv[]) {
    VectorList<int> lista(11);
    std::cout << "lista criada\n";
    
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);
    lista.push_back(50);
    
    lista.remove(2);  // Remove element at position 2
    
    std::cout << "tamanho da lista: " << lista.size() << "\n";
    lista.print();
    
    return 0;
}
*/
/*METODO: OPERADOR DE ACESSO E COPIA DO CONSTRUTOR*/
/*int main(int argc, char const* argv[]) {
    VectorList<int> lista(11);
    std::cout << "lista criada\n";
    
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);
    lista.push_back(50);
    lista.push_back(60);
    
    std::cout << "Elemento no índice 3: " << lista[3] << "\n";

    VectorList<int> lista2 = lista;
    std::cout << "Lista copiada: ";
    lista2.print();
    
    return 0;
}
*/