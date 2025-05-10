#include <stdio.h>
#include <stdbool.h>

#define N 9

typedef int Grille[N][N];

void afficher_grille(Grille grille) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grille[i][j] == 0) {
                printf("  ");
            } else {
                printf("%d ", grille[i][j]);
            }
        }
        printf("\n");
    }
}



#define N 9

typedef int Grille[N][N];

bool verifier_ligne(Grille grille, int ligne) {
    int chiffres[N] = {0}; // Tableau pour compter les occurrences de chaque chiffre

    for (int j = 0; j < N; j++) {
        int valeur = grille[ligne][j];
        if (valeur >= 1 && valeur <= 9) {
            chiffres[valeur - 1]++; // Incrémente le compteur pour ce chiffre
        }
    }

    // Vérifie si chaque chiffre de 1 à 9 apparaît exactement une fois
    for (int i = 0; i < N; i++) {
        if (chiffres[i] != 1) {
            return false; // Si un chiffre apparaît plus d'une fois ou pas du tout, la ligne est invalide
        }
    }

    return true; // Tous les chiffres de 1 à 9 apparaissent exactement une fois
}


bool verifier_colonne(Grille grille, int colonne) {
    int chiffres[N] = {0}; // Tableau pour compter les occurrences de chaque chiffre

    for (int j = 0; j < N; j++) {
        int valeur = grille[j][colonne];
        if (valeur >= 1 && valeur <= 9) {
            chiffres[valeur - 1]++; // Incrémente le compteur pour ce chiffre
        }
    }

    // Vérifie si chaque chiffre de 1 à 9 apparaît exactement une fois
    for (int i = 0; i < N; i++) {
        if (chiffres[i] != 1) {
            return false; // Si un chiffre apparaît plus d'une fois ou pas du tout, la ligne est invalide
        }
    }

    return true; // Tous les chiffres de 1 à 9 apparaissent exactement une fois
}

int verifier_grille(Grille grille){
    if( verifier_colonne == 1 && verifier_ligne == 1){
        return 1;
    }
    else {
        return 0;
    }

}


