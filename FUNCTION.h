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

void ajout_conteneur(Conteneur tabcont[]);
void mod_conteneur(Conteneur tabcont[]);
void supp_conteneur(Conteneur tabcont[]);
void afficher_conteneur(Conteneur tabcont[]);
void filtre_conteneur(Conteneur tabcont[]);
void ajout_camion(Camion tabcam[]);
void mod_camion(Camion tabcam[]);
void supp_camion(Camion tabcam[]);
void afficher_cam(Camion tabcam[]);
void vider_conteneur(Conteneur tabcont[],Camion tabcam[],Collecte tabcoll[],int n,int m, int *f);
void dech_camion(Camion tabcam[],int n);
void hist_collecte(Collecte *tabcoll,int f);
struct tm maintenant(void);
void date(char *buf, size_t size);
Collecte format(Conteneur a, Camion b, int z);
Conteneur saisir_cont();
Camion saisir_cam();
Zone saisir_zone();
#endif // function_H_INCLUDED
