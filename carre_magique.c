#include <stdio.h>

void magique(int tab[10][10], int n) {
    int x = 0, y = n / 2;
    int valeur = 1;

    while (valeur <= n * n) {
        tab[x][y] = valeur;
        valeur++;
        int nouvelle_x = (x - 1 + n) % n;
        int nouvelle_y = (y + 1) % n;

        if (tab[nouvelle_x][nouvelle_y] != 0) {
            x++;
        } else {
            x = nouvelle_x;
            y = nouvelle_y;
        }
    }
}

int main() {
    int tab[10][10] = {0};
    int n = 5;
    magique(tab, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", tab[i][j]);
        }
        printf("\n");
    }
    return 0;
}
