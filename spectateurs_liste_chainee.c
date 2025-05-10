#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des structures
typedef struct {
    char nom[50];
    int siege;
    int jourconcert;
    int moisconcert;
    int cbok;
} Spectateur;

typedef struct SpecList {
    Spectateur *spectateur;
    struct SpecList *suivant;
} SpecList;

// Déclaration des fonctions
void ajout_spec(SpecList **liste, Spectateur *spectateur);
void libere_speclist(SpecList *liste);
void affiche_spec(SpecList *liste);
Spectateur* trouve_meilleur(SpecList *liste);
void suppr_err_CB(SpecList **liste);

// Implémentation des fonctions
void ajout_spec(SpecList **liste, Spectateur *spectateur) {
    SpecList *nouveau = (SpecList *)malloc(sizeof(SpecList));
    nouveau->spectateur = spectateur;
    nouveau->suivant = NULL;

    if (*liste == NULL) {
        *liste = nouveau;
    } else {
        SpecList *temp = *liste;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau;
    }
}

void libere_speclist(SpecList *liste) {
    SpecList *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp->spectateur);
        free(temp);
    }
}

void affiche_spec(SpecList *liste) {
    while (liste != NULL) {
        printf("%s : siège n. %d pour le %d/%d\n",
               liste->spectateur->nom,
               liste->spectateur->siege,
               liste->spectateur->jourconcert,
               liste->spectateur->moisconcert);
        liste = liste->suivant;
    }
}

Spectateur* trouve_meilleur(SpecList *liste) {
    if (liste == NULL) {
        return NULL;
    }

    Spectateur *meilleur = liste->spectateur;
    liste = liste->suivant;

    while (liste != NULL) {
        if (liste->spectateur->siege < meilleur->siege) {
            meilleur = liste->spectateur;
        }
        liste = liste->suivant;
    }

    return meilleur;
}

void suppr_err_CB(SpecList **liste) {
    SpecList *courant = *liste;
    SpecList *precedent = NULL;

    while (courant != NULL) {
        if (!courant->spectateur->cbok) {
            if (precedent == NULL) {
                *liste = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            free(courant->spectateur);
            free(courant);
        } else {
            precedent = courant;
        }
        courant = precedent ? precedent->suivant : *liste;
    }
}
int main() {
    printf("Début du programme\n");

    // Initialisation de la liste
    SpecList *liste = NULL;
    printf("Liste initialisée\n");

    // Création de quelques spectateurs
    Spectateur *s1 = (Spectateur *)malloc(sizeof(Spectateur));
    strcpy(s1->nom, "Alice");
    s1->siege = 5;
    s1->jourconcert = 15;
    s1->moisconcert = 5;
    s1->cbok = 1;
    printf("Spectateur Alice créé\n");

    Spectateur *s2 = (Spectateur *)malloc(sizeof(Spectateur));
    strcpy(s2->nom, "Bob");
    s2->siege = 3;
    s2->jourconcert = 15;
    s2->moisconcert = 5;
    s2->cbok = 0;
    printf("Spectateur Bob créé\n");

    Spectateur *s3 = (Spectateur *)malloc(sizeof(Spectateur));
    strcpy(s3->nom, "Charlie");
    s3->siege = 7;
    s3->jourconcert = 16;
    s3->moisconcert = 5;
    s3->cbok = 1;
    printf("Spectateur Charlie créé\n");

    // Ajout des spectateurs à la liste
    ajout_spec(&liste, s1);
    ajout_spec(&liste, s2);
    ajout_spec(&liste, s3);
    printf("Spectateurs ajoutés à la liste\n");

    // Affichage des spectateurs
    printf("Liste des spectateurs:\n");
    affiche_spec(liste);

    // Trouver le meilleur siège
    Spectateur *meilleur = trouve_meilleur(liste);
    if (meilleur) {
        printf("\nMeilleur siège : %s\n", meilleur->nom);
    }

    // Supprimer les erreurs de CB
    suppr_err_CB(&liste);
    printf("Erreurs de CB supprimées\n");

    // Affichage après suppression
    printf("\nListe des spectateurs après suppression des erreurs de CB:\n");
    affiche_spec(liste);

    // Libération de la mémoire
    libere_speclist(liste);
    printf("Mémoire libérée\n");

    return 0;
}

