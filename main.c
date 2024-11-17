//gerer les interractions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bd.h"

void runTests();

void afficherMenu() {
	printf("\nMenu :\n");
	printf("1. Insert a record\n");
	printf("2. Delete a record\n");
	printf("3. Update a record\n");
	printf("4. Search for a record\n");
	printf("5. Display all records\n");
	printf("6. Advanced search by criterion\n");
	printf("7. Display tree structure (graphical)\n");
	printf("0. Quit\n");
}

int main(int argc, char* argv[]) {
	Noeud* racine = NULL;

	//construire automatiquement l'arbre a partir de user.csv
	construireArbreDepuisCSV(&racine, "user.csv");


	//gerer les commandes en ligne de commande
	if (argc > 1) {
		if (strcmp(argv[1], "test") == 0) {
			runTests();
			return 0;
			//vérifier qu'il y a sufisiamment d'arguments pour un insert
		}else if (strcmp(argv[1], "insert") == 0){
			if (argc != 8){
				printf("Usage: %s insert <name> <surname> <age> <gender> <job> <phone>\n", argv[0]);
				return 1;
			}

			//récuperer les données de l'user
			Enregistrement e;
			strncpy(e.name, argv[2], sizeof(e.name) -1);
			strncpy(e.surnam, argv[3], sizeof(e.surnam) -1);
			e.age = atoi(argv[4]); // conversion en entier
			strncpy(e.gender, argv[5], sizeof(e.gender) -1);
			strncpy(e.job, argv[6], sizeof(e.job) -1);
			strncpy(e.phone, argv[7], sizeof(e.phone) -1);

			//inserer dans l'arbre
			racine = insererNoeud(racine, e);

			//sauvegarder dans le fichier CSV
			sauvegarderDansCSV(racine, "user.csv");

			printf("Record inserted: %s %s, %d, %s, %s, %s\n",
				e.name, e.surnam, e.age, e.gender, e.job, e.phone);
			return 0;
		}
		else if (strcmp(argv[1], "search") == 0) {
			if (argc != 4) {
				printf("usage: %s search <criterion> <value>_n", argv[0]);
				return 1;
			}

			const char* critere = argv[2];
			const char* valeur = argv[3];

			printf("Resuls marching %s = %s:\n", critere, valeur);
			rechercherParCritere(racine, critere, valeur);
			return 0;
		} else {
			printf("unknown command. available commands: test, insert, search\n");
			return 1;
		}

	}

// si aucun arg, continuer avec le menu interactif
	int choix;

	do {
		afficherMenu();
		printf("Your choice buddy: ");
		scanf("%d", &choix);

		switch (choix) {
			case 1: {
				Enregistrement e;
				printf("Name: ");scanf("%s", e.name);
				printf("Surname: "); scanf("%s", e.surnam);
				printf("Age: "); scanf("%d", &e.age);
				printf("Gender: "); scanf("%s", e.gender);
				printf("Job: "); scanf("%s", e.job);
				printf("Phone: "); scanf("%s", e.phone);
				racine = insererNoeud(racine, e);
				printf("Record inserted!\n");
				break;
			}
			case 2: {
				char name[50];
				printf("Enter name to delete: ");
				scanf("%s", name);
				racine = supprimerNoeud(racine, name);
				printf("Record deleted!\n");
				break;
			}
			case 3: {
				char name[50];
				printf("Entrer name to update: ");
				scanf("%s", name);
				Enregistrement nouveau;
				printf("New Surname: "); scanf("%s", nouveau.surnam);
				printf("New Age: "); scanf("%d", &nouveau.age);
				printf("New Gender: "); scanf("%s", nouveau.gender);
				printf("New Job: "); scanf("%s", nouveau.job);
				printf("New Phone: "); scanf("%s", nouveau.phone);
				strcpy(nouveau.name, name);
				if (mettreAJourNoeud(racine, name, nouveau)){
					printf("Record updated!\n");
				}else{
					printf("Record not found!!!!!!!!\n");
				}
				break;
			}
			case 4: {
				char name[50];
				printf("Entrer name to search: ");
				scanf("%s", name);
				Noeud* resultat = rechercherNoeud(racine, name);
				if (resultat) {
					printf("Found: %s %s, %d, %s, %s, Phone: %s\n",
						resultat->data.name, resultat->data.surnam,
						resultat->data.age, resultat->data.gender,
						resultat->data.job, resultat->data.phone);
				}else{
					printf("Record no found!!!!!!!\n");
				}
				break;
			}
			case 5:
				afficherArbre(racine);
				break;
			case 6: 
				char critere[20], valeur[50];
				printf("Entrer the search criterion (name, surnam, job, gender): ");
				scanf("%s", critere);
				printf("Entrer the value to search for: ");
				scanf("%s", valeur);

				printf("Resuls matching !!!!!!! %s = %s:\n", critere, valeur);
				rechercherParCritere(racine, critere, valeur);
				break;
			case 7:
				if(racine == NULL) {
					printf("arbre vide.\n");
				}else{
					printf("structure graphique de l'arbre :\n");
					afficherArbreGraphique(racine, 0); // affichage graphique
				}
				break;
			case 0:
				printf("bye bye!!!\n");
				break;
			default:
				printf("invalid choice!!!!!!!!!!!!!\n");
		}
	}while (choix != 0);

	libererArbre(racine);
	return 0;
}

void runTests() {
	printf("Running tst...\n");

	Noeud* racine = NULL;

	construireArbreDepuisCSV(&racine, "test_users.csv");
	
//verification
	assert(rechercherNoeud(racine, "TestUser1") != NULL);
	assert(rechercherNoeud(racine, "TestUser2") != NULL);
	printf("csv loading tests passed!!!!!!!\n");

//insertion
	Enregistrement nouveau = {"TestUser3", "Gamma", 40, "pan", "Scientist", "3333333333"};
	racine = insererNoeud(racine, nouveau);
	assert(rechercherNoeud(racine, "TestUser3") != NULL);
	printf("INsertion tests passed\n");

// supressions
racine = supprimerNoeud(racine, "TestUser2");
assert(rechercherNoeud(racine, "TestUser2") == NULL);
printf("deletion tests passed\n");

// test
	libererArbre(racine);

	printf("All tests passed sucessssssfully !_n");
}
