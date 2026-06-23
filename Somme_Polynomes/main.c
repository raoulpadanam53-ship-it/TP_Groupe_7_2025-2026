#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

int main() {

    /* =========================
       VARIABLES PRINCIPALES
    ========================= */
    TListe polynome1, polynome2, resultat;
    int choix, continuer = 1;

    /* Initialisation des listes */
    InitialiserListe(&polynome1);
    InitialiserListe(&polynome2);
    InitialiserListe(&resultat);

    /* =========================
       BOUCLE PRINCIPALE
    ========================= */
    while (continuer) {

        AfficherMenuPrincipal();
        scanf("%d", &choix);

        /* ---- SAISIE ---- */
        if (choix == 1) {
            LibererListe(&polynome1);
            LibererListe(&polynome2);

            SaisirPolynome1(&polynome1);
            SaisirPolynome2(&polynome2);
        }

        /* ---- CHARGEMENT ---- */
        else if (choix == 2) {
            Charger(&polynome1, "P1.bin");
            Charger(&polynome2, "P2.bin");
        }

        /* ---- SAUVEGARDE ---- */
        else if (choix == 3) {
            Sauvegarder(&polynome1, "P1.bin");
            Sauvegarder(&polynome2, "P2.bin");
        }

        /* ---- SOMME ---- */
        else if (choix == 4) {
            Calculer(&polynome1, &polynome2, &resultat, 1);
            Afficher(&resultat, "SOMME");
        }

        /* ---- DIFFERENCE ---- */
        else if (choix == 5) {
            Calculer(&polynome1, &polynome2, &resultat, -1);
            Afficher(&resultat, "DIFFERENCE");
        }

        /* ---- AFFICHAGE ---- */
        else if (choix == 6) {
            Afficher(&polynome1, "P1");
            Afficher(&polynome2, "P2");
        }

        /* ---- QUITTER ---- */
        else if (choix == 0) {
            continuer = 0;
        }

        /* Continuer ou non */
        if (choix != 0) {
            printf("Continuer ? (1/0) : ");
            scanf("%d", &continuer);
        }
    }

    /* =========================
       NETTOYAGE FINAL
    ========================= */
    LibererListe(&polynome1);
    LibererListe(&polynome2);
    LibererListe(&resultat);

    return 0;
}
