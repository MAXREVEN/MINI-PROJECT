#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"


Collecte format(Conteneur a,Camion b,int z)
{
    Collecte x;
    x.id_cont=a.id_cont;
    x.id_cam=b.id_cam;
    do{
        printf("ID:");
        scanf("%d",&x.id_collecte);
    } while (x.id_collecte < 10000000 || x.id_collecte > 99999999);  //id should be 8-digit long
    date(x.date_hr_collecte, sizeof x.date_hr_collecte);
    x.volume_collecte=z;
    return x;
}
struct tm maintenant(void) {
    time_t secondes;
    time(&secondes);
    return *localtime(&secondes);
}
void date(char *d, size_t s)
{
    struct tm t = maintenant();
    snprintf(d, s, "%02d/%02d/%d %02d:%02d:%02d",
             t.tm_mday, t.tm_mon + 1, t.tm_year + 1900,
             t.tm_hour, t.tm_min, t.tm_sec);
}


