#ifndef ARQUIVOS
#define ARQUIVOS


#include <stdio.h>


#define tam 90
#define linhas 40 //cada usuario possui duas linhas

// Função para escrever dados em um arquivo de texto (sobrescreve o arquivo)
void escreveArquivo(char *nomeArquivo, char *dados)
{
    FILE *arquivo = fopen(nomeArquivo, "ab");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    //fprintf(arquivo, "%s\n", dados);
    fwrite(dados, sizeof(char), tam, arquivo);
    fprintf(arquivo,"\n");
    fclose(arquivo);
}

// Função para ler dados de um arquivo de texto
int leArquivo(char *nomeArquivo, char buffer[linhas][tam], int tamanhoMaximo)
{
    int qtd = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }
    int i =0;
    while( !feof( arquivo ) )
    {
        fgets(buffer[i] , tamanhoMaximo-1, arquivo);
        i++;
        qtd++;
    }
    printf("qtd na leitura vale %d", qtd);
    qtd = qtd/2;
    printf("qtd apos divisao vale %d", qtd);
    fclose(arquivo);
    return qtd;
}

// Função para adicionar uma nova linha ao arquivo (sem sobrescrever)
/*void adicionaLinhaArquivo(char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    
    fclose(arquivo);
}

*/


#endif