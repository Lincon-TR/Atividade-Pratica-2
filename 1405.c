struct fila {
    int *começo;
    int *final;
};

struct dado {
    char letra;
    int peso;
    int *prox;
    int *anterior;
};

void inicializa (struct fila s);
void push (int *p, char letra, int peso); 
int *procura (struct fila s, int peso);

char* longestDiverseString(int a, int b, int c) {
    struct fila *s;
    int valor;

    inicializa(*s);

    while (a>0 || b>0 || c>0) {
        if (a>b && a>c) {
            valor = a;
            push(procura(*s,valor),a,valor);
            a--;
        } else if (b>c) {
                valor = b;
                push(procura(*s,valor),b,valor);
                b--;
            } else {
                    valor = c;
                    push(procura(*s,valor),c,valor);
                    c--;
                }
    };

    int *atual = s->começo;
    char *string = (char *) malloc(0);
    while (atual != NULL){
        string = realloc(string, sizeof(string)+sizeof(char));
        strcat(string,atual->letra);
        atual = atual->prox;
    }
    return string;
}

void inicializa (struct fila s) {
    s->começo = NULL;
    s->final = NULL;
}

void push (int *p, char letra, int peso) {
    struct dado *add = (struct *) malloc (sizeof(struct dado));
    add.letra = letra;
    add.peso = peso;
    add->prox = p->prox;
    p->prox = add;
}

int *procura (struct fila s, int peso) {
    int **atual = s->começo;
    int *anterior;

    while (peso < atual->peso || atual != NULL){
        anterior->prox = atual;
        atual = atual->prox;
    };

    if (atual == s->começo) {
        return 0;
    }

    return atual;
}