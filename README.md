# TP1EstruturadeDados
Trabalho prático da disciplina de Estruturas de Dados do curso de Engenharia de Sistemas.
Aluno: Lucas Henrique Martins Petronilho
Matrícula: 2023060600

Descrição

O programa realiza a leitura de um arquivo texto contendo múltiplas linhas no formato:

NOMEDDMMAADDMMAADDMMAA

Cada linha representa um registro composto por:

Nome (string)
Três datas no formato DDMMAA

Os dados são armazenados em uma lista encadeada, utilizando a struct dadosEntrada.

Funcionalidades
Leitura de dados a partir de arquivo
Armazenamento em lista encadeada
Ordenação alfabética dos registros (por nome)
Ordenação crescente das datas dentro de cada registro

Detalhes da Implementação
A estrutura dadosEntrada contém:

Nome do registro
Três datas armazenadas como vetores inteiros [dia, mês, ano]
Ponteiro para o próximo elemento da lista
A ordenação da lista é realizada utilizando o algoritmo Bubble Sort, com troca de dados entre os nós.

As datas são comparadas considerando:
Ano
Mês
Dia
Anos com dois dígitos são tratados para lidar com a virada de século.

Compilação e Execução

Compilação:
g++ main.cpp dadosEntrada.cpp -o programa

Execução:
./programa ou programa.exe (a depender o sistema operacional)

Compilador utilizado: 
g++ (MinGW.org GCC-6.3.0-1) 6.3.0
