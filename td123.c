td1 

int minimum(int a , int b , int c ){
    if (a <b && a< c) {
        return a;
    } 
    else {
        if (b< a && b<c ){
            return b;
        }
        else {
            return c;
        }
    }
}

int entier(int a){
    return  a*a;
}

int entier1(void){
    int a  ; 
    scanf("%d", &a) ; 
    return a*a
}

void entier1(int a){
    printf("%d", a*a) ;
}

void entier1(void){
    int a;
    scanf("%d", &a)
    printf("%d", a*a)
}

bool suivre(int a , int b, int c){
    if ((a == b+1)  && (b ==c+1)){
    return True ;
    }
    else {
        return False ;
    }
}


bool sesuivre(void){
    int a, b, c ; 
    scanf("%d %d %d", &a, &b ,&c );
    return suivre( a, b, c) ;
}


int equation(void) {
    int a ,b, c ;
    printf("donner les valeurs");
    scanf("%d %d %d" ,&a, &b, &c )
    if (a==0){
        return 0;
    }
    return (c-b)/a;

}



int calcul(void){
    int a ,b, o;
    scanf("%d %d %d", &a ,&b, &o) ; 
    switch (o) {
        case 1 : return a + b; 
        case 2 : return a-b ;
        case 3 : return a*b ;
        case 4 : if (b != 0) ? return a/b : return 0;
        default : pintf("Operation invalide");
        return 0;
    }
}


void afficher_signe_produit(double a, double b) {
    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        printf("Le signe du produit de %.2f et %.2f est positif.\n", a, b);
    } else if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        printf("Le signe du produit de %.2f et %.2f est négatif.\n", a, b);
    } else {
        printf("Le signe du produit de %.2f et %.2f est zéro.\n", a, b);
    }
}



int factoriel(int n){
    if (n == 0) || (n==1) {
        return 1;
    }
    return n * factoriel(n-1)
}

int fibo(int n){
    if (n == 0) {
        return 0; 
    }
    else {
        if (n ==1){
            return 1; 
        }
        else {
            return fibo(n-1) + fibo(n-2);
        }
    }
}

int pgcd(int a, int b) {
    if (b == 0){
        if (a>0){
            return a
        }
        else {
            return -a
        }
    }
    else {
        return pgcd(b, a%b);
    }
}

void pyramide(int n ){
    if n == 0{
        printf("*********");
    }
    else {
    printf((4 - (5-n))* " " + "*"+ (4 - (5-n))*" "\n); 
    pyramide(int n-1);
    }
}

int divise(int a , int b ){
    if (b == 0) {
        return 0; 
    }
    else {
        if (b == 0) {
            return true;}
        else {
          
        if (b < a ){
            return false ; 
        }
        else {
            return divise(a , a-b);
        }
    }  
    }
}


bool est_premier(int a ){
    if (a == 0) || (a == 1) || (a ==2){
        return true
    }
    else est_premier(sqrt(a) -1)
}


#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Fonction récursive pour vérifier si un entier est premier
bool est_premier_recursif(int n, int diviseur) {
    // Un nombre premier est supérieur à 1
    if (n <= 1) {
        return false;
    }
    // Si le diviseur est supérieur à la racine carrée de n, alors n est premier
    if (diviseur > sqrt(n)) {
        return true;
    }
    // Si n est divisible par le diviseur actuel, alors n n'est pas premier
    if (n % diviseur == 0) {
        return false;
    }
    // Appel récursif avec le diviseur suivant
    return est_premier_recursif(n, diviseur + 1);
}

// Fonction principale pour vérifier si un entier est premier
bool est_premier(int n) {
    return est_premier_recursif(n, 2);
}

int main() {
    int n;
    printf("Saisir un entier : ");
    scanf("%d", &n);

    if (est_premier(n)) {
        printf("%d est un nombre premier.\n", n);
    } else {
        printf("%d n'est pas un nombre premier.\n", n);
    }

    return 0;
}


void remplir(float tableau[], int taille){
    for (int i = 0; i< taille; i++){
        scanf("%f", &tableau[i]) ; 
    }
}


bool egaux(int tableau1[],int taille1, int tableau2[], int taille2 ){
    if (taille != taillle2) {
        return false;  
    }
    else {
        for( int i = 0 ; i < taille; i++){
            if (tableau[i] != tableau2[i]) {
                return false;
            }
        return true;
    
        }
    }
}



int decompte(innt tableau[], int taille, int n ) {
    int nbr ; 
    for (int i = 0; i <= taille; i++) {
        if (tableau[i] == n ) {
            nrd += 1;
        }
    }
    return nrb;

}



void copie(char tableau[], int taille, chat copie[]){
     ; 
    for (int i = 0, i < taille && tableau[i] != "\0", i++){
        copie[i] = tableau[i] ; 
    }
    copie[taille - 1] = '\0';
}



int permuttation(int tableau[] , int taille){
    for (int i = 0, i < (taille /2), i++)
    {
        int temps = taille [i]; 
        tableau [i ] = tableau[taille -1-i];
        tableau[taille - i-1 ] = temps ;

    }
}
typedef struct {
    int numerateur ; 
    int denominateur ; 
}fraction ;
int pgc (int a , int b) {
    if (b == 0){
        return a> 0 ? a : -a ; 
    }
    return pgcd(b, a%b);
}

fraction simplifie(fraction f) {
    int gcd = pdgc(f.numerateur, f.denominateur) ;
    fraction simplified = {f.numerateur /gcd, f.denominateur/gcd} ;
    return simplified;
}

