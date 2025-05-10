
#include <stdio.h>
#include <stdbool.h>

// Exercice 1 - Minimum de trois entiers
int minimum(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Exercice 2 - Quatre types de fonctions
int carre(int x) {
    return x * x;
}

int lireEtCarre() {
    int x;
    printf("Entrez un entier : ");
    scanf("%d", &x);
    return x * x;
}

void afficherCarre(int x) {
    printf("Le carré de %d est %d\n", x, x * x);
}

void lireEtAfficherCarre() {
    int x;
    printf("Entrez un entier : ");
    scanf("%d", &x);
    printf("Le carré de %d est %d\n", x, x * x);
}

// Exercice 3 - Vérifier si trois nombres se suivent
bool sontSuivants(int a, int b, int c) {
    return (b == a + 1) && (c == b + 1);
}

void verifierSuivants() {
    int a, b, c;
    printf("Entrez trois entiers : ");
    scanf("%d %d %d", &a, &b, &c);
    if (sontSuivants(a, b, c)) {
        printf("Les nombres se suivent.\n");
    } else {
        printf("Les nombres ne se suivent pas.\n");
    }
}

// Exercice 4 - Solution d'une équation ax + b = 0
void resoudreEquation(float a, float b) {
    if (a == 0) {
        if (b == 0) {
            printf("L'équation a une infinité de solutions.\n");
        } else {
            printf("L'équation n'a pas de solution.\n");
        }
    } else {
        printf("La solution est x = %.2f\n", -b / a);
    }
}

// Exercice 5 - Switch (calculatrice)
void calculatrice() {
    float a, b;
    int choix;
    printf("Entrez deux nombres : ");
    scanf("%f %f", &a, &b);
    printf("Choisissez une opération :\n");
    printf("1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Résultat : %.2f\n", a + b);
            break;
        case 2:
            printf("Résultat : %.2f\n", a - b);
            break;
        case 3:
            printf("Résultat : %.2f\n", a * b);
            break;
        case 4:
            if (b != 0) {
                printf("Résultat : %.2f\n", a / b);
            } else {
                printf("Erreur : Division par zéro !\n");
            }
            break;
        default:
            printf("Choix invalide.\n");
    }
}

// Exercice 6 - Signe du produit sans multiplication
void signeProduit(float a, float b) {
    if (a == 0 || b == 0) {
        printf("Le produit est nul.\n");
    } else if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        printf("Le produit est positif.\n");
    } else {
        printf("Le produit est négatif.\n");
    }
}


int main() {
    // Tests de certaines fonctions
    printf("Minimum de (3, 1, 2) : %d\n", minimum(3, 1, 2));
    verifierSuivants();
    calculatrice();
    signeProduit(-3, 4);
    return 0;
}



// Exercice 7  - Aires

int aire(int a, int b, int c, int p) {
    return( p(p-a)(p-b)(p-c))
}

// Exercice 8 -Caractères

bool caract( char lettre) {
    switch (lettre)
    {
    case 'a': case 'e': case 'i':case 'o': case 'u': case 'y':
        
        return True;
    
    default:
        return False;
    }
}
// ou bien return(lettre =='a' || lettre == 'e' ..)


// Exercice 9 -Jour de la semaine 


void jour_de_la_selaine(unsigned char k  ){
    switch (k)
    {
        case 1 : printf("Lundi \n") ; break;
        case 2 : printf("Mardi \n") ; break;
        case 3 : printf("Mercredi \n") ; break;
        case 4 : printf("Jeudi \n") ; break;
        case 5 : printf("Vendredi \n") ; break;
        case 6 : printf("Samedi \n") ; break;
        case 7 : printf("Dimanche \n") ; break;
    }
    

}