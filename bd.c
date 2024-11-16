#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd.h"

//
void afficherArbreGraphique(Noeud* racine, int niveau) {
	if (racine == NULL) return;

	//affciher l sous arbre droit avec indentation augmente
	afficherArbreGraphique(racine->droite, niveau + 1);

	//indenter pour visualiser la hierarchie
	for (int i = 0; i < niveau; i++) {
		printf("   ");//trois espaces par  niveau
	}

	//aficher les données du noeud 
	printf("%s\n", racine->data.name);

	//afficher e sous arbre gauche avec indentation augmentee
	afficherArbreGraphique(racine->gauche, niveau + 1);
}


//lit un fichier csv et innere les enregistrement dans l'arbre binaire
void construireArbreDepuisCSV(Noeud** racine, const char* chemin) {
	FILE* fichier = fopen(chemin, "r");
	if (!fichier) {
		printf("Error: Impossible d'ouvrir le fichier %s\n", chemin);
		return;
	}

	char ligne[256];
	fgets(ligne, sizeof(ligne), fichier); //ignorer la ligne d'en-tete

	while (fgets(ligne, sizeof(ligne), fichier)) {
		Enregistrement e;

		//utilisation de strtok pour découper les champs
		char* token = strtok(ligne, ",");
		if (token) strncpy(e.name, token, sizeof(e.name) -1);

		token = strtok(NULL, ",");
		if (token) strncpy(e.surnam, token, sizeof(e.surnam) -1);

		token = strtok(NULL, ",");
		if (token) e.age = atoi(token); // convertir en entier

		token = strtok(NULL, ",");
		if (token) strncpy(e.gender, token, sizeof(e.gender) - 1);

		token = strtok(NULL, ",\n");
		if (token) strncpy(e.job, token, sizeof(e.job) -1);

		token = strtok(NULL, ",\n");
		if (token) strncpy(e.phone, token, sizeof(e.phone) -1);

		//insérer dans l'arbre
		*racine = insererNoeud(*racine, e);
	}

	fclose(fichier);
	printf("Arbre construit a partir de  %s.\n", chemin);
}

void sauvegarderArbreDansCSV(Noeud* racine, FILE* fichier) {
	if (racine == NULL) return;

	sauvegarderArbreDansCSV(racine->gauche, fichier);
	
	fprintf(fichier, "%s,%s,%d,%s,%s,%s\n",
		racine->data.name,racine->data.surnam,
		racine->data.age,racine->data.gender,
		racine->data.job,racine->data.phone);
	sauvegarderArbreDansCSV(racine->droite, fichier);
}

void sauvegarderDansCSV(Noeud* racine, const char* chemin){
	FILE* fichier = fopen(chemin, "w");
	if (!fichier) {
		printf("Ereur : impossible %s\n", chemin);
		return;
	}
	fprintf(fichier, "name,surname,age,gender,job,phone\n"); //en tete
	sauvegarderArbreDansCSV(racine, fichier);
	fclose(fichier);
	printf("les données ont ete sauvegarde dans %s.\n", chemin);
}



//insérer un noeaud dasn l'arbre
Noeud* insererNoeud(Noeud* racine, Enregistrement e){
	if (racine == NULL) {
	Noeud* nouveau = (Noeud*)malloc(sizeof(Noeud));
	nouveau->data = e;
	nouveau->gauche = NULL;
	nouveau->droite = NULL;
	return nouveau;
	}

	if (strcmp(e.name, racine->data.name) <0) {
		racine->gauche = insererNoeud(racine->gauche, e);
	}else{
		racine->droite = insererNoeud(racine->droite, e);
	}
	return racine;
}

// trouver le minimum dans le sous arbre droit
Noeud* trouverMin(Noeud* racine){
	while (racine && racine->gauche != NULL){
		racine = racine->gauche;
	}
	return racine;
}

// supprimer un noeud
Noeud* supprimerNoeud(Noeud* racine, const char* name){
	if (racine == NULL) return NULL;

	if (strcmp(name, racine->data.name)<0){
		racine->gauche = supprimerNoeud(racine->gauche, name);
	} else if (strcmp(name, racine->data.name)>0){
		racine->droite = supprimerNoeud(racine->droite, name);
	}else{
		if (racine->gauche == NULL){
			Noeud* temp = racine->droite;
			free(racine);
			return temp;
		} else if (racine->droite == NULL) {
			Noeud* temp = racine->gauche;
			free(racine);
			return temp;
		}
		Noeud* temp = trouverMin(racine->droite);
		racine->data = temp->data;
		racine->droite = supprimerNoeud(racine->droite, temp->data.name);
	}
	return racine;
}

//recherhce un noeud
Noeud* rechercherNoeud(Noeud* racine, const char* name) {
	if (racine == NULL || strcmp(racine->data.name, name) == 0) {
	return racine;
	}
	if (strcmp(name, racine->data.name) < 0){
		return rechercherNoeud(racine->gauche, name);
	}else{
	return rechercherNoeud(racine->droite, name);
	}
}

//mettre a jour un noeud
int mettreAJourNoeud(Noeud* racine, const char* name, Enregistrement nouveau) {
	if (racine == NULL) return 0;

	if (strcmp(name, racine->data.name) == 0) {
		racine->data = nouveau;
		return 1;
	}else if (strcmp(name, racine->data.name) < 0) {
		return mettreAJourNoeud(racine->gauche, name, nouveau);
	}else{
		return mettreAJourNoeud(racine->droite, name, nouveau);
	}
}

//Afficher l'arbre (parcours infixe)
void afficherArbre(Noeud* racine) {
	if (racine == NULL) return;
	afficherArbre(racine->gauche);
	printf("%s %s, %d, %s, %s, Phone: %s\n",
		racine->data.name, racine->data.surnam,
		racine->data.age, racine->data.gender,
		racine->data.job, racine->data.phone);
	afficherArbre(racine->droite);
}

//liberer arbre
void libererArbre(Noeud* racine) {
	if (racine == NULL) return;
	libererArbre(racine->gauche);
	libererArbre(racine->droite);
	free(racine);
}
