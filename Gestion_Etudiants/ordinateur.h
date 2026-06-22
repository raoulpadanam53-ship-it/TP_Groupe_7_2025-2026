#ifndef ORDINATEUR_H
#define ORDINATEUR_H

#define NombreMaximumOrdinateurs 300

struct Ordinateur {
    int numeroCarteDetenteur;
    char specialiteDetenteur[100];
    char numeroSerie[100];
    char marqueOrdinateur[100];
    float vitesseProcesseurGigahertz;
    int memoireViveGigaoctets;
    int tailleDisqueDurGigaoctets;
    int prixEstimeFrancCFA;
};
typedef struct Ordinateur Tordinateur;

// Prototypes

void AfficherMenuUtilisateur();
int DemanderContinuerOuQuitter();
Tordinateur* CreerNouvelOrdinateur();
void AjouterOrdinateurAuParc(Tordinateur** parcInformatique, int* nombreActuelOrdinateurs);
void ListerOrdinateursDuParc(Tordinateur** parcInformatique, int nombreActuelOrdinateurs);
void AfficherDetailsOrdinateurSpecifique(Tordinateur** parcInformatique, int nombreActuelOrdinateurs);
void SupprimerOrdinateurDuParc(Tordinateur** parcInformatique, int* nombreActuelOrdinateurs);
void ClasserOrdinateursParVitesseProcesseur(Tordinateur** parcInformatique, int nombreActuelOrdinateurs);
long CalculerValeurTotaleParcInformatique(Tordinateur** parcInformatique, int nombreActuelOrdinateurs);
void LibererMemoireTotaleParc(Tordinateur** parcInformatique, int nombreActuelOrdinateurs);

#endif
