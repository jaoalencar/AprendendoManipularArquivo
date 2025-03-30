/*
__Q5__ -> Faça um programa que receba do usuário um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Variaveis globais
FILE *pFile;

bool ContaCaracter(char nome[], char c=' '){
    int contador = 0;
    char caracterArquivo;
    //Abre o arquivo para leitura
    pFile = fopen(nome, "r");
    while (caracterArquivo != EOF)
    {
        caracterArquivo = fgetc(pFile);
        (caracterArquivo == c)?contador++:contador;
    }
    cout << "O arquivo possui " << contador << " caracteres \"" << c << "\"";

fclose(pFile);    
}

int main(){
    char nomeArq[50];
    cout<<"Digite o nome do arquivo para ler: ";cin>>nomeArq;
    ContaCaracter(nomeArq, 'l');

getchar();
return 0;
}