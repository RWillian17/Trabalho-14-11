#include <stdio.h>
#include <stdbool.h>
#include "dadosSistema.h"
#include "arquivos.h"


int main ()
{

    int qtd = 0, op, qtdInseridos=0;
    
    char dados[linhas][tam];
    
    for ( int i = 0 ; i < linhas; i++)
        limpaVetor(dados[i], tam);

    qtd = leArquivo("teste.txt",dados); 
    
    printf("\nForam encontrados %d cadastros",qtd);
    do
    {
        printf("\nDigite qual opcao deseja: \n");
        
        printf("\n1 - Adicionar Pessoa");
        printf("\n2 - Mostrar Todos Dados");
        
        printf("\n0 - Fechar e atualizar o banco de dados");
        scanf("%d",&op);
        getchar();
        switch (op)
        {
            case 1:
                adicionaPessoa(dados[2*(qtd+qtdInseridos)], dados[2*(qtd+qtdInseridos)+1]);
                qtdInseridos++;
                break;
            case 2:
                for ( int i = 0; i < 2*(qtd+qtdInseridos)-1 ; i=i+2)
                    mostraPessoa(dados[i], dados[i+1]);
                break;
            case 0:
                printf("\nSaindo");
                break;
            default:
                printf("\nOpcao Invalida");
                break;
        }
    } while (op != 0);
    /*
    for ( int i = 0; i < 2*(qtd+qtdInseridos) ; i++)
        mostraVetor(dados[i]);
    }*/
    for (int i = (qtd*2) ; i < (2*(qtd+qtdInseridos))  ; i++)
    {
        escreveArquivo("teste.txt", dados[i]);
    }
    
}

