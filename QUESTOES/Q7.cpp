/*
__Q7__ -> Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por '*'.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

using namespace std;

//VARIAVEIS GLOBAIS
FILE *pFileOrigem;
FILE *pFileCopia;

bool criaCopia(char origem[60]){
    //Variaveis
    char c = ' ';
    char destino[60];
     

    //Cria ponteiros de origem
    pFileOrigem = fopen(origem, "r");

    //cria copia do arquivo de origem
    origem[strlen(origem)-4] = '\0';
    strcpy(destino, origem);
    strcat(destino, "-copia.txt");

    //Cria ponteiro de destino
    pFileCopia = fopen(destino, "w");

    //testa abertura de arquivo
    if (pFileCopia == NULL || pFileOrigem == NULL){
        cout<<"Erro ao abrir o arquivo";
        return false;
    }
    while (true)
    {
        //Pega os caracteres do documento .txt
        c = getc(pFileOrigem);
        //Condição de parada
        if (c==EOF){ break; }
        

        if (tolower(c) == 'a' ||
            tolower(c) == 'e' ||
            tolower(c) == 'i' ||
            tolower(c) == 'o' ||
            tolower(c) == 'u'   )
        {
            fputc('*', pFileCopia);
        }else{
            fputc(c, pFileCopia);
        }
    }
    
fclose(pFileCopia);
fclose(pFileOrigem);
return true;
}

int main(){
    //VARIAVEIS
    char arq[60];

    //MENU
    cout<<"-----Eliminadora de vogais-----"<<endl;
    cout<<"Digite o novo do arquivo: ";
    cin>>arq;
    
    //Cria o arquivo de cópia
    /*strcpy(copiaArq, arq);
    strcat(copiaArq, "-copia.txt");
    strcat(arq, ".txt");*/
    criaCopia(strcat(arq, ".txt"));



cout<<endl;
system("pause");
return 0;
}