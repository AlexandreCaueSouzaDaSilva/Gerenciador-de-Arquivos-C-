#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Declaração das funções (prototipação)
int banco_arquivos(char arquivos[][50], int *quantidade);
int criar_arquivo_novo(char arquivos[][50], int *quantidade);
int deletar_arquivo(char arquivos[][50], int *quantidade);
int fechar_programa();

// Definição do tamanho máximo do banco
#define MAX_ARQUIVOS 100

// Função principal
int main() {
    char arquivos[MAX_ARQUIVOS][50]; // Array para armazenar os nomes dos arquivos
    int quantidade = 0; // Contador de arquivos no banco

    // Criar arquivo
    printf("Digite um nome para o arquivo: ");
    scanf("%s", arquivos[quantidade]);
    quantidade++;
    printf("Arquivo Criado com sucesso!\n");

    // Limpa o buffer de entrada, nem sabia slk
    while (getchar() != '\n');

    // Chama o banco
    banco_arquivos(arquivos, &quantidade);

    return 0;
}

// banco
int banco_arquivos(char arquivos[][50], int *quantidade) {
    char choice[3];
    char newchoice[3];
    int continuar = 1; // Um loop para evitar erros, slk

    while (continuar) {
        // Ver banco
        printf("Deseja Ver banco de arquivos? (s/n): ");
        printf("Digite 's' para sim ou 'n' para não: ");
        scanf("%s", choice);

        // sim, aadicionar arquivo e deletar arquivo
        if (strcmp(choice, "s") == 0 || strcmp(choice, "S") == 0) {
            char delchoice[3]; // <-- MOVIDO PRA CÁ
        
            printf("Banco de arquivos:\n");
            for (int i = 0; i < *quantidade; i++) {
                printf("%d. %s\n", i + 1, arquivos[i]);
            }
        
            printf("Deseja Criar outro arquivo? (s/n): ");
            scanf("%s", newchoice);
        
            printf("Deseja deletar um arquivo? (s/n): ");
            scanf("%s", delchoice);
            if (strcmp(delchoice, "s") == 0 || strcmp(delchoice, "S") == 0) {
                deletar_arquivo(arquivos, quantidade);
            }
        


            // sim, criar novo arquivo
            if (strcmp(newchoice, "s") == 0 || strcmp(newchoice, "S") == 0) {
                printf("Criando novo arquivo...\n");
                criar_arquivo_novo(arquivos, quantidade);
            } else if (strcmp(newchoice, "n") == 0 || strcmp(newchoice, "N") == 0) {
                printf("Não criou Novo Arquivo.\n");
            } else {
                printf("Erro no pedido para Criar Novo Arquivo.\n");
            }
        } else if (strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0) {
            printf("Banco de arquivos não exibido.\n");
            printf("Deseja Criar outro arquivo? (s/n): ");
            scanf("%s", newchoice);

            if (strcmp(newchoice, "s") == 0 || strcmp(newchoice, "S") == 0) {
                printf("Criando novo arquivo...\n");
                criar_arquivo_novo(arquivos, quantidade);
            } else if (strcmp(newchoice, "n") == 0 || strcmp(newchoice, "N") == 0) {
                printf("Não criou Novo Arquivo.\n");
                continuar = 0; // Sai do loop
                fechar_programa();
            } else {
                printf("Erro no pedido para Criar Novo Arquivo.\n");
            }
        } else {
            printf("Erro no pedido para ver o banco de Dados!.\n");
        }
    }

    return 0;
}

// Função para criar um novo arquivo
int criar_arquivo_novo(char arquivos[][50], int *quantidade) {
    if (*quantidade >= MAX_ARQUIVOS) {
        printf("Erro: Limite máximo de arquivos atingido.\n");
        return 0;
    }

    // Captura o nome do novo arquivo
    printf("Digite o nome do novo arquivo: ");
    scanf("%s", arquivos[*quantidade]);
    (*quantidade)++;
    printf("Novo arquivo '%s' criado com sucesso!\n", arquivos[*quantidade - 1]);

    return 0;
}

int deletar_arquivo(char arquivos[][50], int *quantidade) {
    int index;

    if (*quantidade == 0) {
        printf("Não há arquivos para deletar.\n");
        return 0;
    }

    // Mostrar os arquivos
    printf("Arquivos disponíveis para deletar:\n");
    for (int i = 0; i < *quantidade; i++) {
        printf("%d. %s\n", i + 1, arquivos[i]);
    }

    printf("Digite o número do arquivo que deseja deletar: ");
    scanf("%d", &index);

    if (index < 1 || index > *quantidade) {
        printf("Índice inválido.\n");
        return 0;
    }

    // Remover o arquivo e ajustar o vetor
    for (int i = index - 1; i < *quantidade - 1; i++) {
        strcpy(arquivos[i], arquivos[i + 1]);
    }
    (*quantidade)--;

    printf("Arquivo deletado com sucesso!\n");

    return 0;
}


// Função para fechar o programa
int fechar_programa() {
    char choice[3];

    // Confirmação para fechar o programa
    printf("Deseja realmente fechar o programa? (s/n): ");
    scanf("%s", choice);

    if (strcmp(choice, "s") == 0 || strcmp(choice, "S") == 0) {
        printf("Fechando o programa...\n");
        exit(0);
    } else if (strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0) {
        printf("Voltando ao menu principal...\n");
        return main(); // Retorna ao menu principal
    } else {
        printf("Opção inválida. Tente novamente.\n");
        return fechar_programa();
    }
}