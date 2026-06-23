#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

/* =========================
   RÔLE 1 : GESTION DES LISTES
========================= */

void InitialiserListe(TListe *L) {
    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

void AjouterElement(TListe *L, int coeff, int expo) {
    TElement *nouveau = NULL;

    if (coeff != 0) {
        nouveau = malloc(sizeof(TElement));
        if (nouveau != NULL) {
            nouveau->data.coeff = coeff;
            nouveau->data.expo = expo;
            nouveau->suivant = NULL;

            if (L->debut == NULL) {
                L->debut = nouveau;
                L->fin = nouveau;
            } else {
                L->fin->suivant = nouveau;
                L->fin = nouveau;
            }
            L->taille++;
        }
    }
}

void LibererListe(TListe *L) {
    TElement *courant = L->debut;
    TElement *tmp = NULL;

    while (courant != NULL) {
        tmp = courant;
        courant = courant->suivant;
        free(tmp);
    }

    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

/* =========================
   RÔLE 2 : SAUVEGARDE ET CHARGEMENT
========================= */

void Sauvegarder(TListe *L, char *nomFichier) {
    FILE *f = fopen(nomFichier, "wb");
    TElement *courant = L->debut;
    TData d;

    if (f == NULL) return;

    while (courant != NULL) {
        d = courant->data;
        fwrite(&d, sizeof(TData), 1, f);
        courant = courant->suivant;
    }

    fclose(f);
}

void Charger(TListe *L, char *nomFichier) {
    FILE *f = fopen(nomFichier, "rb");
    TData d;

    if (f == NULL) return; // Sécurité si le fichier n'existe pas encore

    LibererListe(L);

    while (fread(&d, sizeof(TData), 1, f)) {
        AjouterElement(L, d.coeff, d.expo);
    }

    fclose(f);
}

/* =========================
   RÔLE 3 : CALCULS MATHÉMATIQUES
========================= */

void Calculer(TListe *P1, TListe *P2, TListe *R, int signe) {
    TElement *c1 = P1->debut;
    TElement *c2 = P2->debut;

    LibererListe(R);

    while (c1 != NULL && c2 != NULL) {
        if (c1->data.expo > c2->data.expo) {
            AjouterElement(R, c1->data.coeff, c1->data.expo);
            c1 = c1->suivant;
        }
        else if (c1->data.expo < c2->data.expo) {
            AjouterElement(R, signe * c2->data.coeff, c2->data.expo);
            c2 = c2->suivant;
        }
        else {
            AjouterElement(R, c1->data.coeff + signe * c2->data.coeff, c1->data.expo);
            c1 = c1->suivant;
            c2 = c2->suivant;
        }
    }

    while (c1 != NULL) {
        AjouterElement(R, c1->data.coeff, c1->data.expo);
        c1 = c1->suivant;
    }

    while (c2 != NULL) {
        AjouterElement(R, signe * c2->data.coeff, c2->data.expo);
        c2 = c2->suivant;
    }
}

/* =========================
   RÔLE 4 : AFFICHAGE
========================= */

void Afficher(TListe *L, char *nom) {
    TElement *courant = L->debut;

    printf("%s (taille = %d) : ", nom, L->taille);

    if (courant == NULL) {
        printf("0\n");
        return;
    }

    while (courant != NULL) {
        printf("(%dx^%d)", courant->data.coeff, courant->data.expo);

        if (courant->suivant != NULL)
            printf(" + ");

        courant = courant->suivant;
    }

    printf("\n");
}
