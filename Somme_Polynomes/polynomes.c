#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

/* =========================
   INITIALISATION
========================= */
void InitialiserListe(TListe *liste) {
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

/* =========================
   AJOUT MONOME
========================= */
void AjouterMonome(TListe *liste, int coeff, int expo) {
    if (coeff == 0) return;

    TElement *nouveau = malloc(sizeof(TElement));
    if (!nouveau) return;

    nouveau->monome.coeff = coeff;
    nouveau->monome.expo = expo;
    nouveau->suivant = NULL;

    if (liste->debut == NULL) {
        liste->debut = liste->fin = nouveau;
    } else {
        liste->fin->suivant = nouveau;
        liste->fin = nouveau;
    }

    liste->taille++;
}

/* =========================
   LIBÉRATION
========================= */
void LibererListe(TListe *liste) {
    TElement *courant = liste->debut;

    while (courant) {
        TElement *tmp = courant;
        courant = courant->suivant;
        free(tmp);
    }

    liste->debut = liste->fin = NULL;
    liste->taille = 0;
}

/* =========================
   SAUVEGARDE
========================= */
void Sauvegarder(TListe *liste, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "wb");
    if (!f) return;

    for (TElement *c = liste->debut; c; c = c->suivant) {
        fwrite(&c->monome, sizeof(TMonome), 1, f);
    }

    fclose(f);
}

/* =========================
   CHARGEMENT
========================= */
void Charger(TListe *liste, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "rb");
    if (!f) return;

    LibererListe(liste);

    TMonome m;
    while (fread(&m, sizeof(TMonome), 1, f)) {
        AjouterMonome(liste, m.coeff, m.expo);
    }

    fclose(f);
}

/* =========================
   SIMPLIFICATION
   (fusion des mêmes exposants)
========================= */
void Simplifier(TListe *liste) {

    TElement *courant = liste->debut;

    while (courant) {

        TElement *prev = courant;
        TElement *tmp = courant->suivant;

        while (tmp) {

            if (tmp->monome.expo == courant->monome.expo) {

                courant->monome.coeff += tmp->monome.coeff;

                prev->suivant = tmp->suivant;
                free(tmp);

                liste->taille--;

                tmp = prev->suivant;
            } else {
                prev = tmp;
                tmp = tmp->suivant;
            }
        }

        courant = courant->suivant;
    }
}

/* =========================
   CALCUL SOMME / DIFF
========================= */
void Calculer(TListe *p1, TListe *p2, TListe *resultat, int signe) {

    LibererListe(resultat);

    for (TElement *c = p1->debut; c; c = c->suivant) {
        AjouterMonome(resultat, c->monome.coeff, c->monome.expo);
    }

    for (TElement *c = p2->debut; c; c = c->suivant) {
        AjouterMonome(resultat,
            signe * c->monome.coeff,
            c->monome.expo);
    }

    Simplifier(resultat);
}

/* =========================
   AFFICHAGE
========================= */
void Afficher(TListe *liste, const char *nom) {

    printf("%s (taille=%d) : ", nom, liste->taille);

    if (!liste->debut) {
        printf("0\n");
        return;
    }

    for (TElement *c = liste->debut; c; c = c->suivant) {
        printf("(%dx^%d)", c->monome.coeff, c->monome.expo);
        if (c->suivant) printf(" + ");
    }

    printf("\n");
}

/* =========================
   MENU
========================= */
void AfficherMenuPrincipal() {
    printf("\n===== MENU =====\n");
    printf("1. Saisie\n");
    printf("2. Charger\n");
    printf("3. Sauvegarder\n");
    printf("4. Somme\n");
    printf("5. Difference\n");
    printf("6. Afficher\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

/* =========================
   SAISIE P1
========================= */
void SaisirPolynome1(TListe *p1) {

    int n, coeff, expo;

    printf("Nombre de monomes P1 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Coeff : ");
        scanf("%d", &coeff);
        printf("Expo : ");
        scanf("%d", &expo);

        AjouterMonome(p1, coeff, expo);
    }
}

/* =========================
   SAISIE P2
========================= */
void SaisirPolynome2(TListe *p2) {

    int n, coeff, expo;

    printf("Nombre de monomes P2 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Coeff : ");
        scanf("%d", &coeff);
        printf("Expo : ");
        scanf("%d", &expo);

        AjouterMonome(p2, coeff, expo);
    }
}
