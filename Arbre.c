#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* gauche;
    struct Noeud* droit;
} Noeud;

typedef Noeud* Arbre;

Arbre creerNoeud(int valeur) {
    Arbre noeud = (Arbre)malloc(sizeof(Noeud));
    noeud -> valeur = valeur;
    noeud -> gauche = NULL;
    noeud -> droit = NULL;
}

Arbre inserer(Arbre arbre, int valeur) {
    if (arbre == NULL) { return creerNoeud(valeur);}
    if (valeur > arbre -> valeur) {
        arbre -> droit = inserer(arbre -> droit, valeur);
    }
    else if (valeur < arbre -> valeur) {
        arbre -> gauche = inserer(arbre -> gauche, valeur);
    }
    return arbre;
}

void prefix(Arbre arbre) {
    if (arbre != NULL) {
        printf("%d, ", arbre -> valeur);
        prefix(arbre -> gauche);
        prefix(arbre -> droit);
    }
}

int verifFeuille(Arbre noeud) {
    return (noeud != NULL && noeud->gauche == NULL && noeud->droit == NULL);
}

int verifNoeudComplet(Arbre noeud) {
    return (noeud != NULL && noeud -> gauche != NULL && noeud -> droit != NULL);
}

void fill(Arbre arbre) {
    arbre = inserer(arbre, 5);
    arbre = inserer(arbre, 8);
    arbre = inserer(arbre, 5);
    arbre = inserer(arbre, 7);
    arbre = inserer(arbre, 10);
    arbre = inserer(arbre, 1);
}

// Methode qui retourne le taille(Nombre de noeuds)
int nbNoeuds(Arbre arbre) {
    if (arbre == NULL) { return 0;}
    else { return 1 + nbNoeuds(arbre -> droit) + nbNoeuds(arbre -> gauche);}
}

int hauteur(Arbre arbre) {
    if (arbre == NULL) {
        return -1;
    }
    else {
        int hauteurGauche = hauteur(arbre -> gauche);
        int hauteurDroit = hauteur(arbre -> droit);
        return 1 + (hauteurGauche > hauteurDroit ? hauteurGauche : hauteurDroit);
    }
}

int nbFeuille(Arbre arbre) {
    if (arbre == NULL) {
        return 0;
    } else if (verifFeuille(arbre)) {
        return 1;
    } else {
        return nbFeuille(arbre->gauche) + nbFeuille(arbre->droit);
    }
}

int max(Arbre arbre) {
    if (arbre == NULL) {
        return -1; 
    }
    while (arbre->droit != NULL) {
        arbre = arbre->droit;
    }
    return arbre->valeur;
}

void main() {
    Arbre arbre = NULL;

    arbre = inserer(arbre, 5);
    arbre = inserer(arbre, 8);
    arbre = inserer(arbre, 5);
    arbre = inserer(arbre, 7);
    arbre = inserer(arbre, 10);
    arbre = inserer(arbre, 1);
    
    printf("%d", hauteur(arbre));

    //prefix(arbre);
}