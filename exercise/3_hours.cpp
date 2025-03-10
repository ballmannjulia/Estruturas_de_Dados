#include <iostream>

#include "../include/hours.hpp"

/**
 * ! Exercício 3: Controle de Jornada de Trabalho
 *
 * Um funcionário registra o horário de início e término de sua jornada de
 * trabalho todos os dias. Seu objetivo é calcular o tempo total trabalhado no
 * dia e verificar se ele cumpriu a carga horária mínima de 8 horas.
 *
 * ! Entrada:
 * O programa deve solicitar ao usuário dois horários no formato HH MM SS:
 * - O primeiro horário representa a hora de entrada no trabalho.
 * - O segundo horário representa a hora de saída do trabalho.
 *
 * ! Saída:
 * O programa deve calcular o tempo total trabalhado e exibir:
 * - O tempo total no formato HH:MM:SS.
 * - Uma mensagem indicando se o funcionário cumpriu ou não a carga horária
 * mínima.
 *
 * ! Exemplo de Entrada:
 * 08 30 00  // Horário de entrada
 * 17 15 30  // Horário de saída
 *
 * ! Exemplo de Saída:
 * Tempo total trabalhado: 08:45:30
 * Carga horária mínima cumprida!
 *
 * ! Observações:
 * - Caso o funcionário tenha trabalhado menos de 8 horas, exiba: "Carga horária
 * não cumprida!"
 * - Utilize a classe Hours e seus métodos para realizar os cálculos e
 * formatação.
 */

int main() {
    Hours a(10,30,0);
    std::cout << "10h tem: " << a.to_seconds() <<"s\n";
    std::cout << "10h tem: " << a.to_minutes() <<"min\n";
    std::cout << "10h tem: " << a.to_hours() <<"h\n";
    std::cout << "10h tem: " << a.to_string() <<"\n";

    int hora, min, sec;

    Hours entrada(hora, min, sec);
    std::cout << "Digite o horário de entrada (HH MM SS): ";
    std::cin >> hora >> min >> sec;


    Hours saida(hora, min, sec);
    std::cout << "Digite o horário de saída (HH MM SS): ";
    std::cin >> hora >> min >> sec;
    

    Hours jornada = saida - entrada;

    std::cout << "Tempo total trabalhado: " << jornada.to_string() << "\n";
    if(jornada.get_hours() >= 8.0){
        std::cout << "Carga horária mínima cumprida!\n";
    } else {
        std::cout << "Carga horária não cumprida!\n";
    }
    return 0;
}