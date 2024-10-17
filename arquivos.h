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
int leArquivo(char *nomeArquivo, char buffer[linhas][tam])
{
    int qtd = 0;
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    int i =0;
    while( fgets(buffer[i], sizeof(buffer[i]), arquivo) != NULL ) 
    {
        int j = 0;
        
        // Remover '\n' ou '\r' manualmente, se estiver no final da linha
        while (buffer[i][j] != '\0') {
            if (buffer[i][j] == '\n' || buffer[i][j] == '\r') {
                buffer[i][j] = '\0';  // Substitui '\n' ou '\r' por fim de string
                break;
            }
            j++;
        }

        if (buffer[i][0] >= 'A' && buffer[i][0] <= 'z') {
            i++;  // Apenas incrementa se houver uma linha válida
            qtd++;
        }
    }
    //printf("qtd na leitura vale %d", qtd);
    qtd = qtd/2;
    //printf("qtd apos divisao vale %d", qtd);
    fclose(arquivo);
    return qtd;
}


#endif