#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

/* =========================================================
   📌 INITIALISATION DE LA LISTE
   On met tous les pointeurs à NULL et taille à 0
========================================================= */
void InitialiserListe(TListe *liste) {
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

/* =========================================================
   📌 AJOUT D’UN MONÔME À LA FIN
========================================================= */
void AjouterMonome(TListe *liste, int coeff, int expo) {

    /* On ignore les monômes nuls */
    if (coeff == 0) return;

    /* Création d’un nouvel élément */
    TElement *nouveau = (TElement*)malloc(sizeof(TElement));
    if (!nouveau) return;

    nouveau->monome.coeff = coeff;
    nouveau->monome.expo = expo;
    nouveau->suivant = NULL;

    /* Cas 1 : liste vide */
    if (liste->debut == NULL) {
        liste->debut = nouveau;
        liste->fin = nouveau;
    }
    /* Cas 2 : liste non vide */
    else {
        liste->fin->suivant = nouveau;
        liste->fin = nouveau;
    }

    liste->taille++;
}

/* =========================================================
   📌 LIBÉRATION DE MÉMOIRE
========================================================= */
void LibererListe(TListe *liste) {

    TElement *courant = liste->debut;

    while (courant != NULL) {
        TElement *temp = courant;   // sauvegarde
        courant = courant->suivant; // avance
        free(temp);                 // suppression
    }

    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

/* =========================================================
   📌 SAUVEGARDE BINAIRE
   Écrit les monômes dans un fichier
========================================================= */
void Sauvegarder(TListe *liste, const char *nomFichier) {

    FILE *fichier = fopen(nomFichier, "wb");
    if (!fichier) return;

    TElement *courant = liste->debut;

    while (courant != NULL) {
        fwrite(&courant->monome, sizeof(TMonome), 1, fichier);
        courant = courant->suivant;
    }

    fclose(fichier);
}

/* =========================================================
   📌 CHARGEMENT BINAIRE
   Reconstruit la liste depuis un fichier
========================================================= */
void Charger(TListe *liste, const char *nomFichier) {

    FILE *fichier = fopen(nomFichier, "rb");
    if (!fichier) return;

    LibererListe(liste); // vider avant chargement

    TMonome m;

    while (fread(&m, sizeof(TMonome), 1, fichier)) {
        AjouterMonome(liste, m.coeff, m.expo);
    }

    fclose(fichier);
}

/* =========================================================
   📌 CALCUL : SOMME OU DIFFÉRENCE
   signe = +1 → somme
   signe = -1 → soustraction
========================================================= */
void Calculer(TListe *p1, TListe *p2, TListe *resultat, int signe) {

    LibererListe(resultat);

    TElement *c1 = p1->debut;
    TElement *c2 = p2->debut;

    /* Fusion des deux polynômes */
    while (c1 && c2) {

        if (c1->monome.expo > c2->monome.expo) {
            AjouterMonome(resultat, c1->monome.coeff, c1->monome.expo);
            c1 = c1->suivant;
        }
        else if (c1->monome.expo < c2->monome.expo) {
            AjouterMonome(resultat, signe * c2->monome.coeff, c2->monome.expo);
            c2 = c2->suivant;
        }
        else {
            AjouterMonome(resultat,
                c1->monome.coeff + signe * c2->monome.coeff,
                c1->monome.expo);

            c1 = c1->suivant;
            c2 = c2->suivant;
        }
    }

    /* reste de p1 */
    while (c1) {
        AjouterMonome(resultat, c1->monome.coeff, c1->monome.expo);
        c1 = c1->suivant;
    }

    /* reste de p2 */
    while (c2) {
        AjouterMonome(resultat, signe * c2->monome.coeff, c2->monome.expo);
        c2 = c2->suivant;
    }
}

/* =========================================================
   📌 AFFICHAGE D’UN POLYNÔME
========================================================= */
void Afficher(TListe *liste, const char *nom) {

    printf("%s (taille=%d) : ", nom, liste->taille);

    if (liste->debut == NULL) {
        printf("0\n");
        return;
    }

    TElement *courant = liste->debut;

    while (courant != NULL) {
        printf("(%dx^%d)",
               courant->monome.coeff,
               courant->monome.expo);

        if (courant->suivant)
            printf(" + ");

        courant = courant->suivant;
    }

    printf("\n");
}

/* =========================================================
   📌 MENU PRINCIPAL
========================================================= */
void AfficherMenuPrincipal() {
    printf("\n===== MENU =====\n");
    printf("1. Saisie\n");
    printf("2. Charger\n");
    printf("3. Sauvegarder\n");
    printf("4. P1 + P2\n");
    printf("5. P1 - P2\n");
    printf("6. Afficher\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

/* =========================================================
   📌 SAISIE POLYNÔME 1
========================================================= */
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

/* =========================================================
   📌 SAISIE POLYNÔME 2
========================================================= */
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
