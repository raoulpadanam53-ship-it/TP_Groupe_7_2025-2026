#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

int main() {
    TListe P1, P2, R;
    int choix, continuer = 1;
    int n, coeff, expo, i;

    InitialiserListe(&P1);
    InitialiserListe(&P2);
    InitialiserListe(&R);

    while (continuer) {
        printf("\n===== MENU =====\n");
        printf("1. Saisie\n");
        printf("2. Charger\n");
        printf("3. Sauvegarder\n");
        printf("4. P1 + P2\n");
        printf("5. P1 - P2\n");
        printf("6. Afficher P1 et P2\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            LibererListe(&P1);
            LibererListe(&P2);

            printf("Combien de monômes contient votre polynôme P1 : ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) {
                printf("  Entrez le coefficient du monôme %d : ", i + 1);
                scanf("%d", &coeff);
                printf("  Entrez l'exposant du monôme %d : ", i + 1);
                scanf("%d", &expo);
                AjouterElement(&P1, coeff, expo);
            }

            printf("Combien de monômes contient votre polynôme P2 : ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) {
                printf("  Entrez le coefficient du monôme %d : ", i + 1);
                scanf("%d", &coeff);
                printf("  Entrez l'exposant du monôme %d : ", i + 1);
                scanf("%d", &expo);
                AjouterElement(&P2, coeff, expo);
            }
        }
        else if (choix == 2) {
            Charger(&P1, "P1.bin");
            Charger(&P2, "P2.bin");
        }
        else if (choix == 3) {
            Sauvegarder(&P1, "P1.bin");
            Sauvegarder(&P2, "P2.bin");
        }
        else if (choix == 4) {
            Calculer(&P1, &P2, &R, 1);
            Afficher(&R, "SOMME");
        }
        else if (choix == 5) {
            Calculer(&P1, &P2, &R, -1);
            Afficher(&R, "DIFFERENCE");
        }
        else if (choix == 6) {
            Afficher(&P1, "P1");
            Afficher(&P2, "P2");
        }
        else if (choix == 0) {
            continuer = 0;
        }

        if (choix != 0) {
            printf("\nContinuer ? (1/0) : ");
            scanf("%d", &continuer);
        }
    }

    LibererListe(&P1);
    LibererListe(&P2);
    LibererListe(&R);

    return 0;
}

// --- Coded by Rôle 4 ---
void Calculer(TListe *P1, TListe *P2, TListe *R, int signe) {
    // À REMPLIR PAR LE RÔLE 4
}

// --- Coded by Rôle 5 ---
void Sauvegarder(TListe *L, char *nomFichier) {
    // À REMPLIR PAR LE RÔLE 5
}

// --- Coded by Rôle 6 ---
void Charger(TListe *L, char *nomFichier) {
    // À REMPLIR PAR LE RÔLE 6
}

// --- Coded by Rôle 7 ---
void SaisirPolynome1(TListe *P1) {
    // À REMPLIR PAR LE RÔLE 7
}

// ---  Rôle 8 ---
void SaisirPolynome2(TListe *P2) {
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
    TListe P1, P2, R;
    int choix, continuer = 1;

    // Raoul appelle ses fonctions d'initialisation ici
    InitialiserListe(&P1);
    InitialiserListe(&P2);
    InitialiserListe(&R);

    while (continuer) {
        AfficherMenuPrincipal();
        scanf("%d", &choix);

        if (choix == 1) {
            LibererListe(&P1);
            LibererListe(&P2);
            SaisirPolynome1(&P1);
            SaisirPolynome2(&P2);
        }
        else if (choix == 2) {
            Charger(&P1, "P1.bin");
            Charger(&P2, "P2.bin");
        }
        else if (choix == 3) {
            Sauvegarder(&P1, "P1.bin");
            Sauvegarder(&P2, "P2.bin");
        }
        else if (choix == 4) {
            Calculer(&P1, &P2, &R, 1);
            Afficher(&R, "SOMME");
        }
        else if (choix == 5) {
            Calculer(&P1, &P2, &R, -1);
            Afficher(&R, "DIFFERENCE");
        }
        else if (choix == 6) {
            Afficher(&P1, "P1");
            Afficher(&P2, "P2");
        }
        else if (choix == 0) {
            continuer = 0;
        }

        if (choix != 0) {
            printf("\nContinuer ? (1/0) : ");
            scanf("%d", &continuer);
        }
    }

    LibererListe(&P1);
    LibererListe(&P2);
    LibererListe(&R);

    return 0;
}
