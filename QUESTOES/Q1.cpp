/*
Q1-> Escreva um programa que:
   1. Crie/abra um arquivo texto de nome "arq.txt"
   2. Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere '0'
   3. Feche o arquivo.
   4. Agora, abra e leia o arquivo, caracter por caracter, e escreva na tela todos os caracteres armazenados.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//VARIAVEIS GLOBAIS
FILE *arquivo;
char nome[50];

//FUNÇÕES
bool AbrirArquivo(char nome[50]){
    //VARIAVEIS LOCAIS
    arquivo = fopen(nome, "w");
    char c;

    //Teste de erro do arquivo
    if (arquivo == NULL)
    {
        cout<<"Arquivo nao existe";
        return false;
    }
    //Coleta o caracter que irá inserir no arquivo
    while (c != '0')
    {
        cout<<"Digite um caractere para colocar no arquivo, caso queira parar digite 0"<<endl;
        cout<<"Caracter: ";cin>>c;
        if(c != '0'){
            fputc(c, arquivo);
        }
    }  
fclose(arquivo);
}

//FUNÇÃO PARA LER ARQUIVO
bool LerArquivo(char nome[50]){
    //Variaveis
    char c;
    arquivo = fopen(nome, "r");//Abre arquivo para leitura
     //Teste de erro do arquivo
     if (arquivo == NULL)
     {
         cout<<"Arquivo nao existe";
         return false;
     }
     //Pega os caracteres do documento e exibe eles
     do
     {
        c = getc(arquivo);
        cout<<c;
     } while (c!=EOF);

fclose(arquivo);
}


int main(){
    cout<<"Digite o nome do arquivo: ";cin>>nome;
    AbrirArquivo(nome);
    LerArquivo(nome);

cout<<"\n--------FIM DO CODGIO--------\n";
getchar();
return 0;
}