#include <stdio.h>

void hanoi(int n, int depart, int inter, int arrivee) {
    if (n > 0) {
        hanoi(n - 1, depart, arrivee, inter);
        printf("Déplacer disque de la tour %d vers la tour %d\n", depart, arrivee);
        hanoi(n - 1, inter, depart, arrivee);
    }
}

int main() {
    int n;
    printf("Entrez le nombre de disques : ");
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}
