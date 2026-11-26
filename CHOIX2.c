#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FUNCTION.h"
Camion saisir_camion(){
    Camion c;
    printf("saisir l'id du camion =");
    scanf("%d",&c.id_cam);
    printf("saisir la matricule du camion =");
    scanf("%19s",c.matricule);
    printf("saisir le maximum d'occupation du camion =");
    scanf("%f",&c.max_occup_cam);
    printf("saisir la valuer d'occupation actuelle du camion");
    scanf("%f",&c.val_occup_cam);
    printf("saisir l'id de la zone du camion");
    scanf("%d",&c.id_zone);
    printf("saisir l'etat du camion =");
    scanf("%d",&c.etat_dispo);
    return c;}

int  ajouter_camion(Camion tab[], int *m){
    Camion c=saisir_camion();
    for (int i=0;i<(*m);i++){
        if (tab[i].id_cam==c.id_cam)
        {
            printf("camion deja existe\n");
            return 0;   //on doit eviter la redondance de c dans tab
        }
    }
    tab[*m]=c;
    (*m)++;
    return 1;}

int  modifier_camion(Camion tab[], int n, int id_cam){
    int choix;
    for (int i=0;i<n;i++){
        if (tab[i].id_cam==id_cam){
            printf("1. modifier la matricule du camion\n ");
            printf("2. modifier le maximuim d'occupation\n");
            printf("3. modifier la valeur d'occupation actuelle\n");
            printf("4. modfidier la zone du camion\n" );
            printf("5. modfidier l'etat  du camion\n" );
            printf("Donner votre choix: ");
            scanf("%d", &choix);
            switch (choix){
            case 1:{
                printf("saisir la nouvelle matricule =");
                scanf("%19s",tab[i].matricule);
                break;}
            case 2:{
                printf("saisir le nouvel maximuim d'occupation =");
                scanf("%f",&tab[i].max_occup_cam);
                break;}
            case 3:{
                printf("saisir la nouvelle valeur d'occupation actuelle =");
                scanf("%f",&tab[i].val_occup_cam);}
                break;
            case 4:{
                printf("saisir la nouvelle zone =");
                scanf("%d",&tab[i].id_zone);}
                break;
            case 5:{
                printf("saisir le nouvel etat = ");
                scanf("%d",&tab[i].etat_dispo);
                break;}
            default:{
                printf("choix errone!\n");
                }
            }
            return 1;
        }
    }
    printf("camion introuvable\n");
    return 0;}

int supprimer_camion(Camion tab[], int *n, int id){
    for (int i = 0; i < *n; i++){
        if (tab[i].id_cam == id){
            for (int j = i; j < *n - 1; j++)
                tab[j] = tab[j+1];
            (*n)--;
            return 1;
        }
    }
    return 0;
}

Camion  *chercher_camion_disponible(Camion tab[], int n){
    for (int i=0;i<n;i++){
        if (tab[i].etat_dispo==1) return &tab[i];}
    return NULL;}

void afficher_camion(Camion c){
        printf("l'id du camion : %d\n",c.id_cam);
        printf("la valeur maximale d'occupation : %.2f\n",c.max_occup_cam);
        printf("la valeur d'occupation actuelle : %.2f\n",c.val_occup_cam);
        printf("la zone du camion : %d\n",c.id_zone);
        printf("l'etat du camion : %d\n",c.etat_dispo);
        float t =(c.max_occup_cam>0)?c.val_occup_cam/c.max_occup_cam:0;
        printf("le taux de remplissage du camion :%.2f\n",t*100);
        if (t>=1){
                printf("----ALERTE !!! le taux de remplissage du camion identifie par %d est trop eleve !! veuillez faire une decharge ---\n",c.id_cam);}
}

void afficher_camion_par_zone(Camion tab[], int n, int id_zone){
    int trouve=0;
    for(int i=0;i<n;i++){
        if (tab[i].id_zone==id_zone){
            printf("--- les informations du camion identifie par %d ---\n",tab[i].id_cam);
            afficher_camion(tab[i]);
            trouve=1;}}
    if (!trouve) printf("aucun camion dans la zone %d\n",id_zone);
}

void afficher_camions(Camion tab[], int n){
    for(int i=0;i<n;i++)
        afficher_camion(tab[i]);
}
Zone saisir_zone(){
    Zone z;
    printf("saisir l'id de la zone =");
    scanf("%d",&z.id_zone);
    getchar();                      // consume the '\n' left by scanf
    printf("saisir le nom de la zone = ");
    fgets(z.nom_zone, sizeof(z.nom_zone), stdin);
    z.nom_zone[strcspn(z.nom_zone, "\n")] = '\0';   // remove the trailing '\n'
    printf("saisir la description de la zone = ");
    fgets(z.description, sizeof(z.description), stdin);
    z.description[strcspn(z.description, "\n")] = '\0';
    return z;
}

int  ajouter_zone(Zone tab[], int *n){
    Zone z=saisir_zone();
    for (int i=0;i<*n;i++){
        if (tab[i].id_zone==z.id_zone) return 0;   //on doit eviter la redondance de z dans tab
    }
    tab[*n]=z;
    (*n)++;
    return 1;}

int  modifier_zone(Zone tab[], int n, int id_zone){
    int choix;
    for (int i=0;i<n;i++){
        if (tab[i].id_zone==id_zone){
            printf("1. modifier le nom de la  zone\n ");
            printf("2. modifier la description de la zone\n");
            printf("Donner votre choix: ");
            scanf("%d", &choix);
            switch (choix){
            case 1:{
                printf("saisir le nouvel nom de la zone =");
                scanf(" %49[^\n]", tab[i].nom_zone);
                break;}
            case 2:{
                printf("saisir la nouvelle description de la zone =");
                scanf(" %99[^\n]", tab[i].description);
                break;}
            default:{
                printf("choix errone!\n");}
        }
        break;}
    }
    return 0;}

int supprimer_zone(Zone tab[], int *n, int id){
    for (int i = 0; i < *n; i++){
        if (tab[i].id_zone == id){
            for (int j = i; j < *n - 1; j++)
                tab[j] = tab[j+1];
            (*n)--;
            return 1;
        }
    }
    return 0;
}

void afficher_zones(Zone tab[], int n){
    for(int i=0;i<n;i++){
            printf("--- les informations de la zone identifie par %d ---\n",tab[i].id_zone);
            printf("le nom de la zone : %s\n",tab[i].nom_zone);
            printf("la description de la zone : %s\n",tab[i].description);
            }
}
