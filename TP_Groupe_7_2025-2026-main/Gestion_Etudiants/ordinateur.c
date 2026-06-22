#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinateur.h"



void AfficherMenuUtilisateur()
{
    printf("\n--- GESTION DES ORDINATEURS SD+C ---\n");
    printf("1. Ajouter un ordinateur au parc informatique\n");
    printf("2. Lister les ordinateurs du parc informatique\n");
    printf("3. Afficher les details complets d'un ordinateur\n");
    printf("4. Supprimer un ordinateur du parc informatique\n");
    printf("5. Classer la liste par vitesse des processeurs\n");
    printf("6. Calculer la valeur totale du parc informatique\n");
    printf("0. Quitter le programme\n");
    printf("Votre choix : ");
}



// NOUVELLE FONCTION
int DemanderContinuerOuQuitter()
{
    char choix;
    printf("\nSouhaitez-vous revenir au menu principal (M) ou quitter le programme (Q) ? \n ");
    scanf(" %c", &choix);
    if (choix == 'Q' || choix == 'q') {
        return 0; // Quitter
    }
    return 1; // Revenir au menu
}



Tordinateur* CreerNouvelOrdinateur() {
    Tordinateur* nouvelOrdinateur = (Tordinateur*)malloc(sizeof(Tordinateur));
    if (nouvelOrdinateur == NULL) return NULL;

    printf("Numero de carte du detenteur : ");
    scanf("%d", &nouvelOrdinateur->numeroCarteDetenteur);
    printf("Specialite du detenteur : ");
    scanf("%s", nouvelOrdinateur->specialiteDetenteur);
    printf("Numero de serie de l'appareil : ");
    scanf("%s", nouvelOrdinateur->numeroSerie);
    printf("Marque de l'ordinateur : ");
    scanf("%s", nouvelOrdinateur->marqueOrdinateur);
    printf("Vitesse du processeur (en Gigahertz) : ");
    scanf("%f", &nouvelOrdinateur->vitesseProcesseurGigahertz);
    printf("Memoire vive (en Gigaoctets) : ");
    scanf("%d", &nouvelOrdinateur->memoireViveGigaoctets);
    printf("Taille du disque dur (en Gigaoctets) : ");
    scanf("%d", &nouvelOrdinateur->tailleDisqueDurGigaoctets);
    printf("Prix estime (en Franc CFA) : ");
    scanf("%d", &nouvelOrdinateur->prixEstimeFrancCFA);

    return nouvelOrdinateur;
}



void AjouterOrdinateurAuParc(Tordinateur** parcInformatique, int* nombreActuelOrdinateurs)
{
    if (*nombreActuelOrdinateurs >= NombreMaximumOrdinateurs) {
        // Correction du printf ici :
        printf("\n[ERREUR] : La limite maximale de %d ordinateurs est atteinte.\n", NombreMaximumOrdinateurs);
        printf("Impossible d'ajouter une nouvelle unite.\n");
        return;
    }

    Tordinateur* nouvelOrdinateur = CreerNouvelOrdinateur();
    if (nouvelOrdinateur != NULL) {
        *(parcInformatique + *nombreActuelOrdinateurs) = nouvelOrdinateur;
        (*nombreActuelOrdinateurs)++;
        printf("L'ordinateur a ete ajoute avec succes.\n");
    }
}



void ListerOrdinateursDuParc(Tordinateur** parcInformatique, int nombreActuelOrdinateurs)
{
    if (nombreActuelOrdinateurs == 0) {
        printf("Le parc informatique est actuellement vide.\n");
        return;
    }
    printf("\n%-10s | %-15s | %-15s | %-10s\n", "CARTE", "MARQUE", "SERIE", "PRIX");
    for (int i = 0; i < nombreActuelOrdinateurs; i++) {
        Tordinateur* ordinateur = *(parcInformatique + i);
        printf("%-10d | %-15s | %-15s | %-10d Franc CFA\n",
               ordinateur->numeroCarteDetenteur,
               ordinateur->marqueOrdinateur,
               ordinateur->numeroSerie,
               ordinateur->prixEstimeFrancCFA);
    }
}



void AfficherDetailsOrdinateurSpecifique(Tordinateur** parcInformatique, int nombreActuelOrdinateurs)
{
    int numeroRecherche;
    printf("Entrez le numero de carte du detenteur : ");
    scanf("%d", &numeroRecherche);

    for (int i = 0; i < nombreActuelOrdinateurs; i++) {
        Tordinateur* ordinateur = *(parcInformatique + i);
        if (ordinateur->numeroCarteDetenteur == numeroRecherche) {
            printf("\n--- DETAILS COMPLETS ---\n");
            printf("Marque : %s\n", ordinateur->marqueOrdinateur);
            printf("Processeur : %.2f Gigahertz\n", ordinateur->vitesseProcesseurGigahertz);
            printf("Memoire Vive : %d Gigaoctets\n", ordinateur->memoireViveGigaoctets);
            printf("Disque Dur : %d Gigaoctets\n", ordinateur->tailleDisqueDurGigaoctets);
            return;
        }
    }
    printf("Aucun ordinateur trouve.\n");
}



void SupprimerOrdinateurDuParc(Tordinateur** parcInformatique, int* nombreActuelOrdinateurs)
{
    int numeroRecherche;
    printf("Entrez le numero de carte pour la suppression : ");
    scanf("%d", &numeroRecherche);

    for (int i = 0; i < *nombreActuelOrdinateurs; i++) {
        if ((*(parcInformatique + i))->numeroCarteDetenteur == numeroRecherche) {
            free(*(parcInformatique + i));
            for (int j = i; j < *nombreActuelOrdinateurs - 1; j++) {
                *(parcInformatique + j) = *(parcInformatique + j + 1);
            }
            (*nombreActuelOrdinateurs)--;
            printf("L'ordinateur a ete correctement supprime.\n");
            return;
        }
    }
    printf("Aucun ordinateur trouve avec ce numero.\n");
}



void ClasserOrdinateursParVitesseProcesseur(Tordinateur** parcInformatique, int nombreActuelOrdinateurs)
{
    for (int i = 0; i < nombreActuelOrdinateurs - 1; i++) {
        for (int j = 0; j < nombreActuelOrdinateurs - i - 1; j++) {
            if ((*(parcInformatique + j))->vitesseProcesseurGigahertz < (*(parcInformatique + j + 1))->vitesseProcesseurGigahertz) {
                Tordinateur* temporaire = *(parcInformatique + j);
                *(parcInformatique + j) = *(parcInformatique + j + 1);
                *(parcInformatique + j + 1) = temporaire;
            }
        }
    }
    printf("La liste a ete classee par vitesse de processeur decroissante.\n");
}



long CalculerValeurTotaleParcInformatique(Tordinateur** parcInformatique, int nombreActuelOrdinateurs)
{
    long sommeTotale = 0;
    for (int i = 0; i < nombreActuelOrdinateurs; i++) {
        sommeTotale += (*(parcInformatique + i))->prixEstimeFrancCFA;
    }
    return sommeTotale;
}



void LibererMemoireTotaleParc(Tordinateur** parcInformatique, int nombreActuelOrdinateurs)
{
    for (int i = 0; i < nombreActuelOrdinateurs; i++) {
        free(*(parcInformatique + i));
    }
    free(parcInformatique);
}
