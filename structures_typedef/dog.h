#ifndef DOG_H
#define DOG_H

/**
* struct dog - Définit les informations de base d'un chien
* @name: Pointeur vers une chaîne de caractères (le nom du chien)
* @age: L'âge du chien (en float)
* @owner: Pointeur vers une chaîne de caractères (le nom du maître)
*
* Description: Une structure simple regroupant les informations
* d'un chien et de son propriétaire.
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Nouvel alias pour la structure struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
