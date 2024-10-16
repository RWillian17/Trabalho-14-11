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

    //mostraPessoa(dados[0],dados[1]);
    adicionaPessoa(dados[0],dados[1]);
    //qtd++;
/*    adicionaPessoa(dados[2],dados[3]);
    qtd++;
    adicionaPessoa(dados[4],dados[5]);
    qtd++;
    adicionaPessoa(dados[6],dados[7]);
    qtd++;
    //solicitaDados(dados[0], 5, 15);

    for ( int i = 0; i < 2*qtd ; i++)
        
        */
    //printf("\nFoi salvo: \n");
    //mostraPessoa(dados[0],dados[1]);
    

    //leArquivo("teste.txt", dados,tam);
    
    //mostraPessoa(dados[0],dados[1]);
    //mostraPessoa(dados[2],dados[3]);
    //mostraPessoa(dados[4],dados[5]); */

    escreveArquivo("teste.txt", dados[0]);
    escreveArquivo("teste.txt", dados[1]);
}