#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"


void InitialiserListe(TListe *liste) {
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}


void LibererListe(TListe *liste) {
    TElement *courant = liste->debut;
    TElement *tmp = NULL;

    while (courant != NULL) {
        tmp = courant;
        courant = courant->suivant;
        free(tmp); // On libère le monôme actuel
    }

    // Remise à zéro des pointeurs et de la taille
    liste->debut = NULL;
    liste->fin = NULL;
    liste->taille = 0;
}

// ---  Rôle 2 ---
void AjouterElement(TListe *liste, int coeff, int expo) {
    // À REMPLIR PAR LE RÔLE 2
}

// ---  Rôle 3 ---
void Afficher(TListe *liste, char *nom) {
    // À REMPLIR PAR LE RÔLE 3
}

// --- Coded by Rôle 4 ---
void Calculer(TListe *polynome1, TListe *polynome2, TListe *R, int signe) {
    // À REMPLIR PAR LE RÔLE 4
}

// --- Coded by Rôle 5 ---
void Sauvegarder(TListe *liste, char *nomFichier) {
    // À REMPLIR PAR LE RÔLE 5
}

// --- Coded by Rôle 6 ---
void Charger(TListe *liste, char *nomFichier) {
    // À REMPLIR PAR LE RÔLE 6
}

// --- Coded by Rôle 7 ---
void SaisirPolynome1(TListe *polynome1) {
    // À REMPLIR PAR LE RÔLE 7
}

// ---  Rôle 8 ---
void SaisirPolynome2(TListe *polynome2) {
    // À REMPLIR PAR LE RÔLE 8
}

// ---  Rôle 3 ---
void AfficherMenuPrincipal() {
    printf("\n===== MENU =====\n");
    printf("1. Saisie\n");
    printf("2. Charger\n");
    printf("3. Sauvegarder\n");
    printf("4. P1 + P2\n");
    printf("5. P1 - P2\n");
    printf("6. Afficher P1 et P2\n");
    printf("0. Quitter\n");
    printf("Choix : ");
}

/* ========================================================
   FONCTION PRINCIPALE
   ======================================================== */
int main() {
    TListe polynome1, polynome2, R;
    int choix, continuer = 1;

    // Raoul appelle ses fonctions d'initialisation ici
    InitialiserListe(&polynome1);
    InitialiserListe(&polynome2);
    InitialiserListe(&R);

    while (continuer) {
        AfficherMenuPrincipal();
        scanf("%d", &choix);

        if (choix == 1) {
            LibererListe(&polynome1);
            LibererListe(&polynome2);
            SaisirPolynome1(&polynome1);
            SaisirPolynome2(&polynome2);
        }
        else if (choix == 2) {
            Charger(&polynome1, "P1.bin");
            Charger(&polynome2, "P2.bin");
        }
        else if (choix == 3) {
            Sauvegarder(&polynome1, "P1.bin");
            Sauvegarder(&polynome2, "P2.bin");
        }
        else if (choix == 4) {
            Calculer(&polynome1, &polynome2, &R, 1);
            Afficher(&R, "SOMME");
        }
        else if (choix == 5) {
            Calculer(&polynome1, &polynome2, &R, -1);
            Afficher(&R, "DIFFERENCE");
        }
        else if (choix == 6) {
            Afficher(&polynome1, "P1");
            Afficher(&polynome2, "P2");
        }
        else if (choix == 0) {
            continuer = 0;
        }

        if (choix != 0) {
            printf("\nContinuer ? (1/0) : ");
            scanf("%d", &continuer);
        }
    }

    LibererListe(&polynome1);
    LibererListe(&polynome2);
    LibererListe(&R);

    return 0;
}
