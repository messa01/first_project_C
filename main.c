// main.c - point d'entree du programm
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "db.h" // inclure l'en tete pour les fonctions de bdd

//#define MAX_NAME_LENGTH 100


int main() {

	struct User * users = NULL;

//carhger les users
	int user_count = load_users("users.csv", &users);
	if (user_count < 0) {
		fprintf(stderr, "EROOR CHARGEMENT DEPUIS users.csv\n"); //erreur lors du chargement des users
		return EXIT_FAILURE;
	}


	printf("Nombre d'users charge : %d\n", user_count);

// aficher les users si chargé
	if (user_count > 0) {
		display_users(users, user_count);
	} else {
		printf("aucun userstrouver dans le fichier CSV\n");
	}

	free(users); // libérer la memoire allouée pour les users
	return EXIT_SUCCESS;
	
}
