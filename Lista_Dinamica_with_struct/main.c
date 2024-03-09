#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"

int main() {
    int op, valor, anterior;
    Lista *lista = criarLista();
    do {
        printf("\n\tMENU\n");
        printf("\n0- Sair\n1-Inserir\n2-Inserir no Final\n3-Inserir no meio\n4- Imprimir\n5-Busca\n6 - Retirar\n7- Lista Ordenada\n");
        scanf("%d", &op);
        switch (op) {
        case 1:
            lista = lista_insere(lista, criarAluno()); // Captura o novo início da lista após a inserção
            break;
        case 2:
            insere_final(lista, criarAluno()); // Captura a lista atualizada após a inserção no final
            break;
        case 3:
            printf("\nDigite o elemento anterior que gostaria de inserir após ele: ");
            scanf("%d", &anterior);
            insere_meio(lista, criarAluno(), anterior); // Captura a lista atualizada após a inserção no meio
            break;
        case 4:
            printf("\nPrimeira versao de impressao (nao ordenada)\n");
            lista_imprime(lista);
            printf("\nSegunda versao de impressao(Ordenada)\n");
            lista_imprime_ordenado(lista);
            break;
        case 5:
            printf("\nDigite o valor que gostaria de buscar: ");
            scanf("%d", &valor);
            Lista* buscando = lista_busca(lista, valor);
            if(buscando != NULL){
                printf("\nENCONTRADO\n");
            }
            else{
                printf("\nNÃO ENCONTRADO\n");
            }
            break;
        case 6:
            printf("\nDigite o valor a retirar: ");
            scanf("%d", &valor);
            lista = lista_retira(lista, valor);
            if(lista != NULL){
                printf("\n%d - RETIRADO\n", valor);
            }
            else{
                printf("\nNÃO ENCONTRADO");
            }
            break;
        case 7:
            lista = lista_insere_ordenado(lista, criarAluno());
            break;
        default:
            break;
        }
    } while (op != 0);

    lista_libera(lista);
    return 0;
}
