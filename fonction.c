#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"

Conteneur saisir_cont()
{
    Conteneur c;
    do{
        printf("ID:");
        scanf("%d",&c.id_cont);
    }while (!10000000<c.id_cont<99999999);  //id should be 8-digit long
    printf("emplacement:");
    scanf("%s",c.emplacement);
    printf("max occupaction");
    scanf("%f",&c.max_occup_cont);
    printf("valeur notif");
    scanf("%f",&c.val_notif_cont);
    printf("valeur d'occupation");
    scanf("%f",&c.val_occup_cont);
    printf("id de la zone");
    scanf("%s",c.id_zone);
    printf("Etat: ");
    scanf("%i",&c.etat);
    return c;

}
Camion saisir_cam()
{
    Camion c;
    do{
        printf("ID:");
        scanf("%d",&c.id_cam);
    }while (!10000000<c.id_cam<99999999);  //id should be 8-digit long
    printf("matricule:");
    scanf("%s",c.matricule);
    printf("max occupaction");
    scanf("%f",&c.max_occup_cam);
    printf("valeur d'occupation");
    scanf("%f",&c.val_occup_cam);
    printf("id de la zone");
    scanf("%s",c.id_zone);
    printf("Etat: ");
    scanf("%i",&c.etat_dispo);
    return c;
}
Zone saisir_zone()
{
    Zone z;
    do{
        printf("ID:");
        scanf("%d",&z.id_zone);
    }while (!10000000<z.id_zone<99999999);  //id should be 8-digit long
    printf("Nom: ");
    scanf("%s",z.nom_zone);
    printf("Description");
    scanf("%s",z.description);
    return z;
}
Collecte format(Conteneur a,Camion b,int z)
{
    Collecte x;
    x.id_cont=a.id_cont;
    x.id_cam=b.id_cam;
    do{
        printf("ID:");
        scanf("%d",&x.id_collecte);
    }while (!10000000<x.id_collecte<99999999);  //id should be 8-digit long
    date(x.date_hr_collecte, sizeof x.date_hr_collecte);
    x.volume_collecte=z;
}
struct tm maintenant(void) {
    time_t secondes;
    time(&secondes);
    return *localtime(&secondes);
}
void date(char *buf, size_t size)
{
    struct tm t = maintenant();
    snprintf(buf, size, "%02d/%02d/%d %02d:%02d:%02d",
             t.tm_mday, t.tm_mon + 1, t.tm_year + 1900,
             t.tm_hour, t.tm_min, t.tm_sec);
}


