// main.c - point d'entree du programm
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "db.h" // inclure l'en tete pour les fonctions de bdd

//#define MAX_NAME_LENGTH 100


int main() {

	struct User * users = NULL;
	int user_count = load_users("users.txt", &users);

	if (user_count < 0) {
		return EXIT_FAILURE; //erreur lors du chargement des users
	}

	printf("Nombre d'users charge : %d\n", user_count);
	display_users(users, user_count);

	free(users); // libérer la memoire allouée pour les users
	return EXIT_SUCCESS;



	// appeler les fonctions de db.c quand elles seront pretes
	return 0;
}
