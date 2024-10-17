#include <stdio.h>
#include <stdbool.h>
#include "dadosSistema.h"
#include "arquivos.h"


int main ()
{
    //long cpf;
    //int verificador;
    int qtd = 0, op, qtdInseridos=0;
    
    char dados[linhas][tam];
    
    for ( int i = 0 ; i < linhas; i++)
        limpaVetor(dados[i], tam);

    qtd = leArquivo("teste.txt",dados); 

    //char teste[20] = "0123456789ABCDEFGHIJ";
    //char destino[30] = "AAAAAAAAAABBBBBBBBBBCCCCCDDDDD";
 /*   copiaDados(destino, teste, 9, 29);
    for ( int i =0; i < 20; i++)
        printf("\n(%d) = %c", i, teste[i]);
    for ( int i = 0; i < 30; i++)
        printf("\n(%d) = %c",i,destino[i]);

}*/
    
    printf("\nForam encontrados %d cadastros",qtd);
    do
    {
        printf("\nDigite qual opcao deseja: \n");
        
        printf("\n1 - Adicionar Pessoa");
        printf("\n2 - Mostrar Todos Dados");
        printf("\n3 - Remover Pessoa\n");
        scanf("%d",&op);
        fflush(stdin);
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
    
    for ( int i = 0; i < 2*(qtd+qtdInseridos) ; i++)
        mostraVetor(dados[i]);

    for (int i = (qtd*2) ; i < (2*(qtd+qtdInseridos))  ; i++)
    {
        escreveArquivo("teste.txt", dados[i]);
    }
}

