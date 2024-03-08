#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct lista Lista;

Lista* criarLista(void);
void lista_libera(Lista* lista);

Lista* lista_insere(Lista* lista, int val);
Lista* lista_retira(Lista* lista, int val);
Lista* insere_meio(Lista *lista, int val, int elemento_anterior);
Lista* insere_final(Lista *lista, int val);

int lista_vazia(Lista* lista);
Lista* lista_busca(Lista* lista, int val);
void lista_imprime(Lista* lista);
int lista_igual(Lista* lista, Lista* segunda_lista);
Lista* lista_insere_ordenado(Lista* lista, int val);
#endif // LISTAD_H_INCLUDED
