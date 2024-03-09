#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"

typedef struct aluno Aluno;
struct aluno{
    char nome[100];
    int matricula;
};

typedef struct lista Lista;
struct lista{
    Aluno aluno;
    struct Lista *proximo;
};

Lista* criarLista(void) {
    return NULL;
}

Aluno* criarAluno() {
    Aluno *al = malloc(sizeof(Aluno));
    if (al) {
        printf("\nDigite o nome do aluno: ");
        scanf("%*c");
        fgets(al->nome, 99, stdin);
        printf("\nDigite a matricula: ");
        scanf("%d", &al->matricula);
        return al;
    } else {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
}

Lista* lista_insere(Lista* lista, Aluno *aluno) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (novo) {
        novo->aluno = *aluno;
        novo->proximo = lista;
        return novo;
    } else {
        printf("Erro ao alocar memoria\n");
        return lista;
    }
}

Lista* insere_final(Lista *lista, Aluno *aluno) {
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo) {
        novo->aluno = *aluno;
        novo->proximo = NULL;

        if (lista == NULL) {
            lista = novo;
        } else {
            aux = lista;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        return lista;
    } else {
        printf("Erro ao alocar memoria");
        return lista;
    }
}

Lista* insere_meio(Lista *lista, Aluno *aluno, int elemento_anterior) {
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo) {
        novo->aluno = *aluno;
        if (lista == NULL) {
            novo->proximo = NULL;
            lista = novo;
        } else {
            aux = lista;
            while (aux->proximo && aux->aluno.matricula != elemento_anterior) {
                aux = aux->proximo;
            }
            if (aux->aluno.matricula == elemento_anterior) {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            } else {
                printf("Elemento anterior nao encontrado na lista\n");
                free(novo);
            }
        }
        return lista;
    } else {
        printf("Erro ao alocar memoria\n");
        return lista;
    }
}

void lista_imprime(Lista* lista) {
    Lista* aux = lista;
    printf("\n\tLista: \n");
    while (aux != NULL) {
        printf("Nome: %s\nMatricula: %d\n", aux->aluno.nome, aux->aluno.matricula);
        aux = aux->proximo;
    }
    printf("\n\n");
    printf("\nfinalizou a impressao");
}

void lista_imprime_ordenado(Lista* lista) {
    // Copia a lista original para uma nova lista
    Lista* copia = NULL;
    Lista* percorre = lista;
    while (percorre != NULL) {
        copia = lista_insere_ordenado(copia, &(percorre->aluno));
        percorre = percorre->proximo;
    }

    // Imprime a lista ordenada
    printf("\n\tLista ordenada: \n");
    while (copia != NULL) {
        printf("Nome: %s\nMatricula: %d\n", copia->aluno.nome, copia->aluno.matricula);
        copia = copia->proximo;
    }
    printf("\nfinalizou a impressao\n");
}


Lista* lista_busca(Lista *lista, int matricula) {
    Lista* auxiliar;
    for (auxiliar = lista; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (auxiliar->aluno.matricula == matricula) {
            return auxiliar;
        }
    }
    return NULL;
}

Lista* lista_retira(Lista *lista, int matricula) {
    Lista* anterior = NULL;
    Lista* auxiliar = lista;
    while(auxiliar != NULL && auxiliar->aluno.matricula != matricula) {
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }
    if(auxiliar == NULL) {
        return lista;
    }
    if(anterior == NULL) {
        lista = auxiliar->proximo;
    } else {
        anterior->proximo = auxiliar->proximo;
    }
    free(auxiliar);
    return lista;
}

Lista* lista_insere_ordenado(Lista *lista, Aluno* aluno) {
    Lista* novo;
    Lista* anterior = NULL;
    Lista* percorre = lista;

    while(percorre != NULL && percorre->aluno.matricula < lista->aluno.matricula) {
        anterior = percorre;
        percorre = percorre->proximo;
    }
    novo = (Lista*) malloc(sizeof(Lista));
    novo->aluno = *aluno;
    if(anterior == NULL) {
        novo->proximo = lista;
        lista = novo;
    } else {
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    return lista;
}

void lista_libera(Lista* lista) {
    Lista* liberando;
    Lista* auxiliar = lista;
    while(auxiliar != NULL) {
        liberando = auxiliar->proximo;
        free(auxiliar);
        auxiliar = liberando;
    }
}
