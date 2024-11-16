#ifndef BD_H
#define BD_H

#include <stdio.h>
//structure pour un nregistrement

typedef struct {
	char name[50];
	char surnam[50];
	int age;
	char gender[10];
	char job[50];
	char phone[15];
} Enregistrement;

//structure pour un noeud de l'arbre
typedef struct Noeud {
	Enregistrement data; //donnee de l'enregistrement
	struct Noeud* gauche; // sous-arbre gauche
	struct Noeud* droite;
} Noeud;

//fonctions de gestion des données
Noeud* insererNoeud(Noeud* racine, Enregistrement e);
Noeud* supprimerNoeud(Noeud* racine, const char* name);
Noeud* rechercherNoeud(Noeud* racine, const char* name);
int mettreAJourNoeud(Noeud* racine, const char* name, Enregistrement nouveau);
void afficherArbre(Noeud* racine);
void libererArbre(Noeud* racine);
//void chargerCSV(Noeud** racine, const char* chemin);
void afficherArbreGraphique(Noeud* racine, int niveau);
void construireArbreDepuisCSV(Noeud** racine, const char* chemin);
void sauvegarderArbreDansCSV(Noeud* racine, FILE* fichier);
void sauvegarderDansCSV(Noeud* racine, const char* chemin);


#endif
