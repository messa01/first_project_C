//gerer les interractions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd.h"

void afficherMenu() {
	printf("\nMenu :\n");
	printf("1. Insert a record\n");
	printf("2. Delete a record\n");
	printf("3. Update a record\n");
	printf("4. Search for a record\n");
	printf("5. Display all records\n");
//	printf("6. Load records from CSV\n");
	printf("7. Display tree structure (graphical)\n");
	printf("0. Quit\n");
}

int main(int argc, char* argv[]) {
	Noeud* racine = NULL;

	//construire automatiquement l'arbre a partir de user.csv
	construireArbreDepuisCSV(&racine, "user.csv");

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
		//	case 6: {
		//		char chemin[100];
		//		printf("Entrer CSV file path: ");
		//		scanf("%s", chemin);

		//		chargerCSV(&racine, chemin); // charge le csv
		//		break;
		//	}
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