fraction mutlitiplier (fraction f1, fractions f2){
        f1.nominateur *= f2.nominateur;
        f1.denominateur *= f2.denominateur;
        fraction f3 = simplifie(fraction f1);
        return f3;
        
}




typedef struc {
    int degrés_zero ;
    int premie_degres; 
    int second_degres ; 

}polynome ;




typedef struct {
    char nom[50] ; 
    char prenom[40] ; 
    int num_et; 
    float note ; 
}etudiant;

float moyenne( etudiant table[], nbretudiant){
    int somme ;
    for (int i = 0 ; i <= nbretudiant){
        somme += table[i].note;
    }
    return somme / nbretudiant
}

float calculerMoyenne(Etudiant etudiants[], int nombreEtudiants) {
    float somme = 0.0;
    for (int i = 0; i < nombreEtudiants; i++) {
        somme += etudiants[i].note;
    }
    return somme / nombreEtudiants;
}



typedef double Matrice[N][N];
int nombreDeZeros(Matrice mat) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 0.0) {
                count++;
            }
        }
    }
    return count;
}


bool estDiagonale(Matrice mat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && mat[i][j] != 0.0) {
                return false;
            }
        }
    }
    return true;
}
void transpose(Matrice mat) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}


void addition(Matrice mat1, Matrice mat2, Matrice resultat) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}




#include <stdio.h>

void incremente(int* p) {
    if (p != NULL) {
        (*p)++; // Incrémente la valeur pointée
    }
}
void incremente(int* p ){
    if (*p != NULL){
        (*p) ++ ;
    }
}

void echange(int* p1, int* p2){
    int temp ; 
    temp = *p1 ;
    *p1 = *p2;
    *p2 = temp ;
}

void carre(int * p){
    (*p) = (*p) * (*p);
}


void disque(float rayon, float* diametre, float* perimetre, float* surface){
    float pi = 3.14;
    (*diametre) =2* (rayon)  ;
    (*perimetre) = (*diametre) * pi; 
}

void somme_diff(int x, int y, int* somme, int* diff){
    if (somme != NULL){
        (*somme) = x + y ;
    }
    if (diff != NULL) {
        (*diff) = x - y ;
    }
}


int * somme(int* x, int* y) {
    int* som = malloc(sizeof(int));
    if ((x) != NULL && (*) != NULL){
        (*som)= (*x) + (*y)
    }   
}



int * multiplication(int* x, int* y){
    int * mult = malloc(sizeof(int));
    if (mult == NULL) {
        return NULL;
    }
    if (x == NULL || y == NULL){
        return NULL;
    }
    *mult = (*x)*(*y);
    return mult;
}


typedef struct {
    float im;
    float re;
}complexe;

complexe* new_complexe(float r, float i){
    complexe* nv = malloc(sizeof(complexe));
    nv-> re = r;
    nv-> im = i ;
    return nv;
}



void print_complexe(complexe *p){
    if (p->im >= 0) {
    printf("notre complexe : %2f + %2fi", p->re, p->im ) ; 
    }
    else {
        printf("notre nombre complexe %2f - %2fi", p->re, -p->im);
    }
}

complexe * addition_complexe(complexe* c1, complexe* c2){
    complexe* nv = malloc(sizeof(complexe));
    nv->re = c1->re + c2->re ;
    nv->im = c1->im + c2->im ;
    return nv;

}


complexe* produit_complexes(complexe* c1, complexe* c2);{
    complexe* nv = malloc(sizeof(complexe));
    if (n == NULL){
        return NULL ;
    }
    nv->re = c1->re * c2->re ;
    nv->im = c1->im * c2->im ;
    return nv;
}


int* copie_tab (int* tab, int n){
    int * table = malloc(n*sizeof(int));
    for (int i = 0; i <= n; i++){
        table[i] = tab[i] ; 
    }
    return tab;
}


int* cree_tab_carre(int n){
    int * table = malloc(n * sizeof( int));
    if ( table == NULL) {
        return NULL ; 
    }
    for (int i = 0 ; i <= n-1 ; i++){
        table[i] = i*i ; 
    }
    return table;
}


int* concat (int* tab1, int* tab2, int n1, int n2){
    int * tab = malloc((n1 + n2) * sizeof(int));
    for (int i = 0; i < n1 ; i ++){
        tab[i] = tab1 [i] ; 
    }
    for (int i = 0 ; i < (n2) ; i ++){
        tab[n1 + i] = tab2 [i] ; 
    }
    return resultat ;
}


int* sous_tab(int* tab, int taille, int i1, int i2){
    int * sous = malloc((i2 -i1 +1) * sizeof(int));
    if (sous == NULL){
        return NULL; 
    }
    for (int i = 0 ; i < (i2-i1 +1); i++){
        sous[i] = tab[i1+i] ; 

    }
}




int ** init_mat_id(int n){
    int ** mat = malloc(n * sizeof(int*));
    if (mat == NULL) return NULL;

    for (int i  = 0 ; i < n; i++ ){
        mat[i] = malloc(n * saizeof(int));
        if (mat[i] == NULL) return NULL ; 
        for (int j = 0 ; j < n ; j++){
            free(mat[j]) ;
        }
        free(mat) ;
        return NULL;

        for(int j = 0; j < n , j ++){
            mat[i][j] = if 
    }
    }
    


}


int ** transpose(int ** mat, int n) {
    // Exercice 6
int ** transpose(int ** mat, int n) {
    int ** t = init_mat_id(n) ; // pour construire la matrice, mais on s'en blc des valeurs, on veut juste l'espace mémoire

    for(int l = 1 ; l <= n ; ++l) {
        for (int c = 1 ; c <= n ; ++c) {
            t[l][c] = mat[c][l] ;
        }
    }
    return t ;
}

