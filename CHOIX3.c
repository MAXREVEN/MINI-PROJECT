#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"

void vider_conteneur(Conteneur *tabcont,Camion *tabcam,Collecte *tabcoll,int n,int m,int *f)
{
    int x=0,y=-1;
    for (int i=0;i<n;i++)
        printf("conteuneur '%i': valeur d'occupation: %f\n",i,tabcont[i].val_occup_cont);
    printf("choisir un conteuneur a vider");
    scanf("%i",&x);
    if (x < 0 || x >= n)
        {
            printf("conteneur invalide\n");
            return;
        }
    float vol = tabcont[x].val_occup_cont;
    for (int i = 0; i < m; i++){
        if (tabcam[i].max_occup_cam - tabcam[i].val_occup_cam >= vol){ y = i; break; }
    }
    if (y == -1){ printf("aucun camion disponible\n"); return; }

    tabcam[y].val_occup_cam += vol;
    tabcont[x].val_occup_cont = 0;
    tabcoll[*f] = format(tabcont[x], tabcam[y], vol);
    (*f)++;
}
void dech_camion(Camion *tabcam,int m)
{
    int x=0;
    for (int i=0;i<m;i++)
        printf("camion '%i': valeur d'occupation: %f\n",i,tabcam[i].val_occup_cam);
    printf("choisir une camion a vider");
    scanf("%i",&x);
    if (x < 0 || x >= m)
        {
            printf("camion invalide\n");
            return;
        }
    tabcam[x].val_occup_cam=0;
}
void hist_collecte(Collecte *tabcoll,int f)
{
    for (int i=0;i<f;i++)
    {
        printf("id_collecte: %d\nid_cont: %d\nid_cam: %d\ndate: %s\nvolume: %.2f\n\n",tabcoll[i].id_collecte,tabcoll[i].id_cont,tabcoll[i].id_cam,tabcoll[i].date_hr_collecte,tabcoll[i].volume_collecte);
    }
}
