#ifndef POLYNOMES_H
#define POLYNOMES_H

/* =========================
   STRUCTURES
========================= */

typedef struct TData {
    int coeff;
    int expo;
} TData;

typedef struct TElement {
    TData data;
    struct TElement *suivant;
} TElement;

typedef struct TListe {
    TElement *debut;
    TElement *fin;
    int taille;
} TListe;

/* =========================
   PROTOTYPES DES FONCTIONS
========================= */

// Rôle 1 : Gestion des listes (Mémoire et ajouts)
void InitialiserListe(TListe *L);
void AjouterElement(TListe *L, int coeff, int expo);
void LibererListe(TListe *L);

// Rôle 2 : Fichiers (Sauvegarde et Chargement)
void Sauvegarder(TListe *L, char *nomFichier);
void Charger(TListe *L, char *nomFichier);

// Rôle 3 : Opérations mathématiques (Somme et Différence)
void Calculer(TListe *P1, TListe *P2, TListe *R, int signe);

// Rôle 4 : Affichage de l'interface
void Afficher(TListe *L, char *nom);

#endif // POLYNOMES_H
