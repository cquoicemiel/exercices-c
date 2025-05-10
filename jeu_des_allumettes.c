#include <stdio.h>

void afficher_allumettes(int R) {
    for (int i = 0; i < R; i++) {
        printf("|");
    }
    printf("\n");
}

int jouer_tour(int allumettes, int p) {
    int prise;
    do {
        printf("Combien d'allumettes voulez-vous retirer (1 à %d) ? ", p);
        scanf("%d", &prise);
    } while (prise < 1 || prise > p || prise > allumettes);
    return prise;
}

int main() {
    int allumettes = 20; // Nombre initial d'allumettes
    int p = 3; // Nombre maximal d'allumettes retirées par tour
    int tour = 1; // 1 pour joueur humain, 2 pour joueur virtuel

    while (allumettes > 0) {
        afficher_allumettes(allumettes);
        if (tour == 1) {
            allumettes -= jouer_tour(allumettes, p);
        } else {
            // Logique du joueur virtuel ici
        }
        tour = (tour % 2) + 1; // Changer de joueur
    }
    printf("Le joueur %d a gagné !\n", tour);
    return 0;
}
