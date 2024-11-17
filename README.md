## **Description du Projet**

Ce projet est une application écrite en C qui permet de gérer une base de données simple d'utilisateurs à l'aide d'un **arbre binaire de recherche** (ABR).  
Les données (nom, prénom, âge, genre, métier, téléphone) sont stockées dans un fichier CSV nommé **`user.csv`**, garantissant la persistance entre les sessions.

Le programme propose à la fois une interface **menu interactif** et des **commandes en ligne de commande** pour gérer les enregistrements.

---
### **1. Compilation**
   make
   
 ### **2. Exécution**
 ## *2.1 Utilisation du Menu interactif*
 .\main
 
 - **Affichage**:
1. Insert a record
2. Delete a record
3. Update a record
4. Search for a record
5. Display all records
6. Advanced search by criterion
7. Display tree structure (graphical)
0. Quit


 ## *2.2 Commandes en Ligne de commande*
 - **Insertion : ./main insert name surnam age gender job phone
 - **Recherche avancée: ./main search criterion value
 - ** Tests automatiques[test insertion, suppression en utilisant test_users.csv]: .\main test

## **Fonctionnalités**

1. **Insertion** : Ajouter un nouvel utilisateur dans l'arbre binaire et le fichier CSV.
2. **Recherche basique** : Rechercher un utilisateur par son nom.
3. **Recherche avancée** : Rechercher par critère (par exemple, métier, genre, etc.).
4. **Mise à jour** : Modifier les informations d'un utilisateur existant.
5. **Suppression** : Supprimer un utilisateur de l'arbre binaire et du fichier CSV.
6. **Affichage graphique** : Afficher l'arbre binaire sous une forme textuelle structurée.
7. **Tests automatiques** : Vérifier le bon fonctionnement des fonctionnalités principales.
8. **Menu interactif** : Utiliser un menu simple pour gérer les enregistrements directement depuis le terminal.

---

## **Structure des Fichiers**

- **`main.c`** : menu interactif, la gestion des commandes,logique principale.
- **`bd.c`** : Implémente les fonctions pour gérer l'arbre binaire (insertion, suppression, recherche, mise à jour) et l'interaction avec le fichier CSV.
- **`bd.h`** : Déclarations des fonctions et des structures de données.
- **`user.csv`** : Fichier CSV contenant les enregistrements utilisateurs.
- **`test_users.csv`** : Fichier CSV dédié aux tests automatiques.
- **`Makefile`** : Automatisation de la compilation.


## **Choix techniques**
**1.Arbre Binaire de Recherche :**
- Simplicité pour organiser et chercher les enregistrements.
- Les données sont triées par name.
  
**2.Fichier CSV :**
- Format léger et facile à manipuler.
- Assure la persistance des données entre les sessions.

- **3.Tests Automatiques :**
- Utilisation d'un fichier CSV séparé (test_users.csv) pour éviter d'altérer les données réelles.

**4.Affichage Graphique :**
- Les indentations représentent la structure hiérarchique de l'arbre.
 
