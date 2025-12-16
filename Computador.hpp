#ifndef COMPUTADOR_HPP_INCLUDED
#define COMPUTADOR_HPP_INCLUDED

#include "Numero_aleatorio.hpp"

struct Propriedade_do_numero_aleatorio
{
    unsigned ID {0};

    std::string descricao;
};

enum Validade_de_uma_propriedade
{
    propriedade_invalida = 0,
    propriedade_valida = 1
};

class Computador
{
public:

    void escolher_numero_aleatorio()
    {
        std::random_device rd;

        std::uniform_int_distribution<int> distribution_1(1, 10);

        numero_aleatorio_do_computador.definir_valor(distribution_1(rd));
    }

    void expor_uma_propriedade_do_numero()
    {
        unsigned numero_de_propriedades_buscadas {0};

        std::array<unsigned, 2> ID_das_propriedades_mostradas_ao_jogador;

        std::random_device rd;

        std::uniform_int_distribution<int> distribution_1(1, propriedades_do_numero_aleatorio.size());

        while(true)
        {
            if(numero_de_propriedades_buscadas == 2)
            break;

            auto index_da_propriedade {distribution_1(rd)};

            if(propriedades_do_numero_aleatorio[index_da_propriedade].second == propriedade_valida)
            {
                std::cout << std::format(" {}. {}{}", propriedades_do_numero_aleatorio[index_da_propriedade].first.ID, propriedades_do_numero_aleatorio[index_da_propriedade].first.descricao, "\n\n");

                propriedades_do_numero_aleatorio[index_da_propriedade].second = propriedade_invalida;

                if(propriedades_do_numero_aleatorio[index_da_propriedade].first.ID == 2) // Se o número é maior que cinco então ele não é menor que seis
                    propriedades_do_numero_aleatorio[6].second = propriedade_invalida;
                else if(propriedades_do_numero_aleatorio[index_da_propriedade].first.ID == 7)
                        propriedades_do_numero_aleatorio[1].second = propriedade_invalida;


                switch(numero_de_propriedades_buscadas)
                {
                case 0:
                    ID_das_propriedades_mostradas_ao_jogador[0] = propriedades_do_numero_aleatorio[index_da_propriedade].first.ID;
                    break;
                case 1:
                    ID_das_propriedades_mostradas_ao_jogador[1] = propriedades_do_numero_aleatorio[index_da_propriedade].first.ID;
                }

                ++numero_de_propriedades_buscadas;
            }
            else continue;
        }

        std::cout << std::format("{} Escolha o número da propriedade: ", '\n');

        unsigned escolha_do_usuario {0};

        while(true)
        {
            std::cin >> escolha_do_usuario;

            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Opção inválida, por favor, escolha uma propriedade: ";
                continue;
            }

            auto& IDs = ID_das_propriedades_mostradas_ao_jogador;

            if(std::find(IDs.begin(), IDs.end(), escolha_do_usuario) != IDs.end())
            break;
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\n" << " Opção inválida, por favor, escolha uma propriedade: ";
                continue;
            }
        }

        for(auto& ID : ID_das_propriedades_mostradas_ao_jogador) // tornar válida, propriedade que jogador não escolheu saber
        {
            if(escolha_do_usuario != ID)
                propriedades_do_numero_aleatorio[ID - 1].second = propriedade_valida;
        }

        switch(escolha_do_usuario)
        {
        case 1:
            if(numero_aleatorio_do_computador.buscar_es_par())
                std::cout << "\n Resposta: Sim, o número é par.\n\n";
            else std::cout << "\n Resposta: Não, o número não é par.\n\n";
            break;
        case 2:
            if(numero_aleatorio_do_computador.buscar_es_maior_que_cinco())
                std::cout << "\n Resposta: Sim, o número é maior que 5.\n\n";
            else std::cout << "\n Resposta: Não, o número não é maior que 5.\n\n";
            break;
        case 3:
            if(numero_aleatorio_do_computador.buscar_es_primo())
                std::cout << "\n Resposta: Sim, o número é primo.\n\n";
            else std::cout << "\n Resposta: Não, o número não é primo.\n\n";
            break;
        case 4:
            if(numero_aleatorio_do_computador.buscar_es_divisivel_por_tres())
                std::cout << "\n Resposta: Sim, o número é divisível por três.\n\n";
            else std::cout << "\n Resposta: Não, o número não é divisível por três.\n\n";
            break;
        case 5:
            if(numero_aleatorio_do_computador.buscar_es_divisivel_por_cinco())
                std::cout << "\n Resposta: Sim, o número é divisível por cinco.\n\n";
            else std::cout << "\n Resposta: Não, o número não é divisível por cinco.\n\n";
            break;
        case 6:
            if(numero_aleatorio_do_computador.buscar_es_quadrado_perfeito())
                std::cout << "\n Resposta: Sim, o número é quadrado perfeito.\n\n";
            else std::cout << "\n Resposta: Não, o número não é quadrado perfeito.\n\n";
            break;
        case 7:
            if(numero_aleatorio_do_computador.buscar_es_menor_que_seis())
                std::cout << "\n Resposta: Sim, o número é menor que seis.\n\n";
            else std::cout << "\n Resposta: Não, o número não é menor que seis.\n\n";
            break;
        }
    }

    void resetar_validade_das_propriedades()
    {
        for(auto& propriedade : propriedades_do_numero_aleatorio)
        {
            propriedade.second = propriedade_valida;
        }
    }

    unsigned buscar_numero_aleatorio() const {return numero_aleatorio_do_computador.buscar_valor();}

private:
    Numero_aleatorio numero_aleatorio_do_computador;

    std::vector<std::pair<Propriedade_do_numero_aleatorio, Validade_de_uma_propriedade>> propriedades_do_numero_aleatorio = {
        { {1, "Se o número é par."}, propriedade_valida},
        { {2, "Se o número é maior que cinco."}, propriedade_valida },
        { {3, "Se o número é primo."}, propriedade_valida},
        { {4, "Se o número é divisível por três."}, propriedade_valida },
        { {5, "Se o número é divisível por cinco."}, propriedade_valida },
        { {6, "Se o número é quadrado perfeito."}, propriedade_valida },
        { {7, "Se o número é menor que seis."}, propriedade_valida }
    };
};

#endif // COMPUTADOR_HPP_INCLUDED
