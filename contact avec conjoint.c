typedef struct {
    char nom[50];
    char prenom[50];
    char sexe; // 'M' ou 'F'
    char telephone_fixe[15];
    char telephone_portable[15];
    struct contact *conjoint; // Pointeur vers le conjoint
} Contact;


void afficher_contact(Contact c) {
    printf("Nom: %s\n", c.nom);
    printf("Prénom: %s\n", c.prenom);
    printf("Sexe: %c\n", c.sexe);
    printf("Téléphone fixe: %s\n", c.telephone_fixe);
    printf("Téléphone portable: %s\n", c.telephone_portable);
    if (c.conjoint != NULL)
        printf("Conjoint: %s %s\n", c.conjoint->prenom, c.conjoint->nom);
    else
        printf("Conjoint: Non renseigné\n");
}



Contact creer_contact() {
    Contact nouveau;
    printf("Nom: ");
    scanf("%s", nouveau.nom);
    printf("Prénom: ");
    scanf("%s", nouveau.prenom);
    printf("Sexe (M/F): ");
    scanf(" %c", &nouveau.sexe);
    printf("Téléphone fixe: ");
    scanf("%s", nouveau.telephone_fixe);
    printf("Téléphone portable: ");
    scanf("%s", nouveau.telephone_portable);
    nouveau.conjoint = NULL; // Le conjoint sera ajouté plus tard
    return nouveau;
}




void ajouter_contact(Contact carnet[], int *taille, Contact nouveau) {
    carnet[*taille] = nouveau;
    (*taille)++;
}




void afficher_contacts_par_prefixe(Contact carnet[], int taille, char *prefixe) {
    for (int i = 0; i < taille; i++) {
        if (strncmp(carnet[i].nom, prefixe, strlen(prefixe)) == 0) {
            afficher_contact(carnet[i]);
            printf("\n");
        }
    }
}



Contact *rechercher_contact(Contact carnet[], int taille, char *nom) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(carnet[i].nom, nom) == 0 ||
            (carnet[i].conjoint != NULL && strcmp(carnet[i].conjoint->nom, nom) == 0)) {
            return &carnet[i];
        }
    }
    return NULL;
}
