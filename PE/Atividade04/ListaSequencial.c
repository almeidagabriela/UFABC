#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------TAD Item------
struct Item{
    int chave;
};

struct Item criaItem(int);
//------FIM TAD Item------
//------TAD Lista------
struct Lista{
    struct Item *itens  ;
    int tamanho, quantidade;
};

struct Lista criaLista(int);
void destroiLista(struct Lista *);
int tamanho(struct Lista);
int vazia(struct Lista);
int cheia(struct Lista);
void inserir(struct Lista *, int, struct Item);
void inserirPrimeira(struct Lista *, struct Item);
void inserirUltima(struct Lista *, struct Item);
struct Item remover(struct Lista *, int);
struct Item removerPrimeira(struct Lista *);
struct Item removerUltima(struct Lista *);
//------FIM TAD Lista------

void mostrar(struct Lista);

int main(){
    int n, chave, posicao;
    char op[3]; //operação
    struct Lista lista;

    scanf("%d", &n);
    lista = criaLista(n);

    while(scanf("%s", op) != EOF){
        if(strcmp(op, "I") == 0){
            //Inserir
            scanf("%d %d", &chave, &posicao);
            inserir(&lista, posicao, criaItem(chave));
        }else if(strcmp(op, "I1") == 0){
            //Inserir na 1ª Posicao
            scanf("%d", &chave);
            inserirPrimeira(&lista, criaItem(chave));
        }else if(strcmp(op, "In") == 0){
            //Inserir na Ultima Posicao
            scanf("%d", &chave);
            inserirUltima(&lista, criaItem(chave));
        }else if(strcmp(op, "R") == 0){
            //Remover
            scanf("%d", &posicao);
            remover(&lista, posicao);
        }else if(strcmp(op, "R1") == 0){
            //Remover na 1ª Posicao
            removerPrimeira(&lista);
        }else if(strcmp(op, "Rn") == 0){
            //Remover na Ultima Posicao
            removerUltima(&lista);
        }if(strcmp(op, "M") == 0){
            mostrar(lista);
        }
    }

    destroiLista(&lista);

    return 0;
}

struct Item criaItem(int chave){
    struct Item it;
    it.chave = chave;

    return it;
}

void destroiLista(struct Lista *l){
    free(l->itens);
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens = (struct Item *) malloc(n * sizeof(struct Item));
    l.tamanho = n;
    l.quantidade = 0;

    return l;
}

int tamanho(struct Lista l){
    return l.tamanho;
}

int vazia(struct Lista l){
    return l.quantidade == 0;
}

int cheia(struct Lista l){
    return l.quantidade == tamanho(l);
}

void inserir(struct Lista *l, int p, struct Item it){
    if((!cheia(*l)) && (p <= l->quantidade)){
        for(int i = l->quantidade; i > p; i--){
            l->itens[i] = l->itens[i-1];
        }
        l->itens[p] = it;
        l->quantidade ++;
    }
}

void inserirPrimeira(struct Lista *l, struct Item it){
    inserir(l, 0, it);
}

void inserirUltima(struct Lista *l, struct Item it){
    inserir(l, l->quantidade, it);
}

struct Item remover(struct Lista *l, int p){
    struct Item removido;

    if(!vazia(*l) && (p <= l->quantidade-1)){
        removido = l->itens[p];

        for(int i = p; i < l->quantidade-1; i++){
            l->itens[i] = l->itens[i+1];
        }
        l->quantidade --;
    }

    return removido;
}

struct Item removerPrimeira(struct Lista *l){
    return remover(l, 0);
}

struct Item removerUltima(struct Lista *l){
    return remover(l, l->quantidade-1);
}

void mostrar(struct Lista l){
    for(int i = 0; i < l.quantidade; i++){
        printf("%d%s", l.itens[i].chave, i < l.quantidade-1 ?" ":"\n");
    }
}