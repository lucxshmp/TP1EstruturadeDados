#include "dadosEntrada.h"
#include <iostream>
#include <utility> 

using namespace std;

// constructor
dadosEntrada::dadosEntrada(string name,
                        string diaUm, string mesUm, string anoUm,
                        string diaDois, string mesDois, string anoDois,
                        string diaTres, string mesTres, string anoTres) {

    nome = name;
    tamNome = name.length();

    dataUm[0] = stoi(diaUm);
    dataUm[1] = stoi(mesUm);
    dataUm[2] = stoi(anoUm);

    dataDois[0] = stoi(diaDois);
    dataDois[1] = stoi(mesDois);
    dataDois[2] = stoi(anoDois);

    dataTres[0] = stoi(diaTres);
    dataTres[1] = stoi(mesTres);
    dataTres[2] = stoi(anoTres);

    prox = nullptr;
}

// exibir lista
void dadosEntrada::exibirDados(dadosEntrada* node){
    while (node != nullptr) {
        cout << "nome: " << node->nome << endl;

        cout << "data um: "
            << node->dataUm[0] << "/" << node->dataUm[1] << "/" << node->dataUm[2] << endl;

        cout << "data dois: "
            << node->dataDois[0] << "/" << node->dataDois[1] << "/" << node->dataDois[2] << endl;

        cout << "data tres: "
            << node->dataTres[0] << "/" << node->dataTres[1] << "/" << node->dataTres[2] << endl;

        node = node->prox;
    }
}

// trocar dados entre nós
void dadosEntrada::trocarDados(dadosEntrada* node1, dadosEntrada* node2){
    swap(node1->nome, node2->nome);
    swap(node1->tamNome, node2->tamNome);

    for (int i = 0; i < 3; i++){
        swap(node1->dataUm[i], node2->dataUm[i]);
        swap(node1->dataDois[i], node2->dataDois[i]);
        swap(node1->dataTres[i], node2->dataTres[i]);
    }
}

// ordenar lista por ordem alfabética
void dadosEntrada::ordenarAlfabeticamente(dadosEntrada* head){
    if (head == nullptr) return;

    bool trocou;

    do {
        trocou = false;
        dadosEntrada* atual = head;

        while (atual->prox != nullptr){
            if (atual->nome > atual->prox->nome){
                trocarDados(atual, atual->prox);
                trocou = true;
            }
            atual = atual->prox;
        }

    } while (trocou);
}

// corrigir ano pois na entrada o ano está no formato YY, assim, na minha regra, caso seja menor que 30, o ano é do 
// século XXI, caso contrário, eu suponho que seja do século XX. 
int dadosEntrada::corrigirAno(int ano){
    if (ano < 30) return 2000 + ano;
    else return 1900 + ano;
}

// booleano pra comparar datas e retornar se a primeira é menor que a seggunda
bool dadosEntrada::dataMenor(int d1[], int d2[]){

    int a1 = corrigirAno(d1[2]);
    int a2 = corrigirAno(d2[2]);

    if (a1 != a2) return a1 < a2;
    if (d1[1] != d2[1]) return d1[1] < d2[1];
    return d1[0] < d2[0];
}

//trocar datas no vetor da struct para ordená-las em ordem crescente 
void dadosEntrada::trocaData(int a[], int b[]){
    for (int i = 0; i < 3; i++){
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

// função que ordena as datas dentro do nó
void dadosEntrada::ordenarData(dadosEntrada* d){

    if(dataMenor(d->dataDois, d->dataUm))
        trocaData(d->dataUm, d->dataDois);

    if (dataMenor(d->dataTres, d->dataUm))
        trocaData(d->dataUm, d->dataTres);

    if (dataMenor(d->dataTres, d->dataDois))
        trocaData(d->dataDois, d->dataTres);
}