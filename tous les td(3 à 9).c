#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>


void remplir_tableau(float tab[], int taille) {
    printf("Entrez %d valeurs pour le tableau :\n", taille);
    for (int i = 0; i < taille; i++) {
        scanf("%f", &tab[i]);
    }
}


bool tableaux_egaux(int tab1[], int tab2[], int taille) {
    for (int i = 0; i < taille; i++) {
        if (tab1[i] != tab2[i]) {
            return false;
        }
    }
    return true;
}


int compte_occurrences(int tab[], int taille, int element) {
    int compteur = 0;
    for (int i = 0; i < taille; i++) {
        if (tab[i] == element) {
            compteur++;
        }
    }
    return compteur;
}


int maximum(int tab[], int taille) {
    int max = tab[0];
    for (int i = 1; i < taille; i++) {
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
}

int indiceDuMaximum(int tab[], int taille) {
    int max = tab[0];
    int indice = 0;
    for (int i = 1; i < taille; i++) {
        if (tab[i] > max) {
            max = tab[i];
            indice = i;
        }
    }
    return indice;
}



void copie_tableau(char src[], char dest[], int taille) {
    for (int i = 0; i < taille; i++) {
        dest[i] = src[i];
    }
}




void permutation_circulaire(int tab[], int taille) {
    int dernier = tab[taille - 1];
    for (int i = taille - 1; i > 0; i--) {
        tab[i] = tab[i - 1];
    }
    tab[0] = dernier;
}



void renverse_tableau(int tab[], int taille) {
    int debut = 0;
    int fin = taille - 1;
    while (debut < fin) {
        int temp = tab[debut];
        tab[debut] = tab[fin];
        tab[fin] = temp;
        debut++;
        fin--;
    }
}



#include <stdbool.h>
#include <string.h>

bool est_palindrome(char mot[]) {
    int debut = 0;
    int fin = strlen(mot) - 1;
    while (debut < fin) {
        if (mot[debut] != mot[fin]) {
            return false;
        }
        debut++;
        fin--;
    }
    return true;
}




void majuscules(char chaine[]) {
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (islower(chaine[i])) {
            chaine[i] = toupper(chaine[i]);
        }
    }
}



void supprime_element(float tab[], int taille, int indice) {
    for (int i = indice; i < taille - 1; i++) {
        tab[i] = tab[i + 1];
    }
}




bool caractere_present(char chaine[], char caractere) {
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] == caractere) {
            return true;
        }
    }
    return false;
}

bool toutes_lettres_presentes(char mot1[], char mot2[]) {
    for (int i = 0; mot1[i] != '\0'; i++) {
        if (!caractere_present(mot2, mot1[i])) {
            return false;
        }
    }
    return true;
}

void efface_voyelles(char mot[]) {
    int j = 0;
    for (int i = 0; mot[i] != '\0'; i++) {
        if (mot[i] != 'a' && mot[i] != 'e' && mot[i] != 'i' && mot[i] != 'o' && mot[i] != 'u' &&
            mot[i] != 'A' && mot[i] != 'E' && mot[i] != 'I' && mot[i] != 'O' && mot[i] != 'U') {
            mot[j++] = mot[i];
        }
    }
    mot[j] = '\0';
}



void insere_element(float tab[], int taille, int indice, float valeur) {
    for (int i = taille; i > indice; i--) {
        tab[i] = tab[i - 1];
    }
    tab[indice] = valeur;
}



bool recherche_dichotomique(int tab[], int taille, int x) {
    int debut = 0;
    int fin = taille - 1;
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        if (tab[milieu] == x) {
            return true;
        } else if (tab[milieu] < x) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    return false;
}



#include <stdio.h>

typedef struct {
    int numerateur;
    int denominateur;
} Fraction;

int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction simplifie(Fraction f) {
    int diviseur = pgcd(f.numerateur, f.denominateur);
    f.numerateur /= diviseur;
    f.denominateur /= diviseur;
    return f;
}

