#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int escalona_guloso(list<int> t, int m){

    int carga_max;

    list<int> maquinas;

    //Inicializa todas as máquinas m como vazias.
    for(int i = 0; i < m; i++){
        maquinas.push_back(0);
    }

    //Configurações dos iteradores da lista maquinas.
    auto it_m1 = maquinas.begin();
    auto it_m2 = maquinas.begin();
    advance(it_m1, 0);
    advance(it_m2, 1);

    for(int tempo_exe : t){
 
        //Aloca o tempo de carga na máquina com menor tempo de carga.
        if (*it_m1 < *it_m2 or *it_m1 == *it_m2){
            *it_m1 += tempo_exe;
        } else if (*it_m2 < *it_m1){
            *it_m2 += tempo_exe;
        }

    }

    //Encontra a máquina que tem a menor soma de tempos das tarefas já alocadas (menor carga). E a retorna para a main.
    if (*it_m1 > *it_m2 or *it_m1 == *it_m2){
        carga_max = *it_m1;
    } else if (*it_m2 > *it_m1){
        carga_max = *it_m2;
    }

    return carga_max;

}

int main(){

    int t1, t2, t3, quant_maquinas, max;

    t1 = 1;
    t2 = 1;
    t3 = 2;

    quant_maquinas = 2;

    list<int> t_tarefa;
    t_tarefa.push_back(t1);
    t_tarefa.push_back(t2);
    t_tarefa.push_back(t3);

    //Ordena os valores da lista em ordem decrescente. Faz-se isso porque o funcionamento do algoritmo guloso é modificado variante a ordenação dos valores na lista. Logo, dependendo do caso e da composição dos valores na lista, é mais interessante fazer essa ordenação.
    //t_tarefa.sort(greater<int>());

    max = escalona_guloso(t_tarefa, quant_maquinas);
    cout << max;

    return 0;
}