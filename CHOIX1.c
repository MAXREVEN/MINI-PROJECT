#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"
Conteneur saisir_conteneur(){
    Conteneur c;
    printf("saisir l'id du conteneur =");
    scanf("%d",&c.id_cont);
    printf("saisir l'emplacement du conteneur =");
    scanf("%59[^\n]",c.emplacement);
    printf("saisir la valeur maximuim d'occupation =");
    scanf("%f",&c.max_occup_cont);
    printf("saisir la valeur valeur seuil =");
    scanf("%f",&c.val_notif_cont);
    printf("saisir la valeur d'occupation actuelle =");
    scanf("%f",&c.val_occup_cont);
    printf("saisir la id de zone =");
    scanf("%d",&c.id_zone);
    printf("saisir l'etat du conteneur =");
    scanf("%d",&c.etat);
    return c;}

int  ajouter_conteneur(Conteneur tab[], int *n)
{
    Conteneur c=saisir_conteneur();
    for (int i=0;i<*n;i++){
        if (tab[i].id_cont==c.id_cont) return 0;}   //on doit eviter la redondance de c dans tab
    tab[*n]=c;
    (*n)++;
    return 1;
}

int  modifier_conteneur(Conteneur tab[], int n, int id){
    int choix;
    for (int i=0;i<n;i++){
        if (tab[i].id_cont==id){
            printf("1. modifier l'emplacement du conteneur\n ");
            printf("2. modifier le maximuim d'occupation\n");
            printf("3. modifier la valeur seuil\n");
            printf("4. modifier la valeur d'occupation actuelle\n");
            printf("5. modfidier la zone du conteneur\n" );
            printf("6. modfidier l'etat  du conteneur\n" );
            printf("Donner votre choix: ");
            scanf("%d", &choix);
            switch (choix){
            case 1:{
                printf("saisir le nouvel emplacement =");
                scanf("%59s", tab[i].emplacement);
                break;}
            case 2:{
                printf("saisir le nouvel maximuim d'occupation =");
                scanf("%f",&tab[i].max_occup_cont);
                break;}
            case 3:{
                printf("saisir la nouvelle valeur seuil =");
                scanf("%f",&tab[i].val_notif_cont);
                break;}
            case 4:{
                printf("saisir la nouvelle valeur d'occupation actuelle =");
                scanf("%f",&tab[i].val_occup_cont);
                break;}
            case 5:{
                printf("saisir la nouvelle zone =");
                scanf("%d",&tab[i].id_zone);
                break;}
            case 6:{
                printf("saisir le nouvel etat = ");
                scanf("%d",&tab[i].etat);
                break;}
            default:{
                printf("choix errone!\n");}
        }
        break;}
    }
    return 0;}

int supprimer_conteneur(Conteneur tab[], int *n, int id){
    for (int i = 0; i < *n; i++){
        if (tab[i].id_cont == id){
            for (int j = i; j < *n - 1; j++)
                tab[j] = tab[j+1];
            (*n)--;
            return 1;
        }
    }
    return 0;
}

Conteneur  *chercher_conteneur(Conteneur tab[], int n, int id){
    for (int i=0;i<n;i++){
        if (tab[i].id_cont==id) return &tab[i];}
    return NULL;}


void afficher_conteneur(Conteneur c){
        printf("l'id du conteneur : %d\n",c.id_cont);
        printf("l'emplacement du conteneur : %s\n",c.emplacement);
        printf("la valeur maximale d'occupation : %.2f\n", c.max_occup_cont);
        printf("la valeur seuil : %.2f\n",c.val_notif_cont);
        printf("la valeur d'occupation actuelle : %.2f\n",c.val_occup_cont);
        printf("la zone du conteneur : %d\n",c.id_zone);
        printf("l'etat du conteneur : %d\n",c.etat);
        if (c.val_occup_cont>=c.val_notif_cont){
            printf("----ALERTE !!! le taux d'occupation du conteneur identifie par l'id %d est trop eleve !! veuillez faire un vidage ---\n",c.id_cont);
        }
}

void afficher_conteneur_par_zone(Conteneur tab[], int n, int id_zone){
    int trouve=0;
    for(int i=0;i<n;i++){
        if (tab[i].id_zone==id_zone){
            printf("--- les informations du conteneur numero %d ---\n",i+1);
            afficher_conteneur(tab[i]);
            trouve=1;}}
    if (!trouve) printf("aucun conteneur dans la zone %d",id_zone);
}
void afficher_conteneurs(Conteneur tab[], int n){
    for(int i=0;i<n;i++) afficher_conteneur(tab[i]);}



