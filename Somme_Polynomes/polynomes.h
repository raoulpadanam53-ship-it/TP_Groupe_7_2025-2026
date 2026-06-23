#ifndef POLYNOMES_H
#define POLYNOMES_H

/* ========================================================
   STRUCTURES DE DONNÉES DU PROJET
======================================================== */

typedef struct TMonome TMonome{
    int coeff;
    int expo;
};

typedef struct TPolynome Tpolynome{
    Tpolynome monome;
    struct Tpolynome *suivant;
};

typedef struct TListe TListe {
    Tpolynome *debut;
    Tpolynome *fin;
    int taille;
};

/* ========================================================
   REPARTITION DES 9 ROLES DU GROUPE
======================================================== */

// 👑 TON RÔLE : Gestion structurelle de base
void InitialiserListe(TListe *liste);

// 👥 RÔLE 2 : Insertion d'un monôme
void AjouterElement(TListe *liste, int coeff, int expo);

// 👥 RÔLE 3 : Nettoyage de la mémoire
void LibererListe(TListe *liste);

// 👥 RÔLE 4 : Sauvegarde dans un fichier binaire
void Sauvegarder(TListe *liste, char *nomFichier);

// 👥 RÔLE 5 : Chargement depuis un fichier binaire
void Charger(TListe *liste, char *nomFichier);

// 👥 RÔLE 6 : Algorithme de calcul (Somme / Soustraction)
void Calculer(TListe *polynome1, TListe *polynome2, TListe *R, int signe);

// 👥 RÔLE 7 : Affichage console mis en forme
void Afficher(TListe *liste, char *nom);

// 👥 RÔLE 8 : Interface utilisateur et saisie de P1
void AfficherMenuPrincipal();
void SaisirPolynome1(TListe *polynome1);

// 👥 RÔLE 9 : Saisie de P2 et Gestion de la boucle principale
void SaisirPolynome2(TListe *polynome2);

#endif // POLYNOMES_H
