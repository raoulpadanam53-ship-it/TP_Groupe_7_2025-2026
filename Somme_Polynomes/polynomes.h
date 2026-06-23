#ifndef POLYNOMES_H
#define POLYNOMES_H

/* =========================================================
   📌 STRUCTURE : MONOME
   Représente un terme du polynôme : ax^b
========================================================= */
typedef struct {
    int coeff;   // coefficient (a)
    int expo;    // exposant (b)
} TMonome;

/* =========================================================
   📌 STRUCTURE : ELEMENT DE LISTE CHAÎNÉE
   Chaque élément contient un monôme + pointeur suivant
========================================================= */
typedef struct TElement {
    TMonome monome;          // donnée (monôme)
    struct TElement *suivant; // lien vers le prochain élément
} TElement;

/* =========================================================
   📌 STRUCTURE : LISTE DE POLYNÔMES
   Représente un polynôme sous forme de liste chaînée
========================================================= */
typedef struct {
    TElement *debut;  // premier élément
    TElement *fin;    // dernier élément
    int taille;       // nombre de monômes
} TListe;

/* =========================================================
   📌 PROTOTYPES DES FONCTIONS
========================================================= */

/* Initialisation de la liste */
void InitialiserListe(TListe *liste);

/* Ajout d’un monôme */
void AjouterMonome(TListe *liste, int coeff, int expo);

/* Libération mémoire */
void LibererListe(TListe *liste);

/* Sauvegarde dans un fichier binaire */
void Sauvegarder(TListe *liste, const char *nomFichier);

/* Chargement depuis un fichier binaire */
void Charger(TListe *liste, const char *nomFichier);

/* Calcul somme ou différence */
void Calculer(TListe *p1, TListe *p2, TListe *resultat, int signe);

/* Affichage d’un polynôme */
void Afficher(TListe *liste, const char *nom);

/* Interface utilisateur */
void AfficherMenuPrincipal();
void SaisirPolynome1(TListe *p1);
void SaisirPolynome2(TListe *p2);

#endif
