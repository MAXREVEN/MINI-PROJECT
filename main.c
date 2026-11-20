#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FUNCTION.h"

int main()
{
    int choix,run,n,m,f;
    time_t secondes;
    struct tm instant;
    Conteneur tabcont[30];
    Zone tabzone[30];
    Collecte tabcoll[30];
    Camion tabcam[30];
    while (1)
    {
        printf("1. Gestion des zones et conteneurs\n");
        printf("2. Gestion des camions de collecte\n");
        printf("3. Opérations de collecte et vidage\n");
        printf("4. Statistiques et alertes\n");
        printf("0. Quitter\n" );

        printf("Donner votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            run = 1;
            while (run)
            {
                printf("1. Ajouter un conteneur / une zone\n");
                printf("2. Modifier les informations d'un conteneur\n");
                printf("3. Supprimer un conteneur\n");
                printf("4. afficher la liste des conteneur\n");
                printf("5. Afficher les conteneurs filtrés par zone\n");
                printf("0. precedent\n" );

                printf("Donner votre choix: ");
                scanf("%d", &choix);
                switch (choix)
                {
                case 1:
                {
                    ajout_conteneur(tabcont);
                    break;
                }
                case 2:
                {
                    mod_conteneur(tabcont);
                    break;
                }
                case 3:
                {
                    supp_conteneur(tabcont);
                    break;
                }
                case 4:
                {
                    afficher_conteneur(tabcont);
                    break;
                }
                case 5:
                {
                    filtre_conteneur(tabcont);
                    break;
                }
                case 0:
                    run = 0;
                    break;
                default:
                    printf("choix errone!\n");
                }
            }
            break;
        }
        case 2:
        {
            run = 1;
            while (run)
            {
                printf("1. Ajouter un camion\n");
                printf("2. Modifier la capacité ou les informations d'un camion\n");
                printf("3. Supprimer un camion\n");
                printf("4. Afficher tous les camions et leur taux de remplissage\n");
                printf( "0. precedent\n" );

                printf("Donner votre choix: ");
                scanf("%d", &choix);
                switch (choix)
                {
                case 1:
                {
                    ajout_camion(tabcam);
                    break;
                }
                case 2:
                {
                    mod_camion(tabcam);
                    break;
                }
                case 3:
                {
                    supp_camion(tabcam);
                    break;
                }
                case 4:
                {
                    afficher_cam(tabcam);
                    break;
                }
                case 0:
                    run = 0;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            run = 1;
            while (run)
            {
                printf("1. Vider un conteneur\n");
                printf("2. Décharger un camion\n");
                printf("3. Afficher l'historique complet des opérations de collecte\n");
                printf("0. precedent\n" );

                printf("Donner votre choix: ");
                scanf("%d", &choix);
                switch (choix)
                {
                case 1:
                {
                    vider_conteneur(tabcont,tabcam,tabcoll,n,m,&f);
                    break;
                }
                case 2:
                {
                    dech_camion(tabcam);
                    break;
                }
                case 3:
                {
                    hist_collecte(tabcoll);
                    break;
                }
                case 0:
                    run = 0;
                    break;
                }
            }
            break;
        }
        /*case 4:
        {
            run = 1;
            while (run)
            {
                printf("1. Afficher la liste prioritaire des conteneurs saturés ou en alerte\n");
                printf("2. Statistiques de remplissage et de volume collecté par zone\n");
                printf("3. Statistiques par camion\n");
                printf("4. Tri des conteneurs ou des opérations\n");
                printf("5. Recherche d'un conteneur ou d'un camion par ID, emplacement ou zone\n");
                printf("0. precedent\n");

                printf("Donner votre choix: ");
                scanf("%d", &choix);
                switch (choix)
                {
                case 1:
                {
                    ajout_conteneur(tabcont);
                    break;
                }
                case 2:
                {
                    mod_conteneur(tabcont);
                    break;
                }
                case 3:
                {
                    supp_conteneur(tabcont);
                    break;
                }
                case 3:
                {
                    supp_conteneur(tabcont);
                    break;
                }
                case 4:
                {
                    afficher_conteneur(tabcont);
                    break;
                }
                case 0:
                    run = 0;
                    break;
                }
            }
            break;
        }*/
        case 0:
            exit(0);
        default:
            printf("Choix errone!\n");
        }
    }
    return 0;
}
