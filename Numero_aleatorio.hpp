l#ifndef NUMERO_ALEATORIO_HPP_INCLUDED
#define NUMERO_ALEATORIO_HPP_INCLUDED

bool es_primo(int numero)    // Eu peguei da internet, para saber se o número é primo
{
    if(numero < 2) return false;
    if(numero == 2) return true;
    if(numero % 2 == 0) return false;
    for(int i=3; (i*i)<=numero; i+=2){
        if(numero % i == 0 ) return false;
    }
    return true;
}

class Numero_aleatorio
{
public:

    void definir_valor(unsigned novo_valor)
    {
        valor = novo_valor;

        if(valor % 2 == 0)
            par = true;
        else par = false;

        if(valor > 5)
            maior_que_cinco = true;
        else maior_que_cinco = false;

        primo = es_primo(valor);

        if(valor % 3 == 0)
            divisivel_por_tres = true;
        else divisivel_por_tres = false;

        if(valor % 5 == 0)
            divisivel_por_cinco = true;
        else divisivel_por_cinco = false;

        std::array<int, 3> quadrados_perfeitos {1, 4, 9};
        if(std::find(quadrados_perfeitos.begin(), quadrados_perfeitos.end(), valor) != quadrados_perfeitos.end())
            quadrado_perfeito = true;
        else quadrado_perfeito = false;

        if(valor < 6)
            menor_que_seis = true;
        else menor_que_seis = false;
    }

    unsigned buscar_valor() const {return valor;}

    bool buscar_es_par() const {return par;}

    bool buscar_es_maior_que_cinco() const {return maior_que_cinco;}

    bool buscar_es_primo() const {return primo;}

    bool buscar_es_divisivel_por_tres() const {return divisivel_por_tres;}

    bool buscar_es_divisivel_por_cinco() const {return divisivel_por_cinco;}

    bool buscar_es_quadrado_perfeito() const {return quadrado_perfeito;}

    bool buscar_es_menor_que_seis() const {return menor_que_seis;}
private:

    unsigned valor {0};

    bool par {false};

    bool maior_que_cinco {false};

    bool primo {false};

    bool divisivel_por_tres {false};

    bool divisivel_por_cinco {false};

    bool quadrado_perfeito {false};

    bool menor_que_seis {false};
};

#endif // NUMERO_ALEATORIO_HPP_INCLUDED