Fraction multiplication(Fraction f1, Fraction f2) {
    Fraction resultat;
    resultat.numerateur = f1.numerateur * f2.numerateur;
    resultat.denominateur = f1.denominateur * f2.denominateur;
    return simplifie(resultat);
}

Fraction addition(Fraction f1, Fraction f2) {
    Fraction resultat;
    resultat.numerateur = f1.numerateur * f2.denominateur + f2.numerateur * f1.denominateur;
    resultat.denominateur = f1.denominateur * f2.denominateur;
    return simplifie(resultat);
}




typedef struct {
    int degre;
    int* coefficients;
} Polynome;

Polynome derivee(Polynome p) {
    if (p.degre == 0) {
        Polynome resultat = {0, NULL};
        return resultat;
    }
    Polynome resultat;
    resultat.degre = p.degre - 1;
    resultat.coefficients = (int*)malloc((resultat.degre + 1) * sizeof(int));
    for (int i = 0; i <= resultat.degre; i++) {
        resultat.coefficients[i] = p.coefficients[i + 1] * (i + 1);
    }
    return resultat;
}





typedef struct {
    char nom[50];
    char prenom[50];
    int numero_etudiant;
    float note;
} Etudiant;

float moyenne_classe(Etudiant tab[], int taille) {
    float somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tab[i].note;
    }
    return somme / taille;
}

void meilleur_etudiant(Etudiant tab[], int taille) {
    int meilleur_indice = 0;
    for (int i = 1; i < taille; i++) {
        if (tab[i].note > tab[meilleur_indice].note) {
            meilleur_indice = i;
        }
    }
    printf("Meilleur étudiant : %s %s\n", tab[meilleur_indice].prenom, tab[meilleur_indice].nom);
}







typedef float Matrice[100][100];

int nombreDeZeros(Matrice mat, int n) {
    int compteur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                compteur++;
            }
        }
    }
    return compteur;
}

bool estDiagonale(Matrice mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && mat[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool estSymetrique(Matrice mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void transpose(Matrice mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void addition(Matrice mat1, Matrice mat2, Matrice resultat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplication(Matrice mat1, Matrice mat2, Matrice resultat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}





void incremente(int* p) {
    (*p)++;
}



void echange(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}



void carre(int* x) {
    *x = (*x) * (*x);
}





void disque(float rayon, float* diametre, float* perimetre, float* surface) {
    *diametre = 2 * rayon;
    *perimetre = 2 * M_PI * rayon;
    *surface = M_PI * rayon * rayon;
}




void somme_diff(int x, int y, int* somme, int* diff) {
    *somme = x + y;
    *diff = x - y;
}






int* somme(int* x, int* y) {
    int* resultat = (int*)malloc(sizeof(int));
    *resultat = *x + *y;
    return resultat;
}

int* produit(int x, int y) {
    int* resultat = (int*)malloc(sizeof(int));
    *resultat = x * y;
    return resultat;
}







typedef struct {
    float re;
    float im;
} Complexe;

Complexe* new_complexe(float r, float i) {
    Complexe* c = (Complexe*)malloc(sizeof(Complexe));
    c->re = r;
    c->im = i;
    return c;
}

void print_complexe(Complexe* p) {
    printf("%.2f + %.2fi\n", p->re, p->im);
}

Complexe* addition_complexes(Complexe* c1, Complexe* c2) {
    Complexe* resultat = (Complexe*)malloc(sizeof(Complexe));
    resultat->re = c1->re + c2->re;
    resultat->im = c1->im + c2->im;
    return resultat;
}

Complexe* produit_complexes(Complexe* c1, Complexe* c2) {
    Complexe* resultat = (Complexe*)malloc(sizeof(Complexe));
    resultat->re = c1->re * c2->re - c1->im * c2->im;
    resultat->im = c1->re * c2->im + c1->im * c2->re;
    return resultat;
}





int* copie_tab(int* tab, int n) {
    int* nouvelle_zone = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nouvelle_zone[i] = tab[i];
    }
    return nouvelle_zone;
}






int* cree_tab_carre(int n) {
    int* tab = (int*)malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; i++) {
        tab[i] = (i + 1) * (i + 1);
    }
    return tab;
}






int* concat(int* tab1, int* tab2, int n1, int n2) {
    int* resultat = (int*)malloc((n1 + n2) * sizeof(int));
    for (int i = 0; i < n1; i++) {
        resultat[i] = tab1[i];
    }
    for (int i = 0; i < n2; i++) {
        resultat[n1 + i] = tab2[i];
    }
    return resultat;
}









int* sous_tab(int* tab, int taille, int i1, int i2) {
    int* resultat = (int*)malloc((i2 - i1 + 1) * sizeof(int));
    for (int i = i1; i <= i2; i++) {
        resultat[i - i1] = tab[i];
    }
    return resultat;
}





int** init_mat_id(int n) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            mat[i][j] = (i == j) ? 1 : 0;
        }
    }
    return mat;
}





