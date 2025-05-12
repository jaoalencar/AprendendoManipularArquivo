/*
__Q9__ -> Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE *pFile1;
FILE *pFile2;
FILE *pFileJunto;

int main(){
    //Define variaveis
    char arq1[50];
    char arq2[50];
    char arqJunto[100] = "";
    char c=' ';
    //Coleta o nome dos arquivos
    cout << "Digite o nome do primeiro arquivo: ";cin>>arq1;
    cout << "Digite o nome do segundo arquivo: ";cin>>arq2;
    //Cria nome do arquivo copia
    strcat(arqJunto, arq1);
    strcat(arqJunto, arq2);
    
    //Isere o .txt em cada arquivo
    strcat(arq1, ".txt");
    strcat(arq2, ".txt");
    strcat(arqJunto, ".txt");

    //Abre os arquivos
    pFile1 = fopen(arq1, "r");
    pFile2 = fopen(arq2, "r");
    pFileJunto = fopen(arqJunto, "w");
    //Verifica se abriu corretamente
    if (pFile1 == NULL){
        cout << "Erro abrir o arquivo 1";
        return EXIT_FAILURE;
        }
    else if(pFile2 == NULL){
        cout << "Erro abrir o arquivo 2";
        return NULL;
    }
    else if(pFileJunto == NULL){
        cout << "Erro abrir o arquivo junto";
    }
    //MANIPULAÇÃO DOS ARQUIVOS
    //Inicia a escrever o primeiro documento
    fprintf(pFileJunto, "%s", "-------------------------- Primeiro arquivo --------------------------\n");//primeira linha do arquivo
    //começa a escrever o primeiro arquivo
    while (true)
    {   
        //Coleta o caractere do primeiro arquivo
        c = fgetc(pFile1);
        //Condição de parada
        if (c == EOF){ break; }
        //Insere no documento dos dois arquivos juntos
        fputc(c, pFileJunto);
    }

    //ESCREVE A SEPARAÇÃO ENTRE O ARQUIVO 1 E 2
    fprintf(pFileJunto,"%s", "\n---------------------- Segundo arquivo ----------------------\n");

    //começa a escrever o segundo arquivo
    while (true)
    {
        //Coleta o caractere do segundo arquivo
        c = fgetc(pFile2);
        //Condição de parada
        if (c == EOF){break;}
        //Insere no documento dos dois arquivos juntos
        fputc(c, pFileJunto);
    }

    
    
fclose(pFile1);
fclose(pFile2);
fclose(pFileJunto);
cout << endl;
system("pause");
return 0;
}