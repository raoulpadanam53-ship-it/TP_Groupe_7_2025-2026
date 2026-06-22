#ifndef POLYNOMES_H
#define POLYNOMES_H

/* ==========================================
   1. STRUCTURES (Les plans de la boîte)
   ========================================== */

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

/* ==========================================
   2. PROTOTYPES (La liste des tâches pour le groupe)
   ========================================== */

// Rôle 1
void InitialiserListe(TListe *L);

// Rôle 2
void LibererListe(TListe *L);

// Rôle 3
void AjouterElement(TListe *L, int coeff, int expo);

// Rôle 4
void Afficher(TListe *L, char *nom);

// Rôle 5
void Calculer(TListe *P1, TListe *P2, TListe *R, int signe);

// Rôle 6
void Sauvegarder(TListe *L, char *nomFichier);

// Rôle 7
void Charger(TListe *L, char *nomFichier);

// Rôle 8
void SaisirPolynome1(TListe *P1);
void SaisirPolynome2(TListe *P2);
void AfficherMenuPrincipal();

#endif
