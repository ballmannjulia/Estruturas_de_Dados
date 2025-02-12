#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/pair.hpp"
#include "../include/point.hpp"

/**
 * ! Exercício: Cadastro e Ordenação de Produtos por Preço
 *
 * Você foi contratado para implementar um sistema simples de cadastro de
 * produtos para um mercado. Cada produto tem um nome (do tipo string) e um
 * preço (do tipo float). O sistema deve permitir as seguintes operações:
 *
 * 1. Ler uma lista de produtos com nome e preço.
 * 2. Exibir a lista de produtos ordenada por preço (do mais barato ao mais
 * caro).
 * 3. Identificar e exibir o produto mais barato e o mais caro.
 *
 * Para resolver este problema, você deve usar a classe `Pair<string, float>`
 * para armazenar o nome do produto e seu preço. Use os métodos adequados da
 * classe `Pair` para manipular os dados.
 *
 * ! Entrada:
 * A entrada consiste em:
 * - O primeiro número da entrada é um inteiro `n`, representando o número de
 * produtos.
 * - Em seguida, temos `n` linhas, cada uma com o nome e o preço de um produto,
 * separados por espaço.
 *
 * ! Saída:
 * O programa deve exibir:
 * - A lista de produtos ordenada por preço, no formato: "Nome: [nome], Preço:
 * [preço]".
 * - O nome e o preço do produto mais barato e do mais caro.
 *
 * ! Exemplo de Entrada:
 * 4
 * Arroz 4.5
 * Feijão 3.2
 * Macarrão 2.3
 * Leite 1.8
 *
 * ! Exemplo de Saída:
 * Produtos ordenados por preço:
 * Nome: Leite, Preço: 1.8
 * Nome: Macarrão, Preço: 2.3
 * Nome: Feijão, Preço: 3.2
 * Nome: Arroz, Preço: 4.5
 *
 * Produto mais barato:
 * Nome: Leite, Preço: 1.8
 *
 * Produto mais caro:
 * Nome: Arroz, Preço: 4.5
 *a
 * ! Observações:
 * - O programa deve permitir que o usuário forneça a lista de produtos e seus
 * preços.
 * - O sistema deve exibir a lista de produtos ordenada por preço de forma
 * crescente.
 * - O programa deve exibir o produto mais barato e o mais caro.
 * - A entrada e saída devem ser feitas via `cin` e `cout`, respectivamente.
 */

template <class P>
void print_pair(const P& pair) {
   auto& first = pair.first();
   auto& second = pair.second();
   std::cout << "(" << first << ", " << second << ")" << std::endl;
}

using produto = Pair<float, std::string>;

int main() {
 Pair<std::string, int> a("nome", 4);
 Pair<std::string, double> b("ola", 3.2);


 print_pair(a);
 print_pair(b);

std::vector<produto> Prod;

int n;
std::cin >> n;

for (int i = 0; i < n; i++) {
  std::string nome;
  float preco;

  std::cin >> nome >> preco;
  Prod.push_back(produto(preco, nome));
}

std::sort(Prod.begin(), Prod.end());

//for que garante iiterar do inicio ao final do vetor
for(auto &p : Prod) {
 std::cout << "Nome: " << p.second() << ", Preço: " << p.first() << std::endl;
} 

std::cout << "PRODUTO MAIS BARATO " << std::endl;
std::cout << "Nome: " << Prod[0].second() << ", Preço: " << Prod[0].first() << std::endl;

std::cout << "PRODUTO MAIS CARO " << std::endl;
std::cout << "Nome: " << Prod[Prod.size() - 1].second() << ", Preço: " << Prod[Prod.size() - 1].first() << std::endl;


  return 0;
}
