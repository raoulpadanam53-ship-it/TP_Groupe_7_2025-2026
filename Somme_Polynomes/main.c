#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

/* ========================================================
   👥 RÔLE 8 : MENU PRINCIPAL ET SAISIE DE P1
======================================================== */
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

void SaisirPolynome1(TListe *P1) {
    int n, coeff, expo, i;
    printf("Combien de monômes contient votre polynôme P1 : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("  Entrez le coefficient du monôme %d : ", i + 1);
        scanf("%d", &coeff);
        printf("  Entrez l'exposant du monôme %d : ", i + 1);
        scanf("%d", &expo);
        AjouterElement(P1, coeff, expo);
    }
}

/* ========================================================
   👥 RÔLE 9 : SAISIE DE P2
======================================================== */
void SaisirPolynome2(TListe *P2) {
    int n, coeff, expo, i;
    printf("Combien de monômes contient votre polynôme P2 : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("  Entrez le coefficient du monôme %d : ", i + 1);
        scanf("%d", &coeff);
        printf("  Entrez l'exposant du monôme %d : ", i + 1);
        scanf("%d", &expo);
        AjouterElement(P2, coeff, expo);
    }
}

/* ========================================================
   ⚙️ EXÉCUTION DU PROGRAMME PRINCIPAL (Géré par le Rôle 9)
======================================================== */
int main() {
    TListe P1, P2, R;
    int choix, continuer = 1;

    // Appel du rôle de Raoul pour l'initialisation
    InitialiserListe(&P1);
    InitialiserListe(&P2);
    InitialiserListe(&R);

    while (continuer) {
        AfficherMenuPrincipal(); // Géré par Rôle 8
        scanf("%d", &choix);

        if (choix == 1) {
            LibererListe(&P1); // Appels Rôle 3
            LibererListe(&P2);
            SaisirPolynome1(&P1); // Appels Rôle 8
            SaisirPolynome2(&P2); // Appels Rôle 9
        }
        else if (choix == 2) {
            Charger(&P1, "P1.bin"); // Appels Rôle 5
            Charger(&P2, "P2.bin");
        }
        else if (choix == 3) {
            Sauvegarder(&P1, "P1.bin"); // Appels Rôle 4
            Sauvegarder(&P2, "P2.bin");
        }
        else if (choix == 4) {
            Calculer(&P1, &P2, &R, 1); // Appels Rôle 6
            Afficher(&R, "SOMME");      // Appels Rôle 7
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

    // Nettoyage final automatique
    LibererListe(&P1);
    LibererListe(&P2);
    LibererListe(&R);

    return 0;
}
