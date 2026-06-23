#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

/* ========================================================
   mon RÔLE : INITIALISATION DE LA LISTE
======================================================== */
void InitialiserListe(TListe *L) {
    L->debut = NULL;
    L->fin = NULL;
    L->taille = 0;
}

/* ========================================================
   👥 RÔLE 2 : AJOUT D'UN ÉLÉMENT EN FIN DE LISTE
======================================================== */
void AjouterElement(TListe *liste, int coeff, int expo) {
    TElement *nouveau = NULL;

    if (coeff != 0) {
        nouveau = malloc(sizeof(TElement));
        if (nouveau != NULL) {
            nouveau->data.coeff = coeff;
            nouveau->data.expo = expo;
            nouveau->suivant = NULL;

            if (liste->debut == NULL) {
                liste->debut = nouveau;
                liste->fin = nouveau;
            } else {
                liste->fin->suivant = nouveau;
                liste->fin = nouveau;
            }
            liste->taille++;
        }
    }
}

/* ========================================================
   👥 RÔLE 3 : LIBÉRATION DE LA MÉMOIRE
======================================================== */
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

/* ========================================================
   👥 RÔLE 4 : SAUVEGARDE BINAIRE
======================================================== */
void Sauvegarder(TListe *liste, const char *nomFichier){
    FILE *f = NULL;

    if (L == NULL || nomFichier == NULL || nomFichier[0] == '\0')
        return;

    f = fopen(nomFichier, "rb");
    if (f == NULL)
        return;

    for (TElement *courant = liste->debut; courant != NULL; courant = courant->suivant)
    {
        if (fwrite(&courant->data, sizeof(TData), 1, f) != 1)
        {
            fclose(f);
            return;
        }
    }

    fclose(f);        
}
/* ========================================================
   👥 RÔLE 5 : CHARGEMENT BINAIRE
======================================================== */
void Charger(TListe *L, char *nomFichier) {
    FILE *f = fopen(nomFichier, "rb");
    TData d;

    if (f == NULL) return;

    LibererListe(L);

    while (fread(&d, sizeof(TData), 1, f)) {
        AjouterElement(L, d.coeff, d.expo);
    }

    fclose(f);
}

/* ========================================================
   👥 RÔLE 6 : CALCULS MATHÉMATIQUES
======================================================== */
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

/* ========================================================
   👥 RÔLE 7 : AFFICHAGE DU POLYNÔME
======================================================== */
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
