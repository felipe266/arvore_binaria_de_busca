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


no* excluir(no* aux, int chave){
    if (aux != NULL){
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
                printf("aqui: %d\n", aux->valor);
                aux->dir = novo;
            }else{
                printf("%d: %d\n",novo->valor, aux->valor);
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
    printar(raiz);

    return 0;
}