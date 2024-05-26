#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *T;
    int capacite; 
    int indice;
} Pile;

int estVide(Pile p) {
    return (p.indice == -1);
}

void afficheIterative(Pile p){
    while(!estVide(p)) {
        printf("%d, ", p.T[p.indice]);
        p.indice --;
    }
    printf("\n");
}

void afficheRecusrive(Pile p, int indice) {
    if (indice == -1) { printf("Pile vide");}
    if (indice == 0) { printf("%d, ", p.T[0]);}
    else {
        printf("%d", p.T[p.capacite]);
        afficheRecusrive(p, p.capacite --);
    }
    printf("\n");
}

void initPile(Pile *p, int capacite) {
    p -> T = (int*)malloc(capacite * sizeof(int));
    p -> capacite = capacite;
    p -> indice = -1;
}

void empiler(Pile *p, int valeur) {
    p -> T[++p -> indice] = valeur;
}

int depiler(Pile *p) {
    return p -> T[p -> indice--];
}

void supprimerPairs(Pile *p) {
    Pile temp;
    initPile(&temp, p -> capacite);
    
    while(!estVide(*p)) {
        int valeur = p -> T[p -> indice];
        if (valeur % 2 != 0) {
            empiler(&temp, valeur);
        }
        p -> indice --;
    }
    p -> indice = -1;
    *p = temp;
}

void main() {
    Pile p;
    initPile(&p, 5);

    empiler(&p, 1);
    empiler(&p, 2);
    empiler(&p, 3);
    empiler(&p, 4);
    empiler(&p, 5);

    afficheIterative(p);
    supprimerPairs(&p);
    afficheIterative(p);
}