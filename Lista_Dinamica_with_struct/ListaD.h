#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct aluno Aluno;
typedef struct lista Lista;

Lista* criarLista(void);
Aluno* criarAluno(void);
Lista* lista_insere(Lista* lista, Aluno *aluno);
Lista* insere_final(Lista *lista, Aluno *aluno);
Lista* insere_meio(Lista *lista, Aluno *aluno, int elemento_anterior);
void lista_imprime(Lista* lista);
void lista_imprime_ordenado(Lista* lista);
Lista* lista_busca(Lista *lista, int matricula);
Lista* lista_retira(Lista *lista, int matricula);
Lista* lista_insere_ordenado(Lista *lista, Aluno* aluno);
void lista_libera(Lista* lista);

#endif // LISTAD_H_INCLUDED
