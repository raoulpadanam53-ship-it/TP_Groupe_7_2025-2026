#include <stdio.h>
#include "polynomes.h"

int main() {

    TListe P1, P2, R;
    int choix, continuer = 1;

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
            printf("Continuer ? (1/0) : ");
            scanf("%d", &continuer);
        }
    }

    LibererListe(&P1);
    LibererListe(&P2);
    LibererListe(&R);

    return 0;
}
