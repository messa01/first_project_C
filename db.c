
// db.c - fonction pour gérer la bdd
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

#define MAX_USERS 100 // Ajuste la taille max des users selon besoin
//implémenter les fonctions de gestion de bdd ici

//fonction pour charger les users depuis un fichier


int load_users(const char *filename, struct User **users) {
	FILE *file = fopen(filename, "r");
	if (!file) {
		perror("Failed to open file");
		return -1;
	}

	//int count = 0;
	*users = malloc(sizeof(struct User) * MAX_USERS); //allouer la mémoire pour 100 utilisateurs
	if (!*users) {
		perror("Failed to allocate memory");
		fclose(file);
		return -1;
	}
	
	int count = 0;
	
	while (fscanf(file, "49%[^,],%49[^,],%19[^,],%14[^,],%49[^,],%10[^,],%99[^,],%49[^\n]\n",
			(*users)[count].name,
			(*users)[count].surname,
			(*users)[count].phone,
			(*users)[count].gender,
			(*users)[count].city,
			(*users)[count].date_of_birth,
			(*users)[count].email,
			(*users)[count].job_title) == 8) {

		printf("users chargé : %s %s\n",(*users)[count].name, (*users)[count].surname);
		count++;

		if (count >= MAX_USERS) {
			break;
		}

	}

	fclose(file);
	return count; // retrouner le nb d'user charger

}


// fonction pour afficher les users
void display_users(struct User *users, int count) {
	for (int i = 0; i < count; i++) {
	printf("Name: %s %s, Phone: %s, Gender: %s, Ville: %s, Birth: %s, Email: %s, Job: %s\n",
		users[i].name,
		users[i].surname,
		users[i].phone,
		users[i].gender,
		users[i].city,
		users[i].date_of_birth,
		users[i].email,
		users[i].job_title);
	}

}

