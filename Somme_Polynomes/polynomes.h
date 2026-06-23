#ifndef POLYNOMES_H
#define POLYNOMES_H

/* ========================================================
   STRUCTURES DE DONNÉES DU PROJET
======================================================== */

typedef struct {
    int coeff;
    int expo;
} TData;

typedef struct Element {
    TData data;
    struct Element *suivant;
} TElement;

typedef struct {
    TElement *debut;
    TElement *fin;
    int taille;
} TListe;

/* ========================================================
   REPARTITION DES 9 ROLES DU GROUPE
======================================================== */

// 👑 TON RÔLE : Gestion structurelle de base
void InitialiserListe(TListe *L);

// 👥 RÔLE 2 : Insertion d'un monôme
void AjouterElement(TListe *L, int coeff, int expo);

// 👥 RÔLE 3 : Nettoyage de la mémoire
void LibererListe(TListe *L);

// 👥 RÔLE 4 : Sauvegarde dans un fichier binaire
void Sauvegarder(TListe *L, char *nomFichier);

// 👥 RÔLE 5 : Chargement depuis un fichier binaire
void Charger(TListe *L, char *nomFichier);

// 👥 RÔLE 6 : Algorithme de calcul (Somme / Soustraction)
void Calculer(TListe *P1, TListe *P2, TListe *R, int signe);

// 👥 RÔLE 7 : Affichage console mis en forme
void Afficher(TListe *L, char *nom);

// 👥 RÔLE 8 : Interface utilisateur et saisie de P1
void AfficherMenuPrincipal();
void SaisirPolynome1(TListe *P1);

// 👥 RÔLE 9 : Saisie de P2 et Gestion de la boucle principale
void SaisirPolynome2(TListe *P2);

#endif // POLYNOMES_H
