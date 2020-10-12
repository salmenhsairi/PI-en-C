#ifndef FONCTIONS_H_included
#define FONCTIONS_H_included
#include<gtk/gtk.h>
typedef struct
{
char shpays[20];
char shville[20];
}shDestination;
typedef struct
{int shj;
int shm;
int sha;
}shDate;
typedef struct 
{char shRef[20];
shDestination shDe;
shDestination shA;
shDate shdateallez;
shDate shdateretour;
char shCompagnieaerienne[20];
int shNombredesiege;
int shPrix;

}shVol;

void shRemplirVille(char shville[20][20],char shpays[]);
void shRemplirCompagnie(char shcompagnie[20][20],char shpays[]);
int shRemplirVols(char shvol[20][20]);//retourner le nb totale de vols et rempir nomvol[][]
void shAfficherVols(GtkWidget *shliste);
int shVerifierVol(char shnom[]);//1 si elle existe dans le fichier,0 si non
void shAjouterVol(shVol v);//lire a partir des champs et ajouter dans vol.txt
int shVerifierDate(shDate dA,shDate dR);//retourne 1 si Date retour > date allez et 0 si nn
void shModifierVol(shVol v);
void shSupprimerVol(char shnom[]);

#endif// FONCTIONS_H_included
