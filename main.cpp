#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

FILE *pont_arq;

//Funcao para criar novo arquivo
bool criarNovoArquivo(char nomeArq[100]){
    char palavra[20];//Variavel que será colocada no arquivo, tamanho de 50 caracteres

    //Abrindo arquivo como modo escrita "w"
    pont_arq = fopen(nomeArq, "w");

    //Caso dê erro, mostra mensagem e retorna false
    if (pont_arq == NULL)
    {
        cout<<"Erro na abertura do arquivo";
        return false;
    }

    //coleta a palavra que o usuário digitar
    cout<< "Escreva uma palavra para testar gravacao de arquivo: ";cin>>palavra;

    //Usando fprint para armazenar a string no arquivo
    fprintf(pont_arq, "%s", palavra);

    //usando fclose para fechar o arquivo
    fclose(pont_arq);

    cout<<"Dados gravados com sucesso!";
    return true;
}

//Funcao para acrecentar palavras no arquivo
bool acrescentarArquivo(char nomeArquivo[500]){
    char palavra[50]; //Variavel utilizada para manipulação dos arquivos

    //Abre arquivo
    pont_arq = fopen(nomeArquivo, "a");

    //Retorna mensagem de erro
    if (pont_arq == NULL)
    {
        cout<<"Erro ao abrir o arquivo";
        return false;
    }

    //coleta palavra para ser gravada no arquivo
    cout<<"Digite a palavra para adicionar no arquivo: ";cin>>palavra;

    //grava palavra no arquivo
    fprintf(pont_arq, "%s", palavra);

    //fecha o arquivo
    fclose(pont_arq);

    cout<<"Dados gravados com sucesso!";
    return true;
}

//Funcao para leitura de arquivos
bool lendoDadosArquivo( char nomeArquivo[100]){
    char c; //Armazenará cada caractere do arquivo

    //Abrindo arquivo
    pont_arq = fopen(nomeArquivo, "r");

    //retorna mensagem de erro 
    if (pont_arq == NULL){
        cout<<"Erro ao abrir arquivo!";
        return false;
    }

    //Mostra o contudo do arquivo
    cout<<"CONTUDO DO ARQUIVO >> \n";
    do{
        //Faz a leitura do caracter no arquivo apontado por pont_arq
        c = getc(pont_arq);

        //Exibe o caracter lido na tela
        cout<<c;
    }while (c != EOF);
    
}

int main(){
    char nome[100];
    int op;
    do
    {
        system("cls");//limpa o cmd
        //mostra o menu
        cout<<"Qual opcaoo deseja realizar?"<<endl;
        cout<<"1 - Criar novo arquivo"<<endl;
        cout<<"2 - Acrescentar dados no final de um arquivo"<<endl;
        cout<<"3 - Exibir conteudo de um arquivo"<<endl;
        cout<<"0 - Encerrar"<<endl;
        cin>>op;
        if( op >= 1 && op<=3){
            cout << "informe o nome do arquivo: ", cin>>nome;    
        }

        switch (op)
            {
            case 1:
                criarNovoArquivo(nome);
                break;
            case 2:
                acrescentarArquivo(nome);
                break;
            case 3:
                lendoDadosArquivo(nome);
                break;
            case 0:
                system("pause");
                break;;
            default:
                cout<<"OPÇÃO INVALIDA!";
                system("pause");
            }
    } while (op != 0);
    return EXIT_SUCCESS;

getchar();
return 0;
}