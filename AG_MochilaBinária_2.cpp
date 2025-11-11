//Algoritmo Guloso Baseado Apenas no Valor (Maior Valor Primeiro)

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

int mochila_guloso(map<float, tuple<float, float>, greater<float>> r, int W){

    //Inicialização da variável que irá armazenar os valores que maximizam a função.
    int itens;
    itens = 0;

    //Incrementa os valores associados a cada item, na variável itens, desde de que o peso total da mochila seja maior ou igual que zero.
    //O peso da mochila é decrementado em relação aos pesos dos itens adicionados na variável itens.
    for(const pair<float, tuple<float, float>>& r_pair : r){
        if (get<0>(r_pair.second) <= W){
            itens += r_pair.first;
            W -= get<0>(r_pair.second);
        }
    }

    return itens;
}

int main(){

    //Inicialização do meu map e variáveis.
    map<float, tuple<float, float>, greater<float>> razao;
    float peso, valor;
    int peso_mochila, solucao;

    //Inicializção do peso associado a minha mochila.
    peso_mochila = 6;

    //Adição dos itens no map é feito passando como chave o valor do item e, como seus respectivos valores, peso e a razão valor-peso do item.
    //O uso do map permite a ordenação dos itens em relação as suas chaves. Por isso, esse map é ordenado em ordem decrescente em relação ao valor do item. 
    for(int i = 0; i < 3; i++){
        cin >> peso;
        cin >> valor;
        razao[valor] = make_tuple(peso, valor/peso);
        cout << endl;
    }

    //Chamada da solução gulosa.
    solucao = mochila_guloso(razao, peso_mochila);

    //Mostragem do meu resultado.
    cout << solucao << endl;

    return 0;
}