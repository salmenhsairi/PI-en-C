#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "shcallbacks.h"
#include "interface.h"
#include "support.h"
#include "shfonctions.h"


void
on_shAfficher_clicked                  (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *ajouterModifierVols;
GtkWidget *ListeVols;
GtkWidget *shtreeview;

ajouterModifierVols=lookup_widget(shobjet,"shajouterModifierVols");
gtk_widget_destroy(ajouterModifierVols);
ListeVols=lookup_widget(shobjet,"shListeVols");
ListeVols=create_shListeVols();
gtk_widget_show(ListeVols);
shtreeview=lookup_widget(ListeVols,"shtreeview");
shAfficherVols(shtreeview);
}


void
on_shok2_clicked                       (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *Combobox1;
GtkWidget *Combobox2;
GtkWidget *Combobox3;
GtkWidget *ajouterModifierVols;
GtkWidget *msg;

char shville[20][20];
char shpays[20];
char shpaysde[20];
int shi;
ajouterModifierVols=lookup_widget(shobjet,"shajouterModifierVols");
msg=lookup_widget(shobjet,"shmessage");
Combobox1=lookup_widget(shobjet,"shPaysA");
Combobox2=lookup_widget(shobjet,"shVilleA");
Combobox3=lookup_widget(shobjet,"shPaysDe");
strcpy(shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
strcpy(shpaysde,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox3)));
if (strcmp(shpaysde,shpays)!=0)
{shRemplirVille(shville,shpays);
gtk_label_set_text(GTK_LABEL(msg)," ");
for(shi=1;shi<=3;shi++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (Combobox2),0);
for(shi=0;shi<3;shi++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox2),_(shville[shi]));
}
else
gtk_label_set_text(GTK_LABEL(msg),"choisir une autre destination!!");
}


void
on_shok1_clicked                       (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *Combobox1;
GtkWidget *Combobox2;
GtkWidget *Combobox3;
char shville[20][20];
char shcompagnie[20][20];
char shpays[20];
int shi;
Combobox1=lookup_widget(shobjet,"shPaysDe");
Combobox2=lookup_widget(shobjet,"shVilleDe");
Combobox3=lookup_widget(shobjet,"shCompagnie");
strcpy(shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
shRemplirVille(shville,shpays);
shRemplirCompagnie(shcompagnie,shpays);
for(shi=0;shi<=3;shi++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (Combobox2),0);
for(shi=0;shi<3;shi++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox2),_(shville[shi]));
for(shi=0;shi<=2;shi++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (Combobox3),0);
for(shi=0;shi<2;shi++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox3),_(shcompagnie[shi]));
}


void
on_shSupprimer_clicked                 (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *ListeVols;
GtkWidget *combobox;
GtkWidget *label;
GtkWidget *treeview;

char ref[20];
ListeVols=lookup_widget(shobjet,"shListeVols");
combobox=lookup_widget(shobjet,"shvolsbox");
label=lookup_widget(shobjet,"shmsgsupression");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
shSupprimerVol(ref);
gtk_widget_destroy(ListeVols);
ListeVols=create_shListeVols();
gtk_widget_show(ListeVols);
treeview=lookup_widget(ListeVols,"shtreeview");
shAfficherVols(treeview);
gtk_label_set_text(GTK_LABEL(label),"supression reussite !!");
}


void
on_shchoisir_clicked                   (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *Combobox0;
GtkWidget *ListeVols;
char shtabvol[20][20];
int shn,shi;
ListeVols=lookup_widget(shobjet,"shListeVols");
Combobox0=lookup_widget(shobjet,"shvolsbox");
shn=shRemplirVols(shtabvol);
for(shi=0;shi<=shn;shi++)
gtk_combo_box_remove_text (GTK_COMBO_BOX (Combobox0),0);
for(shi=0;shi<shn;shi++)
gtk_combo_box_append_text (GTK_COMBO_BOX (Combobox0),_(shtabvol[shi]));
}


void
on_shretour_clicked                    (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *ajouterModifierVols,*ListeVols;
ListeVols=lookup_widget(shobjet,"shListeVols");
gtk_widget_destroy(ListeVols);
ajouterModifierVols=create_shajouterModifierVols();
gtk_widget_show(ajouterModifierVols);
}


