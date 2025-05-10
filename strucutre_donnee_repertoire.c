#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[20] ; 
    char adresse[20]; 
    int age ; 
    char numero[10] ; 
    char email[20] ; 
} contact ; 

#define max_contacts = 300;

contact repertoire[] ; 
void ajout(contact repertoire[]; *taille){
    if (*taille > = max_contact) {
        printf("Le repertoire est plein \n") ;
        return ;
    }
    printf("saisir le nom") ;
    scanf("%s" ; repertoire[*taille].nom );

    printf("saisir l'adresse") ;
    scanf("%s" ; repertoire[*taille].adresse);

    printf("saisir l'age") ;
    scanf("%d" ; &repertoire[*taille].age );

    printf("saisir l'email'") ;
    scanf("%s" ; repertoire[*taille].email );

    (*taille)++;
    printf("contéact ajouté\n");
}

int main(){
    contact repertoire[max_contacts];
    int taille = 0;
    int choix; 
    do {
        printf("1. Ajouter un contact\n");
        printf("3. Supprimer un contact\n");
        printf("2. Quitter\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1 {
                ajout(repertoire , &taille);
                break;
            }
            case 2 {
                printf("Aurevoir");
                break;
            }
            case 3 {
                suppression(repertoire ; *taille);
                break;
            }
            default  : 
                printf("Choix invalide \n");
        }
    }while (choix !=2) ;
    return 0;
}




void suppression(contact repertoir[], *taille ){
    char[20] nom_sup;
    prinf("donner le nom : ");
    scanf("%c", &nom_sup); 
    for(int i ;i< *taille; i++){
        if (strcmp(carnet[i].nom, nom_supp) == 0){
            for (int y = i; y<(taille -1); y++);{
                repetoire[y] = repertoire[y+1];
            } 
        }
        else {
            printf("contact non trouvé");
        }
    }
    printf("la suppression a été faite !");

}



// Définir une structure pour représenter un contact
typedef struct {
    char nom[50];
    char telephone[15];
    char email[50];
} Contact;

// Fonction pour afficher tous les contacts du répertoire
void afficherTousContacts(Contact repertoire[], int taille) {
    printf("Liste de tous les contacts:\n");
    for (int i = 0; i < taille; i++) {
        printf("Nom: %s, Téléphone: %s, Email: %s\n", repertoire[i].nom, repertoire[i].telephone, repertoire[i].email);
    }
}

// Fonction pour afficher toutes les informations sur un contact dont on connaît le nom
void afficherContactParNom(Contact repertoire[], int taille, const char *nom) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(repertoire[i].nom, nom) == 0) {
            printf("Informations sur le contact %s:\n", nom);
            printf("Nom: %s, Téléphone: %s, Email: %s\n", repertoire[i].nom, repertoire[i].telephone, repertoire[i].email);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

// Fonction pour afficher tous les contacts dont le nom commence par une lettre donnée
void afficherContactsParLettre(Contact repertoire[], int taille, char lettre) {
    printf("Contacts dont le nom commence par '%c':\n", lettre);
    for (int i = 0; i < taille; i++) {
        if (repertoire[i].nom[0] == lettre) {
            printf("Nom: %s, Téléphone: %s, Email: %s\n", repertoire[i].nom, repertoire[i].telephone, repertoire[i].email);
        }
    }
}

int main() {
    // Exemple de répertoire avec quelques contacts
    Contact repertoire[] = {
        {"Alice", "0123456789", "alice@example.com"},
        {"Bob", "0987654321", "bob@example.com"},
        {"Charlie", "0147258369", "charlie@example.com"}
    };
    int taille = sizeof(repertoire) / sizeof(repertoire[0]);

    // Afficher tous les contacts
    afficherTousContacts(repertoire, taille);

    // Afficher les informations d'un contact par nom
    afficherContactParNom(repertoire, taille, "Bob");

    // Afficher tous les contacts dont le nom commence par une lettre donnée
    afficherContactsParLettre(repertoire, taille, 'A');

    return 0;
}