int** transpose(int** mat, int n) {
    int** resultat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        resultat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            resultat[i][j] = mat[j][i];
        }
    }
    return resultat;
}











int** somme(int** mat1, int** mat2, int n) {
    int** resultat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        resultat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            resultat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return resultat;
}














typedef struct {
    int degre;
    int* coefficients;
} Polynome;

Polynome* new_polynome(int n) {
    Polynome* p = (Polynome*)malloc(sizeof(Polynome));
    p->degre = n;
    p->coefficients = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        p->coefficients[i] = 1;
    }
    return p;
}

void print_polynome(Polynome* p) {
    for (int i = p->degre; i >= 0; i--) {
        printf("%dx^%d ", p->coefficients[i], i);
    }
    printf("\n");
}

Polynome* addition_polynomes(Polynome* p1, Polynome* p2) {
    int degre_max = (p1->degre > p2->degre) ? p1->degre : p2->degre;
    Polynome* resultat = (Polynome*)malloc(sizeof(Polynome));
    resultat->degre = degre_max;
    resultat->coefficients = (int*)malloc((degre_max + 1) * sizeof(int));
    for (int i = 0; i <= degre_max; i++) {
        resultat->coefficients[i] = (i <= p1->degre) ? p1->coefficients[i] : 0;
        resultat->coefficients[i] += (i <= p2->degre) ? p2->coefficients[i] : 0;
    }
    return resultat;
}








typedef struct {
    float re;
    float im;
} Complexe;

typedef struct {
    int degre;
    Complexe** coefficients;
} PolynomeComplexe;

PolynomeComplexe* new_poly_c(int n) {
    PolynomeComplexe* p = (PolynomeComplexe*)malloc(sizeof(PolynomeComplexe));
    p->degre = n;
    p->coefficients = (Complexe**)malloc((n + 1) * sizeof(Complexe*));
    for (int i = 0; i <= n; i++) {
        p->coefficients[i] = (Complexe*)malloc(sizeof(Complexe));
        p->coefficients[i]->re = 1;
        p->coefficients[i]->im = 1;
    }
    return p;
}

void print_poly_c(PolynomeComplexe* p) {
    for (int i = p->degre; i >= 0; i--) {
        printf("(%f + %fi)x^%d ", p->coefficients[i]->re, p->coefficients[i]->im, i);
    }
    printf("\n");
}






Client* anniversaire(BaseClient base, int mois) {
    int compteur = 0;
    for (int i = 0; i < base.taille; i++) {
        if (base.clients[i].mois_naissance == mois && base.clients[i].carte_fidelite) {
            compteur++;
        }
    }
    Client* resultat = (Client*)malloc(compteur * sizeof(Client));
    int index = 0;
    for (int i = 0; i < base.taille; i++) {
        if (base.clients[i].mois_naissance == mois && base.clients[i].carte_fidelite) {
            resultat[index++] = base.clients[i];
        }
    }
    return resultat;
}


