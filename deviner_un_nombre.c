#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hasard(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));
    int nombre_a_deviner = hasard(1, 100);
    int tentative, essais = 0;

    printf("Devinez le nombre (entre 1 et 100) : ");
    while (essais < 50) {
        scanf("%d", &tentative);
        essais++;
        if (tentative == nombre_a_deviner) {
            printf("Félicitations ! Vous avez trouvé le nombre en %d tentatives.\n", essais);
            return 0;
        } else if (tentative < nombre_a_deviner) {
            printf("Plus grand !\n");
        } else {
            printf("Plus petit !\n");
        }
    }
    printf("Vous avez épuisé vos 50 tentatives. Le nombre était %d.\n", nombre_a_deviner);
    return 0;
}
