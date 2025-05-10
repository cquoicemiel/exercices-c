#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * extraire_consonnes(char * mot) {
    int taille = strlen(mot);
    char * consonnes = (char *)malloc((taille + 1) * sizeof(char)); // Allouer de la mémoire pour les consonnes
    int index = 0;

    for (int i = 0; i < taille; i++) {
        char c = tolower(mot[i]); // Convertir en minuscule pour simplifier la vérification
        if ((c >= 'a' && c <= 'z') && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')) {
            consonnes[index++] = mot[i];
        }
    }
    consonnes[index] = '\0'; // Ajouter le caractère de fin de chaîne

    return consonnes;
}
}