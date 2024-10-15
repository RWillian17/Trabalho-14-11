#include <stdio.h>
#include <stdbool.h>
#include "dadosSistema.h"
#include "arquivos.h"

int main ()
{
    //long cpf;
    //int verificador;
    int qtd = 0;
    
    char dados[linhas][tam];
    
    for ( int i = 0 ; i < linhas; i++)
        limpaVetor(dados[i], tam);

    mostraPessoa(dados[0],dados[1]);
    adicionaPessoa(dados[0],dados[1]);
    qtd++;
    //solicitaDados(dados[0], 5, 15);

    printf("\nFoi salvo: \n");
    mostraPessoa(dados[0],dados[1]);

    escreveArquivo("teste.txt", dados[0]);
    escreveArquivo("teste.txt", dados[1]);
}