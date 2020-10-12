#include<stdio.h>
#include<string.h>
#include<gtk/gtk.h>
#include"shfonctions.h"
enum
{
	SHREF,
	SHDE,
	SHA,
	SHDATEALLEZ,
	SHDATERETOUR,
	SHCOMPAGNIEAERIENNE,
	SHNBSIEGE,
	SHPRIX,
	COLUMNS
};


void shAfficherVols(GtkWidget *shliste)
{                   
GtkCellRenderer *shrenderer;
GtkTreeViewColumn *shcolumn;
GtkTreeIter shiter;
GtkListStore *shstore;
int shn=30;
char shref[shn];
char shde[shn];
char sha[shn];
char shdateallez[shn];
char shdateretour[shn];
char shcompagnieaerienne[shn];
int shnbsiege;
int shprix;

shstore=NULL;
FILE *shf;
shstore=gtk_tree_view_get_model(shliste);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" ref",shrenderer,"text",SHREF,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" de",shrenderer,"text",SHDE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" a",shrenderer,"text",SHA,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" dateallez",shrenderer,"text",SHDATEALLEZ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" dateretour",shrenderer,"text",SHDATERETOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" compagnieaerienne",shrenderer,"text",SHCOMPAGNIEAERIENNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" nbsiege",shrenderer,"text",SHNBSIEGE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shrenderer = gtk_cell_renderer_text_new ();
shcolumn = gtk_tree_view_column_new_with_attributes(" prix",shrenderer,"text",SHPRIX,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (shliste), shcolumn);
shstore=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT);
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","r");
if(shf==NULL)
{
return;
}
else
{shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","a+");
	while (fscanf(shf,"%s %s %s %s %s	%s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,&shnbsiege,&shprix)!=EOF)

{
gtk_list_store_append (shstore,&shiter);
gtk_list_store_set (shstore, &shiter, SHREF, shref, SHDE, shde, SHA, sha, SHDATEALLEZ, shdateallez, SHDATERETOUR, shdateretour, SHCOMPAGNIEAERIENNE, shcompagnieaerienne, SHNBSIEGE, shnbsiege, SHPRIX, shprix, -1);
}
fclose(shf);
gtk_tree_view_set_model (GTK_TREE_VIEW (shliste), GTK_TREE_MODEL (shstore));
g_object_unref (shstore);
}
}
void shAjouterVol(shVol shv)
{FILE *shf;
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","a");
if (shf!=NULL)
{if (shv.shdateretour.shj !=0 && shv.shdateretour.shm !=0)
{fprintf(shf,"%s %s,%s %s,%s %d/%d/%d %d/%d/%d %s %d %d\n ",shv.shRef,shv.shDe.shpays,shv.shDe.shville,shv.shA.shpays,shv.shA.shville,shv.shdateallez.shj,shv.shdateallez.shm,shv.shdateallez.sha,shv.shdateretour.shj,shv.shdateretour.shm,shv.shdateretour.sha,shv.shCompagnieaerienne,shv.shNombredesiege,shv.shPrix);
}
else
{fprintf(shf,"%s %s,%s %s,%s %d/%d/%d allez_simple %s %d %d\n ",shv.shRef,shv.shDe.shpays,shv.shDe.shville,shv.shA.shpays,shv.shA.shville,shv.shdateallez.shj,shv.shdateallez.shm,shv.shdateallez.sha,shv.shCompagnieaerienne,shv.shNombredesiege,shv.shPrix);
}
fclose(shf);
}
}
int shRemplirVols(char shvol[20][20])
{FILE *shf;
int shn=0;
char shref[20];
char shde[20];
char sha[20];
char shdateallez[20];
char shdateretour[20];
char shcompagnieaerienne[20];
int shnbsiege;
int shprix;
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","r");
if (shf!=NULL)
{
while (fscanf(shf,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,&shnbsiege,&shprix)!=EOF)
{strcpy(shvol[shn],shref);
shn+=1;}
fclose(shf);
}
return shn;
}
int shVerifierVol(char shnom[])
{FILE *shf;
int shv=0;
char shref[20];
char shde[20];
char sha[20];
char shdateallez[20];
char shdateretour[20];
char shcompagnieaerienne[20];
int shnbsiege;
int shprix;
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","r");
if (shf!=NULL)
{
while (!shv && fscanf(shf,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,&shnbsiege,&shprix)!=EOF)
{if (strcmp(shref,shnom)==0)
shv=1;}
fclose(shf);
}
return shv;
}
void shRemplirVille(char shville[20][20],char shpays[])
{FILE *shf;
char shp[20];
char shv1[20];
char shv2[20];
char shv3[20];
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shville.txt","r");
if (shf!=NULL)
{
while (fscanf(shf,"%s %s %s %s",shp,shv1,shv2,shv3)!=EOF)
{if (strcmp(shp,shpays)==0)
{strcpy(shville[0],shv1);
strcpy(shville[1],shv2);
strcpy(shville[2],shv3);}}
fclose(shf);
}
}
void shRemplirCompagnie(char shcompagnie[20][20],char shpays[])
{FILE *shf;
char shp[20];
char shc1[20];
char shc2[20];
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shcompagnie.txt","r");
if (shf!=NULL)
{
while (fscanf(shf,"%s %s %s \n",shp,shc1,shc2)!=EOF)
{if (strcmp(shp,shpays)==0)
{strcpy(shcompagnie[0],shc1);
strcpy(shcompagnie[1],shc2);}}
fclose(shf);
}
}

void shModifierVol(shVol shv)
{
FILE *shf;
FILE *shf2;
char shref[20];
char shde[20];
char sha[20];
char shdateallez[20];
char shdateretour[20];
char shcompagnieaerienne[20];
int shnbsiege;
int shprix;
int shx;
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","r");
shf2= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shtmp.txt","w");
if (shf!=NULL)
{
if (shf2!=NULL)
{
while (fscanf(shf,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,&shnbsiege,&shprix)!=EOF)
{if (strcmp(shref,shv.shRef)!=0)
fprintf(shf2,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,shnbsiege,shprix);
else
{if (shv.shdateretour.shj !=0 && shv.shdateretour.shm !=0)
fprintf(shf2,"%s %s,%s %s,%s %d/%d/%d %d/%d/%d %s %d %d\n ",shv.shRef,shv.shDe.shpays,shv.shDe.shville,shv.shA.shpays,shv.shA.shville,shv.shdateallez.shj,shv.shdateallez.shm,shv.shdateallez.sha,shv.shdateretour.shj,shv.shdateretour.shm,shv.shdateretour.sha,shv.shCompagnieaerienne,shv.shNombredesiege,shv.shPrix);

else
fprintf(shf2,"%s %s,%s %s,%s %d/%d/%d allez_simple %s %d %d\n ",shv.shRef,shv.shDe.shpays,shv.shDe.shville,shv.shA.shpays,shv.shA.shville,shv.shdateallez.shj,shv.shdateallez.shm,shv.shdateallez.sha,shv.shCompagnieaerienne,shv.shNombredesiege,shv.shPrix);
}}
fclose(shf2);
}
fclose(shf);
}
remove("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt");
shx=rename("/home/salmenhsairi/Projects/salmen2rec/src/shtmp.txt","/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt");
}
void shSupprimerVol(char shnom[])
{
FILE *shf;
FILE *shf2;
char shref[20];
char shde[20];
char sha[20];
char shdateallez[20];
char shdateretour[20];
char shcompagnieaerienne[20];
int shnbsiege;
int shprix;
int shx;
shf= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt","r");
shf2= fopen("/home/salmenhsairi/Projects/salmen2rec/src/shtmp.txt","w");
if (shf!=NULL)
{
if (shf2!=NULL)
{
while (fscanf(shf,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,&shnbsiege,&shprix)!=EOF)
{if (strcmp(shref,shnom)!=0)
fprintf(shf2,"%s %s %s %s %s %s %d %d \n",shref,shde,sha,shdateallez,shdateretour,shcompagnieaerienne,shnbsiege,shprix);
}
fclose(shf2);
}
fclose(shf);
}
remove("/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt");
shx=rename("/home/salmenhsairi/Projects/salmen2rec/src/shtmp.txt","/home/salmenhsairi/Projects/salmen2rec/src/shvol.txt");
}

int shVerifierDate(shDate dA,shDate dR)
{int x=1;
if (dR.shj!=0 && dR.shm!=0)
{if (dR.sha<dA.sha)

	x=0;
else if (dR.sha>=dA.sha && dR.shm<dA.shm)

	x=0;
else if (dR.sha>=dA.sha && dR.shm>=dA.shm && dR.shj<dA.shj)

	x=0;
else
	x=1;}
return (x);
}






















