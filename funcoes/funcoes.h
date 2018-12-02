#include <stdio.h>
#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void tituloEidioma();

void novaTable();

int calc_tables();

char **showTables();

int strComparar(char str1[],char str2[]);

void criarDiretorios();

void menu();

int apagarTable();

void limparTela();

int apagarKeys(char tabela[]);

int verificarTabela(char tabela[]);

void addResistro();

void addInKey(char tab[],int key);

void gerarKeys_txt(char tab[]);

int removeKey(char tab[],int key);

int Verificakey(char tab[],int k);

void restart();

void exibir();

#endif // MATRIZ_H_INCLUDED
