#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* dir;
    struct No* esq;
}no;

no* raiz = NULL;
int tam = 0;

no* buscar(no* aux, int chave){
    if (aux == NULL){
        return aux;
    }else if (aux->valor == chave){
        return aux;
    }else{
        if(aux->valor > chave){
            if (aux->dir != NULL){
                return buscar(aux->dir, chave);
            }else{
                return aux;
            }
        }else if (aux->valor < chave){
            if (aux->esq != NULL){
                return buscar(aux->esq, chave);
            }else{
                return aux;
            }
            
        }
        
    }
}

void add(int chave, no* aux){
    no* aux = buscar(raiz, chave);
    no* novo = malloc(sizeof(no));

    novo->valor = chave;
    novo->dir = NULL;
    novo->esq = NULL;

    if(raiz == NULL){
        raiz = novo;
    }else{
        if (aux->valor == chave){
            printf("chave já existe");
            free(novo);
        }else{
            if (aux->valor > chave){
            aux->dir = novo;
            }else{
                aux->esq = novo;
            }
        }
    }
}