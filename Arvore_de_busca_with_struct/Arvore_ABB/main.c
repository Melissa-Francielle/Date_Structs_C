#include <stdio.h>
#include <stdlib.h>
#include "Arvore_ABB.h"

int main(){
    No *raiz = arvore_vazia();
    int op, valor;
    do{
        printf("\n\tMENU\n");
        printf("\n0-Sair\n1-Inserir\n2-Imprimir arvore e imprimir ordenado\n3-Busca\n4-Calcula a altura da arvore\n5-Verifica a quantidade de nos\n6-Quantidade de folhas\n7-Remover");
        printf("\n");
        printf("\nDigite qual opcao gostaira: ");
        scanf("%d", &op);
        switch(op){
        case 1:

            raiz = insercao_Arvore(raiz);
            break;
        case 2:
            printf("\nPrimeira Impressao (Nao ordenada)\n");
            imprimir_ver1(raiz);
            printf("\nSegunda Impressao (Ordenada)\n");
            imprimir_ordenada(raiz);
            break;
        case 3:
            printf("\nDigite o valor que gostaria de buscar: ");
            scanf("%d", &valor);
            raiz = busca_Arvore(raiz, valor);
            if (raiz == NULL){
                printf("\n\tVALOR NAO ENCONTRADO\n");
            }
            else{
                    printf("\n\tVALOR ENCONTRADO\n");
            }
            break;
        case 4:
            printf("\nAltura da arvore: ");
            int alt = altura(raiz);
            printf("%d ", alt);
            break;
        case 5:
            printf("\nQuantidade de nos: ");
            int nos = quantidade(raiz);
            printf("\n%d ", nos);
            break;
        case 6:
            printf("\nQuantidade de folhas: ");
            int folhas = quantidade_folhas(raiz);
            printf("\n%d ", folhas);
            break;
        case 7:
            printf("\nDigite o no que gostaria de remover: ");
            scanf("%d", &valor);
            raiz = remove_no(raiz, valor);
            break;
        default:
            break;
        }
    }while(op != 0);

    return 0;

}
