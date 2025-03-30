/*
Q2 -> Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas linhas esse arquivo possui.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

FILE *pFile;

bool ContaLinha(char nome[50]){
    //Variaveis locais
    pFile = fopen(nome, "r");
    char c;
    int contador = 1;

    //Teste do arquivo
    if (pFile == NULL){
        cout<<"Erro ao abrir arquivo";
        return false;
    }
    //Coloca o "cursor no inicio do .txt"
    rewind(pFile);
    //Verifica se o documento está vazio se não estive ai sim conta as linhas
    if(getc(pFile)==EOF){
        contador--;
    }else{
        //Conta a quantidade de linhas em um arquivo
         while(c != EOF){
            c = getc(pFile);
            c=='\n'?contador++:contador;
        }
    }
    
    //Mostra aquantidade de linhas
    cout<<"Numero de linhas: "<<contador;
    
fclose(pFile);
}


int main(){
    char nomeArq[50];
    cout<<"Digite o nome do arquivo para ler: ";cin>>nomeArq;
    ContaLinha(nomeArq);

cout<<"\n-------Fim do codigo-------\n";
getchar();
return 0;
}