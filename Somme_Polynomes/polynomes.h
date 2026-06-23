#ifndef POLYNOMES_H
#define POLYNOMES_H

/* =========================
   MONOME
========================= */
typedef struct {
    int coeff;
    int expo;
} TMonome;

/* =========================
   ELEMENT LISTE
========================= */
typedef struct TElement {
    TMonome monome;
    struct TElement *suivant;
} TElement;

/* =========================
   LISTE POLYNOME
========================= */
typedef struct {
    TElement *debut;
    TElement *fin;
    int taille;
} TListe;

/* =========================
   FONCTIONS
========================= */
void InitialiserListe(TListe *liste);
void AjouterMonome(TListe *liste, int coeff, int expo);
void LibererListe(TListe *liste);

void Sauvegarder(TListe *liste, const char *nomFichier);
void Charger(TListe *liste, const char *nomFichier);

void Calculer(TListe *p1, TListe *p2, TListe *resultat, int signe);
void Simplifier(TListe *liste);
void Afficher(TListe *liste, const char *nom);

/* INTERFACE */
void AfficherMenuPrincipal();
void SaisirPolynome1(TListe *p1);
void SaisirPolynome2(TListe *p2);

#endif
