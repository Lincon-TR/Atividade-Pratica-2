struct fila {
    struct dado* começo;
    struct dado* final;
};

struct dado {
    char letra;
    int peso;
    struct dado* prox;
};

void push( struct fila* s, struct dado* p, char letra, int peso );

char* longestDiverseString(int a, int b, int c) {
    struct fila s;
    s.começo = NULL;
    s.final = NULL;

    char letraAnt = '\0';
    char letraAntAnt = '\0';

    char primeiro, segundo;
    int pri, seg;

    while ( a > 0 || b > 0 || c > 0 ) {
        
        if ( a >= b && a >= c ) {
            primeiro = 'a';
            pri = a;
            if ( b >= c) {
                segundo = 'b';
                seg = b;
            } else {
                segundo = 'c';
                seg = c;
            }
        } else if ( b >= a && b >= c ) {
            primeiro = 'b';
            pri = b;
            if ( a >= c ) {
                segundo = 'a';
                seg = a;
            } else {
                segundo = 'c';
                seg = c;
            }
        } else if ( c >= a && c >= b ) {  
            primeiro = 'c';
            pri = c;       
            if ( a >= b ) {
                segundo = 'a';
                seg = a;
            } else {
                segundo = 'b';
                seg = b;
            }
        }

        if ( pri > 0 && !( letraAnt == primeiro && letraAntAnt == primeiro) ) {
            push( &s, s.final, primeiro, pri );
            letraAntAnt = letraAnt;
            letraAnt = primeiro;
            if ( primeiro == 'a' ) {
                a--;
            } else if ( primeiro == 'b' ) {
                b--;
            } else {
                c--;
            }
        } else if ( seg > 0 ) {
            push( &s, s.final, segundo, seg );
            letraAntAnt = letraAnt;
            letraAnt = segundo;
            if ( segundo == 'a' ) {
                a--;
            } else if ( segundo == 'b' ) {
                b--;
            } else {
                c--;
            }
        } else {
            break;
        }
    };

    struct dado* atual = s.começo;
    char* string = (char *)malloc( 1 );
    string[0] = '\0';
    int len;

    while (atual != NULL) {
        len = strlen( string );
        string = realloc( string, len + 2 );
        string[len] = atual->letra;
        string[len + 1] = '\0';
        atual = atual->prox;
    }
    return string;
}

void push( struct fila* s, struct dado* p, char letra, int peso ) {
    struct dado* add = ( struct dado* ) malloc( sizeof( struct dado ) );
    add->letra = letra;
    add->peso = peso;

    if ( p == NULL ) {
        add->prox = s->começo;
        s->começo = add;
    } else {
        add->prox = p->prox;
        p->prox = add;
    }
    if ( add->prox == NULL ) {
        s->final = add;
    }
}
