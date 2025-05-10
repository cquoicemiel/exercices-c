#include <stdio.h>

// Fonction analyse qui prend en entrée un tableau de notes et renvoie la plus basse note, la plus haute note et la moyenne
void analyse(float notes[], int n, float *min, float *max, float *moyenne) {
    // Initialiser les valeurs de min et max avec la première note
    *min = notes[0];
    *max = notes[0];
    float somme = 0.0;

    // Parcourir le tableau pour trouver min, max et calculer la somme des notes
    for (int i = 0; i < n; i++) {
        if (notes[i] < *min) {
            *min = notes[i];
        }
        if (notes[i] > *max) {
            *max = notes[i];
        }
        somme += notes[i];
    }

    // Calculer la moyenne
    *moyenne = somme / n;
}

int main() {
    // Exemple de tableau de notes
    float notes[] = {12.5, 15.0, 18.0, 9.5, 14.0, 16.5, 13.0};
    int n = sizeof(notes) / sizeof(notes[0]);

    // Variables pour stocker les résultats
    float min, max, moyenne;

    // Appel de la fonction analyse
    analyse(notes, n, &min, &max, &moyenne);

    // Affichage des résultats
    printf("La plus basse note est : %.2f\n", min);
    printf("La plus haute note est : %.2f\n", max);
    printf("La moyenne de la classe est : %.2f\n", moyenne);

    return 0;
}
