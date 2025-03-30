/*
__Q4__ -> Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais e quantas são consoantes.
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
    int vogais = 0, consoantes = 0;

    //Teste do arquivo
    if (pFile == NULL){
        cout<<"Erro ao abrir arquivo";
        return false;
    }
    //Coloca o "cursor no inicio do .txt"
    rewind(pFile);
    //Verifica se o documento está vazio se não estive ai sim conta as vogais/consoantes
    if(getc(pFile)==EOF){
        cout<<"Documento esta vazio!!"<<endl;
    }else{
        //Conta a quantidade de letras consoantes e vogais em um arquivo
         while(c != EOF){
            c = tolower(getc(pFile));//Deixa todas as letras minusculas
            if (c == 'a' ||
                c == 'e' ||
                c == 'i' ||
                c == 'o' ||
                c == 'u'   )
            {
                vogais++;
            }else if(c != ' ' &&
                    c != '.' &&
                    c != ',' &&
                    c != ';' &&
                    c != '!' &&
                    c != '?' &&
                    c != ':'   )
            {
                consoantes++;
            }   
        }
    }
    
    //Mostra a quantidade de consoantes e vogais
    cout<<"Numero de consoantes: "<<consoantes<<endl;
    cout<<"Numero de vogais: "<<vogais<<endl;
    
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