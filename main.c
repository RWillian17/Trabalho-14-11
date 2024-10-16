#include <stdio.h>
#include <stdbool.h>
#include "dadosSistema.h"
#include "arquivos.h"


int main ()
{
    //long cpf;
    //int verificador;
    int qtd = 0, op;
    
    char dados[linhas][tam];
    
    for ( int i = 0 ; i < linhas; i++)
        limpaVetor(dados[i], tam);

    qtd = leArquivo("teste.txt",dados,tam); 

    printf("\nForam encontrados %d cadastros",qtd);
    do
    {
        printf("Digite qual opcao deseja: \n");
        
        printf("\n1 - Adicionar Pessoa");
        printf("\n2 - Mostrar Todos Dados");
        printf("\n3 - Remover Pessoa");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                adicionaPessoa(dados[qtd], dados[qtd+1]);
                qtd++;
                break;
            case 2:
                for ( int i = 0; i < qtd*2 ; i++)
                    mostraPessoa(dados[i], dados[i+1]);
                break;
            case 3:
                printf("\nAinda não feito");
                break;
            case 0:
                printf("\nSaindo");
                break;
            default:
                printf("\nOpcao Invalida");
                break;
        }
    } while (op != 0);
    
    for (int i = 0 ; i < qtd*2 ; i++)
        escreveArquivo("teste.txt", dados[i]);
}