#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 1. Vérifier si l'utilisateur a bien fourni un nom de fichier
    if (argc != 2)
    {
        fprintf(stderr, "Utilisation : %s <chemin_du_fichier>\n", argv[0]);
        return 1;
    }

    // 2. Ouvrir le fichier en mode lecture ("r" pour Read)
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    long count = 0;
    int ch; // Doit être de type 'int' pour détecter correctement EOF (-1)

    // 3. Lire le fichier caractère par caractère jusqu'à la fin (EOF)
    while ((ch = fgetc(file)) != EOF)
    {
        count++;
    }

    // 4. Fermer le fichier
    fclose(file);

    // 5. Afficher le résultat
    printf("Le fichier '%s' contient %ld caractères.\n", argv[1], count);

    return 0;
}
