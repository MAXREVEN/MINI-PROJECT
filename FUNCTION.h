#ifndef function_H_INCLUDED
#define function_H_INCLUDED

typedef struct
{
    int id_zone;
    char nom_zone[50];
    char description[100];
} Zone;

typedef struct {
    int id_cont;
    char emplacement[60];
    float max_occup_cont, val_notif_cont, val_occup_cont;
    int id_zone;
    int etat;            // 0 = actif, 1 = hors service, ...
} Conteneur;

typedef struct {
    int id_cam;
    char matricule[20];
    float max_occup_cam, val_occup_cam;
    int id_zone;
    int etat_dispo;      // 1 = disponible
} Camion;

typedef struct {
    int id_collecte, id_cont, id_cam;
    char date_hr_collecte[20];        // "JJ/MM/AAAA HH:MM"
    float volume_collecte;
} Collecte;
Conteneur saisir_conteneur();
int  ajouter_conteneur(Conteneur tab[], int *n);
int  modifier_conteneur(Conteneur tab[], int n, int id_cont);
int  supprimer_conteneur(Conteneur tab[], int *n, int id_cont);
Conteneur *chercher_conteneur(Conteneur tab[], int n, int id_cont);
void afficher_conteneur_par_zone(Conteneur tab[], int n, int id_zone);
void afficher_conteneurs(Conteneur tab[], int n);
void afficher_conteneur(Conteneur c);
Camion saisir_camion();
int  ajouter_camion(Camion tab[], int *n);
int  modifier_camion(Camion tab[], int n, int id_cam);
int supprimer_camion(Camion tab[],int *n,int id_cam);
Camion  *chercher_camion_disponible(Camion tab[], int n);
void afficher_camion(Camion c);
void afficher_camions(Camion tab[],int n);
void afficher_camion_par_zone(Camion tab[],int n,int id_zone);
Zone saisir_zone();
int  ajouter_zone(Zone tab[], int *n);
int  modifier_zone(Zone tab[], int n, int id_zone);
int supprimer_zone(Zone tab[],int *n,int id_zone);
int chercher_zone(Zone tab[],int n,int id_zone);
void afficher_zone(Zone tab[],int n);
void vider_conteneur(Conteneur tabcont[],Camion tabcam[],Collecte tabcoll[],int n,int m, int *f);
void dech_camion(Camion tabcam[],int n);
void hist_collecte(Collecte *tabcoll,int f);
struct tm maintenant(void);
void date(char *buf, size_t size);
Collecte format(Conteneur a, Camion b, int z);
#endif
