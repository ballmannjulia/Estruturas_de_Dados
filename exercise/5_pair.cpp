#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/pair.hpp"
#include "../include/point.hpp"

template <class P>
void print_pair(const P& pair) {
    auto& first = pair.first();
    auto& second = pair.second();
    std::cout << "(" << first << ", " << second << ")" << std::endl;
}

// Definição do tipo produto como um Pair de <float, std::string>
using produto = Pair<float, std::string>;

// Função de comparação para ordenar produtos pelo preço
bool compare_produto(const produto& a, const produto& b) {
    return a.first() < b.first();
}

int main() {
    std::vector<produto> Prod;

    int n;
    std::cout << "Digite o número de produtos: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string nome;
        float preco;

        std::cin >> nome >> preco;
        Prod.push_back(produto(preco, nome));
    }

    // Ordenação correta utilizando a função de comparação
    std::sort(Prod.begin(), Prod.end(), compare_produto);

    // Exibir a lista ordenada
    std::cout << "Produtos ordenados por preço:" << std::endl;
    for (const auto& p : Prod) {
        std::cout << "Nome: " << p.second() << ", Preço: " << p.first() << std::endl;
    }

    // Exibir o produto mais barato e mais caro
    std::cout << "\nPRODUTO MAIS BARATO:" << std::endl;
    std::cout << "Nome: " << Prod.front().second() << ", Preço: " << Prod.front().first() << std::endl;

    std::cout << "\nPRODUTO MAIS CARO:" << std::endl;
    std::cout << "Nome: " << Prod.back().second() << ", Preço: " << Prod.back().first() << std::endl;

    return 0;
}
