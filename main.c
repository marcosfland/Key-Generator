#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char chave[11];
    int opcao;

    srand(time(NULL));

    do {
        printf("Menu:\n");
        printf("1. Gerar chave de acesso\n");
        printf("2. Validar chave de acesso\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    int random = rand() % 36;
                    if (random < 26) {
                        chave[i] = 'A' + random;
                    } else {
                        chave[i] = '0' + (random - 26);
                    }
                }
                chave[10] = '\0';
                printf("Chave gerada: %s\n", chave);
                break;
            case 2:
                printf("Digite a chave de acesso: ");
                scanf("%s", chave);
                if (strlen(chave) != 10) {
                    printf("Chave invalida!\n");
                } else {
                    int letras = 0, numeros = 0;
                    for (int i = 0; i < 10; i++) {
                        if (chave[i] >= 'A' && chave[i] <= 'Z') {
                            letras++;
                        } else if (chave[i] >= '0' && chave[i] <= '9') {
                            numeros++;
                        }
                    }
                    if (letras > 0 && numeros > 0) {
                        printf("Chave valida!\n");
                    } else {
                        printf("Chave invalida!\n");
                    }
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}