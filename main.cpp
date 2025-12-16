
// ---------------------------------------------------------
// Programa: Jogo de matemática: adivinhe um número de 1 a 10
// Autor: Daniel Vinicius
// Data de início: 01/12/2025
// Última atualização: 04/12/2025
// ---------------------------------------------------------

#include <print>

void menu_principal();

int main()
{
    std::println("{} Jogo de Matemática: adivinhe um número de 1 a 10.{}", '\n', '\n');

    std::println(" Versão 3 - Criado por Daniel Vinicius.{}", '\n');

    menu_principal();

    std::println("{} Fim do jogo! Obrigado por jogar!", '\n');

    return 0;
}
