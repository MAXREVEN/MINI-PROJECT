#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"

void vider_conteneur(Conteneur *tabcont,Camion *tabcam,Collecte *tabcoll,int n,int m,int *f)
{
    int x=0,y=-1,z=0;
    for (int i=0;i<n;i++)
        printf("conteuneur '%i': valeur d'occupation: %i\n",i,tabcont[i].val_occup_cont);
    printf("choisir un conteuneur a vider");
    scanf("%i",&x);
    for (int i=0;i<m;i++)
    {
        if (tabcam[i].max_occup_cam-tabcam[i].val_occup_cam>=tabcont[x].val_occup_cont)
        {
            tabcam[i].val_occup_cam+=tabcont[x].val_occup_cont;
            z=tabcont[x].val_occup_cont;
            tabcont[x].val_occup_cont=0;
            y=i;
            break;
        }
    }
    *f++;
    tabcoll[*f]=format(tabcont[x],tabcam[y],z);
}
void dech_camion(Camion *tabcam,int m)
{
    int x=0;
    for (int i=0;i<m;i++)
        printf("camion '%i': valeur d'occupation: %i\n",i,tabcam[i].val_occup_cam);
    printf("choisir une camion a vider");
    scanf("%i",&x);
    tabcam[x].val_occup_cam=0;
}
void hist_collecte(Collecte *tabcoll,int f)
{
    for (int i=0;i<f;i++)
    {
        printf("id_collecte: %i\nid_cont: %i\nid_cam: %i\n,date: %s,volume:");
    }
}

