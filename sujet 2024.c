
typedef struct {
    int code;
    char nom[20];
    char prenom [20] ; 
    Score score;
}Athlete;

typedef struct{
    int distance ;
    int temps ; 
    bool termine ;  
}Score ;


void ajouter(Athlete participants[]; *taille) {
    #include <stdio.h>
    #include <string.h>
    
    // Assurez-vous que les structures Athlete et Score sont définies avant cette fonction
    typedef struct {
        int distance;
        int temps;
        int termine; // Utiliser int pour booléen (0 pour faux, 1 pour vrai)
    } Score;
    
    typedef struct {
        int id;
        char nom[50];
        char prenom[50];
        Score score;
    } Athlete;
    
void ajouter(Athlete participants[], int *taille) {
    printf("Donner le nom : ");
    scanf("%s", participants[*taille].nom);
    
    printf("Donner le prenom : ");
    scanf("%s", participants[*taille].prenom);
    
    printf("Donner la distance (42 pour marathon, 21 pour semi-marathon) : ");
    scanf("%d", &participants[*taille].score.distance);
    
    printf("Donner le temps (en secondes) : ");
    scanf("%d", &participants[*taille].score.temps);
    
    printf("La course a-t-elle été terminée ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &participants[*taille].score.termine);
    
    participants[*taille].id = *taille + 1; // Le code identifiant est donné automatiquement
    (*taille)++;
}
    

void affichage(Athlete participants[], *taille){
    for (int i =0 ; i < taille; i++){
        printf("Nom : %s\n"; participants[i].nom);
        
        printf("Prenom : %s\n"; participants[i].prenom);
        
        printf("Age : %d\n"; participants[i].age);
        
        printf("Score: %d\n\n"; participants[i].score);
    }
}



void nb_par_course(const Athlete participants[], int taille) {
    int marathon = 0;
    int semi_marathon = 0;

    for (int i = 0; i < taille; i++) {
        if (participants[i].score.distance == 42) {
            marathon++;
        } else if (participants[i].score.distance == 21) {
            semi_marathon++;
        }
    }

    printf("Nombre de participants au marathon: %d\n", marathon);
    printf("Nombre de participants au semi-marathon: %d\n", semi_marathon);
}


void supprimer_non_finisher(Athlete participants[], int *taille) {
    int j = 0;
    for (int i = 0; i < *taille; i++) {
        if (participants[i].score.termine) {
            participants[j++] = participants[i];
        }
    }
    *nb_participants = j;
}

void extraire_finisher_mara(const Athlete participants[], int nb_participants, Athlete finishers[], int *k) {
    *k = 0;
    for (int i = 0; i < nb_participants; i++) {
        if (participants[i].score.distance == 42 && participants[i].score.termine) {
            finishers[*k] = participants[i];
            (*k)++;
        }
    }
}


//) ecrire une fonction extraire_finisher_mara qui permet de remplir le tableau finishers
//avec des athletes qui ont termine le . Le quatrieme argument (k) servira a memoriser la
//taille du tableau finishers.
void affiche_merite_mara(Athlete finishers[], int k) {
    // Tri des finishers par ordre croissant de temps
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (finishers[j].score.temps > finishers[j + 1].score.temps) {
                Athlete temp = finishers[j];
                finishers[j] = finishers[j + 1];
                finishers[j + 1] = temp;
            }
        }
    }

    // Affichage des finishers triés
    for (int i = 0; i < k; i++) {
        printf("ID: %d, Nom: %s, Prénom: %s, Temps: %d\n",
               finishers[i].id, finishers[i].nom, finishers[i].prenom, finishers[i].score.temps);
    }
}


// Fonction principale :

int main()
{                                     
    // déclaration du tableau participants
    Athlete participants[11];

    // nombre initial de participants : 0
    int n = 0;
    
    // ajout des athlètes
    Score s1 = {42, 9634, 1};
    n = ajoute(participants, n, "Johansson", "Thure", s1);
    Score s2 = {21, 3944, 1};
    n = ajoute(participants, n, "Hill", "Ron", s2) ;
    Score s3 = {21, 3826, 1};
    n = ajoute(participants, n, "Reveyn", "Jose", s3) ;
    Score s4 = {42, 8804, 1};
    n = ajoute(participants, n, "Ikenaka", "Yasuo", s4);
    Score s5 = {42, 11845, 0};
    n = ajoute(participants, n, "Wales", "Bob", s5) ;
    Score s6 = {42, 7632, 1};
    n = ajoute(participants, n, "Lopes", "Carlos", s6) ;
    Score s7 = {21, 3451, 1};
    n = ajoute(participants, n, "Kiplimo", "Jacob", s7) ;
    Score s8 = {21, 3587, 1};
    n = ajoute(participants, n, "Tanui", "Moses", s8) ;
    Score s9 = {42, 10823, 0};
    n = ajoute(participants, n, "Wiley", "Frank", s9) ;
    Score s10 = {21, 3535, 1};
    n = ajoute(participants, n, "Gebrselassie", "Haile", s10);
    Score s11 = {42, 10126, 0};
    n = ajoute(participants, n, "Wilson", "John", s11);

    // affichage des athlètes
    printf("*-------- LISTE INITIALE ----------*\n");
    affichage(participants, n) ; 
  
    // calcul des athlètes participants à chaque course
    printf("*------- NB ATHLETES PAR COURSE -----------*\n");
    nb_par_course( participants, n ) ;
    
    // suppression des athlètes qui n’ont pas terminé la course
    n = supprimer_non_finisher(participants , n) ;
    printf("*--------- ATHLETES AYANT TERMINE ---------*\n");
    affichage(participants, n) ; 
   
    // création du tableau contenant les athlètes participant à la course de 3000
    int k;
    Athlete finishers[11];
    extraire_finisher_mara(participants, n, finishers, &k);
    printf("*-------- ATHLETES AYANT TERMINE LE MARATHON ----------*\n");
    affichage(finishers, k);

    printf("*-------- PAR ORDRE DE MERITE ----------*\n");
    //  tri et affichage des informations  des athlètes qui ont terminé la  course 3000 mètres
    affiche_merite_mara(finishers, k);
    

    return 0 ;
}


