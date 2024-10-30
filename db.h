#ifndef DB_H
#define DB_H

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_GENDER_LENGTH 15
#define MAX_CITY_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_JOB_TITLE_LENGTH 50
#define MAX_DATE_LENGTH 11 // format YYYY-MM-DD

// ce fichier contient les déclaration pour la gestion de la bdd

//structure pour un user
struct User{
	char name[MAX_NAME_LENGTH];
	char surname[MAX_NAME_LENGTH];
	char phone[MAX_PHONE_LENGTH];
	char gender[MAX_GENDER_LENGTH];
	char city[MAX_CITY_LENGTH];
	char date_of_birth[MAX_DATE_LENGTH];
	char email[MAX_EMAIL_LENGTH];
	char job_title[MAX_JOB_TITLE_LENGTH];

};

// fonction pour charger les suers depuis un fichier
int load_users(const char *filename, struct User **users);

//fonction pour afficher les utilisateurs
void display_users(struct User *users, int count);


#endif // DB_H
