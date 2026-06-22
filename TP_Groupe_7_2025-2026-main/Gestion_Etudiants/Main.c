/*=====================================================
    UNIVERSITÉ / ÉTABLISSEMENT : EPL
    UE : Structures de données en Programmation C
    Étudiants : 
                MENSAH Attisso Maurice
                TCHOGLI Ayéfouni Magloire
                PADANAM Essobiou Raoul
                NONDO Rewou Tracy

    TITRE :
    Gestion dynamique d'une liste Simplement chaînée .

    Description :
    Programme permettant d'ajouter, supprimer,
    afficher et sauvegarder les éléments d'une
    liste chaînée en langage C.

    Année académique : 2025 - 2026
=====================================================*/



#include <stdio.h>
#include <stdlib.h>

// Structure d'un element
typedef struct TElement TElement;
struct TElement {
    int nombre;
    TElement *suivant;
};

// Structure de la liste
typedef struct TListe TListe;
struct TListe {
    TElement *debut;
    TElement *fin;
    int Taille;
};

// Initialisation
TListe* initialisation() {
    TListe* liste = (TListe*)malloc(sizeof(TListe));
    if (liste != NULL) {
        liste->debut = NULL;
        liste->fin = NULL;
        liste->Taille = 0;
    }else{
        printf("Erreur d'allocation");
    }
    return liste;
}

// Option : Ajouter au debut
void ajouterDebut(TListe *liste, int val) {
    if (liste != NULL)
        {
        TElement *nouveau = (TElement *)malloc(sizeof(TElement));

        if (nouveau != NULL)
            {
            nouveau->nombre = val;
            nouveau->suivant = liste->debut;

            if (liste->debut == NULL)
                {
                liste->fin = nouveau;
            }
            liste->debut = nouveau;
            liste->Taille++;
        }
    }
}

// Option : Ajouter a la fin
void ajouterFin(TListe *liste, int val) {
    if (liste != NULL) {
        TElement *nouveau = (TElement*)malloc(sizeof(TElement));
        if (nouveau != NULL) {
            nouveau->nombre = val;
            nouveau->suivant = NULL;
            if (liste->debut == NULL) {
                liste->debut = nouveau;
                liste->fin = nouveau;
            } else
            {
                liste->fin->suivant = nouveau;
                liste->fin = nouveau;
            }
            liste->Taille++;
        }
    }
}

// Option : Suppression par position
void suppressionPosition(TListe *liste, int position){
    TElement *a_supprimer = NULL;
    TElement *precedent = NULL;

    if (liste != NULL && position > 0 && position <= liste->Taille) {
        if (position == 1) {
            a_supprimer = liste->debut;
            liste->debut = a_supprimer->suivant;
            if (liste->debut == NULL) {
                liste->fin = NULL;
            }
        } else {
            precedent = liste->debut;
            for (int i = 1; i < position - 1; i++) {
                precedent = precedent->suivant;
            }
            a_supprimer = precedent->suivant;
            precedent->suivant = a_supprimer->suivant;
            if (a_supprimer->suivant == NULL) {
                liste->fin = precedent;
            }
        }

        if (a_supprimer != NULL)
            {
            free(a_supprimer);
            liste->Taille--;
        }
    }
}

// Option : Affichage des adresses
void afficherListe(TListe *liste) {
    if (liste != NULL)
        {
        TElement *actuel = liste->debut;
        printf("\n--- VUE DE LA MEMOIRE (Taille: %d) ---\n", liste->Taille);
        if (actuel == NULL)
        {
            printf("Liste vide.\n");
        } else {

            while (actuel != NULL) {
                printf("Val: %d\t | Adresse RAM:  \t%p\n", actuel->nombre, (void*)actuel);
                actuel = actuel->suivant;
            }
        }
        printf("--------------------------------------\n");
    }
}

// Nouvelle fonction dédiée pour exporter la liste dans un fichier
void enregistrerListeDansFichier(TListe *liste, const char *nom_fichier) {
    if (liste == NULL) return;

    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }

    TElement *actuel = liste->debut;
    fprintf(fichier, "--- SAUVEGARDE DE LA LISTE (Taille: %d) ---\n", liste->Taille);

    if (actuel == NULL) {
        fprintf(fichier, "Liste vide.\n");
    } else {
        while (actuel != NULL) {
            fprintf(fichier, "Val: %d\t | Adresse RAM: %p\n", actuel->nombre, (void*)actuel);
            actuel = actuel->suivant;
        }
    }
    fprintf(fichier, "-------------------------------------------\n");

    fclose(fichier);
    printf("La liste a ete correctement sauvegardee dans '%s' !\n", nom_fichier);
}

int main() {
    TListe *maListe = initialisation();
    int continuer = 1;
    int  val, pos;
    char choix[10]; // Modifié en tableau pour éviter les bugs de saisie avec %s

    if (maListe != NULL) {
        while (continuer == 1) {
            printf("\n--- MENU PRINCIPAL ---\n");
            printf("A. Ajouter un element au debut de la chaine\n");
            printf("B. Ajouter un element a la fin de la chaine\n");
            printf("C. Supprimer un element a une position donnee\n");
            printf("D. Afficher adresses et valeurs de la chaine\n");
            printf("E. Enregistrer la liste actuelle dans un fichier\n");
            printf("Z. Quitter directement\n");
            printf("Choix : ");
            scanf("%9s", choix); // Saisie sécurisée d'une chaîne

            // Gestion des actions en vérifiant le premier caractère de la saisie
            if (choix[0] == 'A')
                {
                printf("Valeur : ");
                scanf("%d", &val);
                ajouterDebut(maListe, val);
            }
            else if (choix[0] == 'B')
            {
                printf("Valeur : ");
                scanf("%d", &val);
                ajouterFin(maListe, val);
            }
            else if (choix[0] == 'C')
            {
                printf("Position (1 a %d) : ", maListe->Taille);
                scanf("%d", &pos);
                suppressionPosition(maListe, pos);
            }
            else if (choix[0] == 'D')
            {
                afficherListe(maListe);
            }
            else if (choix[0] == 'E')
            {
                enregistrerListeDansFichier(maListe, "liste_sauvegarde.txt");
            }
            else if (choix[0] == 'Z') {
                continuer = 0;
            }

            // Demander de continuer APRES chaque action (si on n'a pas deja quitte)
            if (continuer == 1 && choix[0] != 'Z')
                {
                printf("\nAction terminee. Voulez-vous continuer ? (1: OUI / 0: NON) : ");
                scanf("%d", &continuer);
            }
        }

        // Nettoyage avant de fermer
        while (maListe->debut != NULL) {
            suppressionPosition(maListe, 1);
        }
        free(maListe);
        printf("Programme termine.\n");
    }
    return 0;
}
