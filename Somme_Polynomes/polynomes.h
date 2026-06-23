#ifndef POLYNOMES_H
#define POLYNOMES_H

/* ==========================================
   1. STRUCTURES (Les plans de la boîte)
   ========================================== */

typedef struct TMonome TMonome  {
    int coeff;
    int expo;
};

typedef struct TElement TElement{
    TMonome monome;
    struct TElement *suivant;
};

typedef struct  TListe TListe {
    TElement *debut;
    TElement *fin;
    int taille;
};

/* ==========================================
   2. PROTOTYPES (La liste des tâches pour le groupe)
   ========================================== */

// Rôle 1
void InitialiserListe(TListe *liste);

// Rôle 2
void LibererListe(TListe *liste);

// Rôle 3
void AjouterElement(TListe *liste, int coeff, int expo);

// Rôle 4
void Afficher(TListe *liste, char *nom);

// Rôle 5
void Calculer(TListe *P1, TListe *P2, TListe *R, int signe);

// Rôle 6
void Sauvegarder(TListe *liste, char *nomFichier);

// Rôle 7
void Charger(TListe *liste, char *nomFichier);

// Rôle 8
void SaisirPolynome1(TListe *P1);
void SaisirPolynome2(TListe *P2);
void AfficherMenuPrincipal();

#endif