void
on_shModifier_clicked                  (GtkWidget       *shobjet,
                                        gpointer         user_data)
{
GtkWidget *ajouterModifierVols;
GtkWidget *Ref;
GtkWidget *paysde;
GtkWidget *villede;
GtkWidget *paysa;
GtkWidget *villea;
GtkWidget *jourallez;
GtkWidget *moisallez;
GtkWidget *anneeallez;
GtkWidget *jourretour;
GtkWidget *moisretour;
GtkWidget *anneeretour;
GtkWidget *compagnie;
GtkWidget *npassagers;
GtkWidget *prix;
GtkWidget *msg;
shVol v;
char prixc[10];
ajouterModifierVols=lookup_widget(shobjet,"shajouterModifierVols");
Ref=lookup_widget(shobjet,"shref");
paysde=lookup_widget(shobjet,"shPaysDe");
villede=lookup_widget(shobjet,"shVilleDe");
paysa=lookup_widget(shobjet,"shPaysA");
villea=lookup_widget(shobjet,"shVilleA");
jourallez=lookup_widget(shobjet,"shja");
moisallez=lookup_widget(shobjet,"shma");
anneeallez=lookup_widget(shobjet,"shaa");
jourretour=lookup_widget(shobjet,"shjr");
moisretour=lookup_widget(shobjet,"shmr");
anneeretour=lookup_widget(shobjet,"shar");
compagnie=lookup_widget(shobjet,"shCompagnie");
npassagers=lookup_widget(shobjet,"shnbpassager");
prix=lookup_widget(shobjet,"shprix");
msg=lookup_widget(shobjet,"shmessagemodifier");
strcpy(v.shRef,gtk_entry_get_text(GTK_ENTRY(Ref)));
strcpy(prixc,gtk_entry_get_text(GTK_ENTRY(prix)));
v.shPrix=atoi(prixc);
strcpy(v.shDe.shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysde)));
strcpy(v.shDe.shville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(villede)));
strcpy(v.shA.shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysa)));
strcpy(v.shA.shville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(villea)));
strcpy(v.shCompagnieaerienne,gtk_combo_box_get_active_text(GTK_COMBO_BOX(compagnie)));
v.shdateallez.shj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourallez));
v.shdateallez.shm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisallez));
v.shdateallez.sha=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(anneeallez));
v.shdateretour.shj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourretour));
v.shdateretour.shm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisretour));
v.shdateretour.sha=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(anneeretour));
v.shNombredesiege=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(npassagers));
if (shVerifierVol(v.shRef)==1 && shVerifierDate(v.shdateallez,v.shdateretour)==1)
{shModifierVol(v);
gtk_label_set_text(GTK_LABEL(msg),"modification reussite !!");}
else
{if (shVerifierVol(v.shRef)==0)
{gtk_label_set_text(GTK_LABEL(msg),"vol inexistant!!");}

if (shVerifierDate(v.shdateallez,v.shdateretour)==0)
gtk_label_set_text(GTK_LABEL(msg),"verifier date!!");}
}


void
on_shAjouter_clicked                   (GtkWidget      *shobjet,
                                        gpointer         user_data)
{
GtkWidget *ajouterModifierVols;
GtkWidget *Ref;
GtkWidget *paysde;
GtkWidget *villede;
GtkWidget *paysa;
GtkWidget *villea;
GtkWidget *jourallez;
GtkWidget *moisallez;
GtkWidget *anneeallez;
GtkWidget *jourretour;
GtkWidget *moisretour;
GtkWidget *anneeretour;
GtkWidget *compagnie;
GtkWidget *npassagers;
GtkWidget *prix;
GtkWidget *msg;
shVol shv;
char prixc[10];
ajouterModifierVols=lookup_widget(shobjet,"shajouterModifierVols");
Ref=lookup_widget(shobjet,"shref");
paysde=lookup_widget(shobjet,"shPaysDe");
villede=lookup_widget(shobjet,"shVilleDe");
paysa=lookup_widget(shobjet,"shPaysA");
villea=lookup_widget(shobjet,"shVilleA");
jourallez=lookup_widget(shobjet,"shja");
moisallez=lookup_widget(shobjet,"shma");
anneeallez=lookup_widget(shobjet,"shaa");
jourretour=lookup_widget(shobjet,"shjr");
moisretour=lookup_widget(shobjet,"shmr");
anneeretour=lookup_widget(shobjet,"shar");
compagnie=lookup_widget(shobjet,"shCompagnie");
npassagers=lookup_widget(shobjet,"shnbpassager");
prix=lookup_widget(shobjet,"shprix");
msg=lookup_widget(shobjet,"shmessageajouter");
strcpy(shv.shRef,gtk_entry_get_text(GTK_ENTRY(Ref)));
strcpy(prixc,gtk_entry_get_text(GTK_ENTRY(prix)));
shv.shPrix=atoi(prixc);
strcpy(shv.shDe.shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysde)));
strcpy(shv.shDe.shville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(villede)));
strcpy(shv.shA.shpays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(paysa)));
strcpy(shv.shA.shville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(villea)));
strcpy(shv.shCompagnieaerienne,gtk_combo_box_get_active_text(GTK_COMBO_BOX(compagnie)));
shv.shdateallez.shj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourallez));
shv.shdateallez.shm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisallez));
shv.shdateallez.sha=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(anneeallez));
shv.shdateretour.shj=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jourretour));
shv.shdateretour.shm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(moisretour));
shv.shdateretour.sha=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(anneeretour));
shv.shNombredesiege=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(npassagers));
if (shVerifierVol(shv.shRef)==0 && shVerifierDate(shv.shdateallez,shv.shdateretour)==1)
{shAjouterVol(shv);
gtk_label_set_text(GTK_LABEL(msg),"ajout reussi !!");}
else 
{if (shVerifierVol(shv.shRef)==1)
gtk_label_set_text(GTK_LABEL(msg),"vol déja existant!!");
if (shVerifierDate(shv.shdateallez,shv.shdateretour)==0)
gtk_label_set_text(GTK_LABEL(msg),"verifier date!!");}

}


