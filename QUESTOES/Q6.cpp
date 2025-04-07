/*
Q6 -> Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//VARIAVEIS GLOBAIS
FILE *pFile;

int ContadorLetras(char nome[50], char letra){
    //Abre arquivo para leitura
    pFile = fopen(nome, "r");
    if(pFile==NULL){
        cout<<"Erro ao abrir arquivo (arquivo não existente)";
        return EXIT_FAILURE;
    }
    //Variaveis locais
    char c=' ';//pega os caracteres do arquivo
    int retorno=0;

    //Contador de letras
    while (c!=EOF)
    {
        c = fgetc(pFile);
        (c == letra) ? retorno++ : retorno;
    }
fclose(pFile);
return retorno;
}

int main(){
    //VARIAVEIS
    char arq[50];
    char letra = ' ';
    int nLetras=0;
    //MENU
    cout<<"---Contador de letras---"<<endl;
    cout<<"Digite o nome do arquivo: ";cin>>arq;
    cout<<"Digite a letra para contar: ";cin>>letra;
    nLetras = ContadorLetras(arq, letra);
    cout << "O arquivo possui " << nLetras << " letras " << letra;

cout<<endl;
system("pause");
return 0;
}