void plusAncienClient(BaseEnseigne base) {
    int annee_min = 9999;
    for (int i = 0; i < base.nombre_magasins; i++) {
        for (int j = 0; j < base.bases[i].taille; j++) {
            if (base.bases[i].clients[j].annee_premier_achat < annee_min) {
                annee_min = base.bases[i].clients[j].annee_premier_achat;
            }
        }
    }
    printf("Année du premier achat du plus ancien client : %d\n", annee_min);
}











typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

typedef Element* liste;

liste liste_vide() {
    return NULL;
}

int tete(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        exit(1);
    }
    return l->valeur;
}

liste corps(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        exit(1);
    }
    return l->suivant;
}

int der_elt(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        exit(1);
    }
    while (l->suivant != NULL) {
        l = l->suivant;
    }
    return l->valeur;
}

liste ajout_debut(liste l, int e) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->valeur = e;
    nouveau->suivant = l;
    return nouveau;
}

liste ajout_fin(liste l, int e) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->valeur = e;
    nouveau->suivant = NULL;
    if (l == NULL) {
        return nouveau;
    }
    Element* temp = l;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveau;
    return l;
}

liste suppr_debut(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        exit(1);
    }
    Element* temp = l;
    l = l->suivant;
    free(temp);
    return l;
}

liste suppr_fin(liste l) {
    if (l == NULL) {
        printf("Liste vide\n");
        exit(1);
    }
    if (l->suivant == NULL) {
        free(l);
        return NULL;
    }
    Element* temp = l;
    while (temp->suivant->suivant != NULL) {
        temp = temp->suivant;
    }
    free(temp->suivant);
    temp->suivant = NULL;
    return l;
}

int nb_elem(liste l) {
    int compteur = 0;
    while (l != NULL) {
        compteur++;
        l = l->suivant;
    }
    return compteur;
}

int element(liste l, int i) {
    int compteur = 0;
    while (l != NULL) {
        if (compteur == i) {
            return l->valeur;
        }
        compteur++;
        l = l->suivant;
    }
    printf("Indice hors limites\n");
    exit(1);
}

liste ajout(liste l, int e, int i) {
    if (i == 0) {
        return ajout_debut(l, e);
    }
    Element* nouveau = (Element*)malloc(sizeof(Element));
    nouveau->valeur = e;
    Element* temp = l;
    for (int j = 0; j < i - 1; j++) {
        if (temp == NULL) {
            printf("Indice hors limites\n");
            exit(1);
        }
        temp = temp->suivant;
    }
    nouveau->suivant = temp->suivant;
    temp->suivant = nouveau;
    return l;
}

liste suppr(liste l, int i) {
    if (i == 0) {
        return suppr_debut(l);
    }
    Element* temp = l;
    for (int j = 0; j < i - 1; j++) {
        if (temp == NULL) {
            printf("Indice hors limites\n");
            exit(1);
        }
        temp = temp->suivant;
    }
    if (temp->suivant == NULL) {
        printf("Indice hors limites\n");
        exit(1);
    }
    Element* a_supprimer = temp->suivant;
    temp->suivant = a_supprimer->suivant;
    free(a_supprimer);
    return l;
}







typedef struct {
    char nom[50];
    char prenom[50];
    int annee_naissance;
} Acteur;

typedef struct {
    char nom[50];
    char prenom[50];
    int annee_naissance;
} Realisateur;

typedef struct {
    char titre[100];
    int annee_sortie;
    Realisateur* realisateur;
    Acteur** acteurs;
    int nombre_acteurs;
} Film;

typedef struct ElementVOD {
    Film* film;
    struct ElementVOD* suivant;
} ElementVOD;

typedef ElementVOD* vOD;


vOD ajoute_film(vOD base, Film* film) {
    ElementVOD* nouveau = (ElementVOD*)malloc(sizeof(ElementVOD));
    nouveau->film = film;
    nouveau->suivant = base;
    return nouveau;
}


void detruit_base(vOD base) {
    while (base != NULL) {
        ElementVOD* temp = base;
        base = base->suivant;
        free(temp->film->realisateur);
        free(temp->film->acteurs);
        free(temp->film);
        free(temp);
    }
}


