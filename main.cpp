#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

FILE *pont_arq;

bool criarNovoArquivo(char nomeArq[100]){
    char palavra[20];

    pont_arq = fopen(nomeArq, "W");
    if (pont_arq == NULL)
    {
        cout<<"Erro na abertura do arquivo";
        return false;
    }

    cout<< "Escreva uma palavra para testar gravacao de arquivo";
    
    
}

int main(){
    char nome[50];
    cout<<"Hello Word\n";
    fflush(stdin);
    cout<<"Digite uma frase";fgets(nome, 50, stdin);
    cout<<nome;

getchar();
return 0;
}