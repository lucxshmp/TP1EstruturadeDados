#include "dadosEntrada.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    std::ifstream file;
    file.open("entrada.txt");

    dadosEntrada* head = nullptr;
    dadosEntrada* tail = nullptr;
    string line;

    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo\n";
        return 1;
    }
    
    // separando os dados da linha e armazenando em uma struct
    while(std::getline(file, line)){

        //nome
        string name = line.substr(0, line.length() - 18);

        //data um
        string diaUm = line.substr(line.length() -18, 2);
        string mesUm = line.substr(line.length() - 16, 2);
        string anoUm =  line.substr(line.length() - 14, 2);

        //data dois
        string diaDois = line.substr(line.length() - 12, 2);          
        string mesDois = line.substr(line.length() - 10, 2);
        string anoDois = line.substr(line.length() - 8, 2);

        //data tres
        string diaTres = line.substr(line.length() - 6, 2); 
        string mesTres = line.substr(line.length() - 4, 2);
        string anoTres = line.substr(line.length() - 2, 2);

        dadosEntrada* novoDado = new dadosEntrada(name, diaUm, mesUm, anoUm, diaDois, mesDois, anoDois, diaTres, mesTres, anoTres);
        if (head == nullptr){
            head = tail = novoDado;
        } else {
            tail->prox = novoDado;
            tail = novoDado;
        }
    }


    //debug pra ver se esta armazenando tudo certinho
    if (head != nullptr) {
    head->ordenarAlfabeticamente(head);

    dadosEntrada * atual = head;
    while (atual != nullptr){
        atual->ordenarData(atual);
        atual = atual->prox;
    }
    head->exibirDados(head); // vendo se organizou alfabticamente 
    } 
    
    // liberar memória
    dadosEntrada* atual = head;
    while (atual != nullptr) {
        dadosEntrada* temp = atual;
        atual = atual->prox;
        delete temp;
    }

    return 0;
}