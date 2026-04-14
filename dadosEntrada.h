#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H
#include <string> 

struct dadosEntrada {
    std::string nome;
    int tamNome;
    int dataUm[3];
    int dataDois[3];
    int dataTres[3];

    dadosEntrada* prox;

    // construtor
    dadosEntrada(std::string name,
                std::string diaUm, std::string mesUm, std::string anoUm,
                std::string diaDois, std::string mesDois, std::string anoDois,
                std::string diaTres, std::string mesTres, std::string anoTres);

    void exibirDados(dadosEntrada* node);

    // utilitárias
    bool dataMenor(int d1[], int d2[]);
    void trocaData(int a[], int b[]);
    int corrigirAno(int ano);

    // lista
    void trocarDados(dadosEntrada* node1, dadosEntrada* node2);
    void ordenarAlfabeticamente(dadosEntrada* head);
    void ordenarData(dadosEntrada* d);
};

#endif
