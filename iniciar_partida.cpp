
#include <iostream>

#include <iomanip>

#include <random>

#include "Computador.hpp"

struct Mestre_do_jogo
{
    unsigned numero_cardinal_da_partida {1};

    unsigned pontuacao_do_jogador {0};

    unsigned pontuacao_do_computador {0};
};

void iniciar_partida()
{
    Mestre_do_jogo mestre;

    Computador computador;

    while(true) // Começo de uma partida
    {
        std::cout << "\n\n\n" << std::right << std::setw(30) << std::format("Partida {}{}", mestre.numero_cardinal_da_partida, "\n\n\n");

        computador.escolher_numero_aleatorio();

        std::cout << std::format(" Computador: Eu já escolhi um número de 1 a 10! Agora é sua vez de adivinhá-lo! {}", "\n\n");

        for(unsigned x {0}; x < 3; ++x) // 3 propriedades do número
        {
            std::cout << std::format("{} Computador: Qual propriedade abaixo do número você gostaria de saber? ({}ª Propriedade): {}", '\n', x + 1,"\n\n");

            computador.expor_uma_propriedade_do_numero();
        }

        std::cout << "\nComputador: Acabaram-se as dicas! Qual foi o número que eu escolhi? ";

        unsigned escolha_do_usuario {0};

        while(true)
        {
            std::cin >> escolha_do_usuario;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Número inválido, por favor, escolha um número válido: ";
                continue;
            }

            if(escolha_do_usuario < 1 || escolha_do_usuario > 10)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Número inválido, por favor, escolha um número válido: ";
                continue;
            }
            else break;
        }

        if(escolha_do_usuario == computador.buscar_numero_aleatorio())
        {
            std::cout << std::format("{} Computador: Você acertou! Eu de fato pensei no número {} !", "\n\n", escolha_do_usuario);
            ++mestre.pontuacao_do_jogador;
        }
        else
        {
            std::cout << std::format("{} Computador: Você errou! Eu pensei no número {} !", "\n\n", computador.buscar_numero_aleatorio());
            ++mestre.pontuacao_do_computador;
        }

        std::cout << std::format("{} Jogador {} X {} Computador", "\n\n", mestre.pontuacao_do_jogador, mestre.pontuacao_do_computador);

        std::cout << std::format("{} Deseja jogar novamente? (s/n) ", "\n\n");

        std::string escolha_jogar_novamente;

        while(true)
        {
            std::cin >> escolha_jogar_novamente;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Opção inválida, por favor, digite s ou n:";
                continue;
            }

            if(escolha_jogar_novamente == "s" || escolha_jogar_novamente == "n")
            break;
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Opção inválida, por favor, digite s ou n:";
            }
        }

        if(escolha_jogar_novamente == "s")
        {
            computador.escolher_numero_aleatorio();
            computador.resetar_validade_das_propriedades();
            ++mestre.numero_cardinal_da_partida;
            continue;
        }
        else return;
    }
}