void affiche_film(Film* film) {
    printf("Titre : %s\n", film->titre);
    printf("Année de sortie : %d\n", film->annee_sortie);
    printf("Réalisateur : %s %s\n", film->realisateur->prenom, film->realisateur->nom);
    printf("Acteurs :\n");
    for (int i = 0; i < film->nombre_acteurs; i++) {
        printf(" - %s %s\n", film->acteurs[i].prenom, film->acteurs[i].nom);
    }
}


void affiche_base(vOD base) {
    while (base != NULL) {
        affiche_film(base->film);
        base = base->suivant;
    }
}


char* plus_vieux_film(vOD base) {
    if (base == NULL) {
        return NULL;
    }
    Film* plus_vieux = base->film;
    vOD temp = base;
    while (temp != NULL) {
        if (temp->film->annee_sortie < plus_vieux->annee_sortie) {
            plus_vieux = temp->film;
        }
        temp = temp->suivant;
    }
    return plus_vieux->titre;
}



void acteurs_annee(vOD base, int annee) {
    while (base != NULL) {
        if (base->film->annee_sortie == annee) {
            for (int i = 0; i < base->film->nombre_acteurs; i++) {
                printf("%s %s\n", base->film->acteurs[i].prenom, base->film->acteurs[i].nom);
            }
        }
        base = base->suivant;
    }
}



vOD films_acteur(vOD base, Acteur* acteur) {
    vOD nouvelle_base = NULL;
    while (base != NULL) {
        for (int i = 0; i < base->film->nombre_acteurs; i++) {
            if (base->film->acteurs[i].nom == acteur->nom && base->film->acteurs[i].prenom == acteur->prenom) {
                nouvelle_base = ajoute_film(nouvelle_base, base->film);
                break;
            }
        }
        base = base->suivant;
    }
    return nouvelle_base;
}
















#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char nom[50];
    int heure;
    int minutes;
    int numero_table;
    bool addition_payee;
} ReservationData;

typedef struct ElementReservation {
    ReservationData data;
    struct ElementReservation* suivant;
} ElementReservation;

typedef ElementReservation* ReservationList;



ReservationList ajout_fin_liste(ReservationList l, ReservationData data) {
    ElementReservation* nouveau = (ElementReservation*)malloc(sizeof(ElementReservation));
    nouveau->data = data;
    nouveau->suivant = NULL;
    if (l == NULL) {
        return nouveau;
    }
    ElementReservation* temp = l;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveau;
    return l;
}


void affiche_liste(ReservationList l) {
    while (l != NULL) {
        printf("%s %dh%dm - Table %d\n", l->data.nom, l->data.heure, l->data.minutes, l->data.numero_table);
        l = l->suivant;
    }
}



ReservationData trouve_le_plus_tot_liste(ReservationList l) {
    if (l == NULL) {
        ReservationData vide = {"", 0, 0, 0, false};
        return vide;
    }
    ReservationData plus_tot = l->data;
    while (l != NULL) {
        if (l->data.heure < plus_tot.heure || (l->data.heure == plus_tot.heure && l->data.minutes < plus_tot.minutes)) {
            plus_tot = l->data;
        }
        l = l->suivant;
    }
    return plus_tot;
}



ReservationList nettoie_liste(ReservationList l) {
    if (l == NULL) {
        return NULL;
    }
    if (l->suivant == NULL) {
        if (l->data.addition_payee) {
            free(l);
            return NULL;
        } else {
            return l;
        }
    }
    ElementReservation* temp = l;
    while (temp->suivant != NULL) {
        if (temp->suivant->data.addition_payee) {
            ElementReservation* a_supprimer = temp->suivant;
            temp->suivant = a_supprimer->suivant;
            free(a_supprimer);
        } else {
            temp = temp->suivant;
        }
    }
    if (l->data.addition_payee) {
        free(l);
        return NULL;
    }
    return l;
}


void libere_liste(ReservationList l) {
    while (l != NULL) {
        ElementReservation* temp = l;
        l = l->suivant;
        free(temp);
    }
}
