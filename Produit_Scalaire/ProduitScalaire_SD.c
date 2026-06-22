/*
Programme : produitScalaire
Role      : Calculer le produit scalaire de deux vecteurs U et V
Auteurs   : MENSAH Maurice (Chef) - GM
            TCHOGLI Ayéfouni Magloire - GM
            PADANAM Essobiou Raoul - GM
            DOSSOU Kodjovi Kévin - GC
            PALA Kivema Christophe - GC
            GAO Abdou Sabour Rodolphe - GM
            NONDO Réwou Tracy - GC
            BLAODEKISSI Essossolam - GC
            PITCHE S. Phanuel Jonas K. - GM
Date      : 08/04/2026
*/#include <stdio.h>
#include <stdlib.h>
// Fonction de récupération de la taille des vecteurs
int taille() {

    int N;

    printf("Entrez le nombre de composantes des vecteurs : ");

    while (scanf("%d", &N) != 1 || N < 2)
        {
        printf("[!] Erreur. Entrez un entier >= 2 : ");

        while (getchar() != '\n');
    }
    return N;
}

// Fonction permettant de lire chaque vecteur
void vect(float *tab, int N, char nom) {

    for (int i = 0; i < N; i++) {

        printf("Entrez la composante %d du vecteur %c : ", i + 1, nom);


        while (scanf("%f", &tab[i]) != 1) {

            printf("[!] Vous devez entrer un réel : ");

            while (getchar() != '\n');
        }
    }
}

// Fonction de calcul du produit scalaire
float scalaire(float *tab1, float *tab2, int N) {

    float produit = 0;

    for (int i = 0; i < N; i++) {

        produit += tab1[i] * tab2[i];
    }
    return produit;
}

// Procédure d'affichage des vecteurs
void affiche(float *tab1, float *tab2, int N) {

    printf("\nLes deux vecteurs enregistrés sont :\n");

    printf("u(");

    for (int i = 0; i < N; i++) {

        printf("%.2f", tab1[i]);

        if (i < N - 1) printf(", ");
    }

    printf(")\n");


    printf("v(");

    for (int i = 0; i < N; i++) {

        printf("%.2f", tab2[i]);

        if (i < N - 1) printf(", ");
    }

    printf(")\n");
}

// Procédure d'affichage du produit scalaire

void affichescalaire(float resultat) {

    printf("\nLe produit scalaire des vecteurs u et v est : %.2f\n", resultat);
}

int main()
{

 int N = taille();


    float *u = malloc(N * sizeof(float));

    float *v = malloc(N * sizeof(float));

    // Vérification de l’allocation mémoire
    if (u == NULL || v == NULL) {

        printf("Erreur d'allocation mémoire.\n");

        free(u);

        free(v);

        return 1;
    }

    float resultat;


    vect(u, N, 'u');

    vect(v, N, 'v');


    affiche(u, v, N);

    resultat = scalaire(u, v, N);

    affichescalaire(resultat);

    // Libération mémoire

    free(u);

    free(v);
);
    return 0;
}
