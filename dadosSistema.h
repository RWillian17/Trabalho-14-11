#ifndef DADOS_SIST
#define DADOS_SIST
#endif

#include <stdio.h>
#include <stdbool.h>
//#include "arquivos.h"

bool testaTamanho (char teste[], int tamanho)
{
    for ( int i = 0; i < tamanho; i++)
    {
        if ( teste[i] == '\0')
        {
            return true;
        }
    }
    return false;
}

void copiaDados (char destino[], char origem[], int inicio, int fim)
{
    for (int i = inicio; i <= fim; i++)
    {
        destino[i] = origem[i-inicio];
    }
}

void solicitaDados (char destino[], int inicio, int fim, char tipoDado[])
{
    char temp[fim-inicio];
    do{
        printf("\nInsira o %s com no max %d caracteres ",tipoDado, fim-inicio-1);
        scanf("%[^\n]", temp);
        fflush(stdin);
    }while (!testaTamanho(temp, fim-inicio));

    copiaDados(destino, temp, inicio, fim);
}

int comparaIgual(char validacao[], char validar[], int tamanho)
{
    for ( int i = 0; i < tamanho ; i++)
    {
        if ( validacao[i] == '\0')
            break;
        if ( !(validar[i] == validacao[i]) )
            return 0;
    }
    return 1;

}

void limpaVetor(char vetor[], int tamanho)
{
    for ( int i = 0 ; i < tamanho ; i++)
        vetor[i] = ' ';
}

void solicitaCurso (char destino[], int inicio)
{
    char teste[16];
    do{
        printf("\nQual o tipo de curso você faz?");
        scanf("%s",teste);
        fflush(stdin);
        if ( comparaIgual ( "Tecnico", teste, 8) || comparaIgual ( "tecnico", teste, 8))
        {
            destino[inicio] = 'T';
            return;
        }
        else if ( comparaIgual ( "qualificacao", teste, 8) || comparaIgual ( "Qualificacao", teste, 8 ) )
        {
            destino[inicio] = 'Q';
            return;
        }
    }while(1);
    
}

void mostraDados (char leitura[], int inicio, int fim)
{
    for( int i = inicio; i < fim ; i++ )
    {
        if ( leitura[i] == '\0')
            break;

        printf("%c",leitura[i]);
    }
}
void mostraPessoa (char linha1[], char linha2[])
{
    printf("\nA pessoa requisitada se chama: ");
    mostraDados(linha1,0, 59);
    printf("\nCom o telefone ");
    mostraDados(linha1,60,79);
    printf("\nSendo o curso ");
    if ( linha2[0] == 'T')
        printf("Técnico ");
    else if ( linha2[0] == 'Q')
        printf("Qualificação ");
    mostraDados(linha2, 2, 30);
    printf("\nMora no endereco ");
    mostraDados(linha2, 31, 84);
    printf("no numero ");
    mostraDados(linha2, 85,89);
}

void adicionaPessoa(char destinoLinha1[], char destinoLinha2[])
{
    solicitaDados(destinoLinha1, 0, 59, "Nome Completo");
    solicitaDados(destinoLinha1, 60, 79, "Telefone");
    solicitaCurso(destinoLinha2, 0);
    solicitaDados(destinoLinha2, 1, 30, "Curso");
    solicitaDados(destinoLinha2, 31, 84, "Endereco");
    solicitaDados(destinoLinha2, 85, 89, "Numero");
    
}
