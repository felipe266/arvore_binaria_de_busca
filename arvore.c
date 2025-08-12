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
        if(aux->valor < chave){
            if (aux->dir != NULL){
                return buscar(aux->dir, chave);
            }else{
                return aux;
            }
        }else if (aux->valor > chave){
            if (aux->esq != NULL){
                return buscar(aux->esq, chave);
            }else{
                return aux;
            }
            
        }
        
    }
}

//maior dos menores
no* maior_dos_menores(no* aux, no** pai){
    while (aux->esq != NULL){
        *pai= aux;
        aux = aux->esq;
    }
    return aux;
}

no* excluir(no* aux, int chave){
    if (aux == NULL){
        return aux;
    }else{
        if (aux->valor == chave){
            if (aux->dir == NULL && aux->esq == NULL){
                free(aux);
                return NULL;
            }else if(aux->dir != NULL && aux->esq == NULL){
                no* temp = aux->dir;
                free(aux);
                return temp;
            }else if (aux->dir == NULL && aux->esq != NULL){
                no* temp = aux->esq;
                free(aux);
                return temp;
            }else{
                no* pai = aux;
                no* subistuir = maior_dos_menores(aux->dir, &pai);
                printf("valor cara%d\n", subistuir->valor);
                if (pai->valor == chave){
                    pai->dir = NULL;
                }else{
                    pai->esq = NULL;
                }
                subistuir->dir = aux->dir;
                subistuir->esq = aux->esq;
                if (raiz->valor == chave){
                    raiz = subistuir;
                }
                free(aux);
                return subistuir;
            }
        }
        if (aux->valor < chave){
            if (aux->dir != NULL){
                aux->dir = excluir(aux->dir, chave);
            }else{
                return aux;
            }
        }else if (aux->valor > chave){
            if (aux->esq != NULL){
                aux->esq = excluir(aux->esq, chave);
            }else{
                return aux;
            }
        }
    }
}

void add(int chave){
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
            if (aux->valor < chave){
                aux->dir = novo;
            }else{
                aux->esq = novo;
            }
        }
    }
}

void printar(no* aux){
    if (aux != NULL){
        printf("%d\n", aux->valor);
        printar(aux->dir);
        printar(aux->esq);
    }
}

int main(){

    add(20);
    add(15);
    add(21);
    add(10);
    add(11);
    add(19);
    add(16);
    add(18);
    add(8);
    add(9);
    excluir(raiz, 20);
    printar(raiz);

    return 0;
}