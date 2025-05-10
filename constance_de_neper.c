#include <stdio.h>

double calculer_e(double epsilon) {
    double terme = 1.0;
    double somme = 1.0;
    int k = 1;

    while (terme > epsilon / 3.0) {
        terme *= 1.0 / k;
        somme += terme;
        k++;
    }
    return somme;
}

int main() {
    double epsilon = 1e-6; // Précision souhaitée
    double e = calculer_e(epsilon);
    printf("Approximation de e : %lf\n", e);
    return 0;
}
