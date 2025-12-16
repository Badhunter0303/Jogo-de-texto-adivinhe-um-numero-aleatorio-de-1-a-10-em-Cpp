
#include <vector>

#include <string>

#include <iostream>

#include <iomanip>

void iniciar_partida();

void menu_principal()
{
    std::vector<std::string> opcoes_do_menu_principal;

    opcoes_do_menu_principal.push_back("Iniciar partida");
    opcoes_do_menu_principal.push_back("Sair do jogo");

    constexpr unsigned comprimento_da_coluna {25};

    while(true) // Loop do menu principal
    {
        std::cout << "\n\n" << std::right << std::setw(30) << "Menu Principal" << "\n\n";

        for(unsigned x {0}; x < opcoes_do_menu_principal.size(); ++x) // Printar opcoes do menu principal
        {
            std::string opcao_do_menu = std::format(" {}. {}", x + 1, opcoes_do_menu_principal[x]); // std::format só no C++20 e GCC 14 aparentemente

            std::cout << std::left << std::setw(comprimento_da_coluna) << opcao_do_menu;

            if((x + 1) >= 3 && (x + 1) % 3 == 0)
            std::cout << '\n';
        }

        std::cout << "\n\n" << " Escolha um item do menu principal: ";

        int escolha_do_usuario {0};

        while(true)
        {
            escolher_opcao_do_menu_principal:

            std::cin >> escolha_do_usuario;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Opção do menu inválida, por favor, escolha um item do menu principal:";
                continue;
            }

            break;
        }

        switch(escolha_do_usuario)
        {
            case 1:
            {
                iniciar_partida();
                break;
            }
            case 2:
            {
                return;
            }
            default:
            {
                std::cout << "\n\n" << " Opção do menu inválida, por favor, escolha um item do menu principal:";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                goto escolher_opcao_do_menu_principal;
            }
        }
    }
}
