#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "troupeaux.h"
#include "nb.h"
#include <string.h>
#include <time.h>
#include "equip.h"
#include "ouvrier.h"
#include"abs.h"



void
on_res__clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *admin,*fenetre_res ; 
admin=lookup_widget(objet_graphique,"Admin");
gtk_widget_destroy(admin);
fenetre_res=create_espace_responsable_();
gtk_widget_show(fenetre_res);



}


void
on_quit_admin_activate                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Admin;
/*
GtkWidget *fenetre_auth,*admin;

fenetre_admin=lookup_widget(objet,"Admin");
gtk_widget_destroy(fenetre_admin);
fenetre_auth=create_auth();
gtk_widget_show(fenetre_auth);*/

gtk_widget_destroy (Admin);

}


void
on_ajouter_ch2__clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*fenetre_ajout2,*labelnom,*labelprenom,*labelsexe,*labelnt,*labelcin,*labelmail;
ouvrier o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
char id[20];
int b=1;
No = lookup_widget (objet,"entry37");
Pr = lookup_widget (objet,"entry38");
ci = lookup_widget (objet,"entry39");

Nt = lookup_widget (objet,"entry40");
jour = lookup_widget (objet,"spinbutton17");
mois = lookup_widget (objet,"spinbutton18");
annee = lookup_widget (objet,"spinbutton19");
se = lookup_widget (objet,"combobox14");

Am = lookup_widget (objet,"entry41");


strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }


labelnom=lookup_widget(objet,"label345");
labelprenom=lookup_widget(objet,"label346");
labelsexe=lookup_widget(objet,"label347");
labelcin=lookup_widget(objet,"label348");
labelnt=lookup_widget(objet,"label349");
labelmail=lookup_widget(objet,"label350");




// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.num_tl,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir votre numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.Mail,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"saisir Mail !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"");
}
if(b==1){
Ajouter_ch( o);
}
//mise a jour du treeView
GtkWidget* p=lookup_widget(objet,"treeview8");
affi_ad_ch(p,"ouvrier.txt");       
}


void
on_supp_ch2__clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char sexe[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char num_tl[20];
char Mail[20];
lb = lookup_widget (objet,"label342");
dd = lookup_widget (objet,"entry42");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("ouvrier.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,sexe,CIN,num_tl,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}



//mise à jour treeview

    GtkWidget* p=lookup_widget(objet,"treeview8");

    affi_ad_ch(p,"ouvrier.txt");




}


void
on_rech_ch2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*Nm,*Pnom,*cin,*SEXE,*Jour,*Mois,*Num,*Annee,*mail,*lb;
char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char CIN[20];
char num_tl[20];
char jour[20];
char mois[20];
char annee[20];
char Mail[20];
char idd[20];
ouvrier o ;
int x=-1;

FILE *F;

dd = lookup_widget (button,"entry43");
Nm = lookup_widget(button, "entry44");
Pnom = lookup_widget(button, "entry45");
SEXE = lookup_widget(button, "label353");
cin = lookup_widget (button,"entry46");
Num = lookup_widget(button, "entry47");
Jour = lookup_widget(button, "spinbutton20");
Mois = lookup_widget(button, "spinbutton21");
Annee = lookup_widget(button, "spinbutton22");
mail = lookup_widget(button, "entry48");
lb = lookup_widget(button, "label352");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("ouvrier.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,sexe,CIN,num_tl,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(SEXE),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(Num),"");
gtk_entry_set_text(GTK_LABEL(mail),"");
}else
{
    ouvrier o = rechercher_ouvrier(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");/* code */


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(SEXE),o.sexe);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(Num),o.num_tl);
gtk_entry_set_text(GTK_LABEL(mail),o.Mail);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),jour);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),mois);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),annee);

}

}


void
on_modi_ch2__clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
ouvrier o;
char id[20];


dd = lookup_widget (objet_graphique,"entry43");
no = lookup_widget (objet_graphique,"entry44");
pr = lookup_widget (objet_graphique,"entry45");
se = lookup_widget (objet_graphique,"combobox15");
ci = lookup_widget (objet_graphique,"entry46");
nt = lookup_widget (objet_graphique,"entry47");
jour = lookup_widget (objet_graphique,"spinbutton20");
mois = lookup_widget (objet_graphique,"spinbutton21");
annee = lookup_widget (objet_graphique,"spinbutton22");
am = lookup_widget (objet_graphique,"entry48");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(am)));


modi_ch(id,o);
//mise  a jour tree
     GtkWidget* p=lookup_widget(objet_graphique,"treeview8");
         affi_ad_ch(p,"ouvrier.txt");
}


void
on_actu_ch2_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *se,*labe;
ouvrier o;
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview8");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *Mail;
        gchar *num_tl;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&sexe,4,&CIN,5,&num_tl,6,&jour,7,&mois,8,&annee,9,&Mail,-1);
   gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry43")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry44")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry45")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry46")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry47")),num_tl);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry48")),Mail);

//labe = lookup_widget(objet_graphique, "label357");
//gtk_label_set_text(GTK_LABEL(se),o.sexe);

		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook7")));//redirection vers la page precedente
}



}


void
on_AFF_CH2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_affi,*fenetre_affi1 ;
GtkWidget *da;
GtkWidget *treeView13;
char s[20];
int annee;
da = lookup_widget (objet,"entry54");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
taux_dab(annee);
treeView13=lookup_widget(objet,"treeview13");
affi_ad_abs(treeView13,"Absent.txt");







}


void
on_actu_ad_mah_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview10");
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}
}

void
on_rech_aff_mah_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*nb,*treeview;

int n;
char type[20];

ty = lookup_widget (objet_graphique,"combobox17");
nb = lookup_widget(objet_graphique, "spinbutton23");

strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
n=nb_troupeaux_mah(type);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),n);
j=0;


GtkWidget* pr=lookup_widget(objet_graphique,"treeview11");
nbr_troupeaux_mah();
d=0;
n=0;
Afficherrr(pr,"nb.txt");

}


void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *dd,*lb;

char idd[20];

int x=-1;
FILE *F;
char type[20];
char sexe[20];
char date[20];
char pd[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
lb = lookup_widget (button,"label376");
dd = lookup_widget (button,"entry50");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("troupeaux.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type,sexe,jour,mois,annee,pd) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_mah(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");
}


GtkWidget* p=lookup_widget(button,"treeview10");
d=0;
n=0;
        Afficherr(p,"troupeaux.txt");
}


void
on_rech_ad_mah_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb,*ty,*se,*jo,*pdd,*mo,*an,*po;
char idd[20];

int x=-1;
char type[20];
char sexe[20];
char date[20];
char pd[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
FILE *F;

lb = lookup_widget (button,"label369");
dd = lookup_widget (button,"entry51");
ty = lookup_widget(button, "label368");
se = lookup_widget(button, "label367");
jo = lookup_widget(button, "spinbutton27");
mo = lookup_widget(button, "spinbutton28");
an = lookup_widget(button, "spinbutton29");
pdd = lookup_widget(button, "label205");


po = lookup_widget (button,"entry52");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("troupeaux.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type,sexe,jour,mois,annee,pd) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(pdd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    troupeaux s=rech_mah(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */
    gtk_label_set_text(GTK_LABEL(ty),s.type);
gtk_label_set_text(GTK_LABEL(se),s.sexe);
gtk_label_set_text(GTK_LABEL(pdd),s.pd);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jo),s.dt_ns.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mo),s.dt_ns.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(an),s.dt_ns.annee);
gtk_entry_set_text(GTK_LABEL(po),s.pd);
}
}


void
on_modi_ad_mah_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*jour,*mois,*annee,*po,*dd;
troupeaux tr;
char id[20];


dd = lookup_widget (objet_graphique,"entry51");
ty = lookup_widget (objet_graphique,"combobox18");
se = lookup_widget (objet_graphique,"combobox19");
jour = lookup_widget (objet_graphique,"spinbutton27");
mois = lookup_widget (objet_graphique,"spinbutton28");
annee = lookup_widget (objet_graphique,"spinbutton29");
po = lookup_widget (objet_graphique,"entry52");



tr.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
tr.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
tr.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));



strcpy(tr.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
strcpy(tr.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(tr.pd,gtk_entry_get_text(GTK_ENTRY(po)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

modi_mah(id,tr);
        GtkWidget* p=lookup_widget(objet_graphique,"treeview10");
d=0;
n=0;
        Afficherr(p,"troupeaux.txt");
}


void
on_affi_ad_ay_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *emarque;

char marque[20];
   char etat [20];
   int nb1=0;
int nb2=0;
int nb3=0;
int nb4=0;
int max,x,y;
      
  FILE* F;

F=fopen("marque.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F,"%s %s\n",marque,etat)!=EOF)
    {
        if((strcmp(marque,"marqueA")==0)&&(strcmp(etat,"0")==0))
        nb1++;
                                             
 if(strcmp(marque,"marqueB")==0)
{
      if(strcmp(etat,"0")==0)
      nb2++;
 }
 if(strcmp(marque,"marqueC")==0)
{
      if(strcmp(etat,"0")==0)
      nb3++;
 }
 if(strcmp(marque,"marqueD")==0)
{
      if(strcmp(etat,"0")==0)
      nb4++;
 }

if(nb1>nb2)
x=nb1;
else
{
    x=nb2;
}
if(nb3>nb4)
y=nb3;
else
{
    y=nb4;
}
if(x>y)
max=x;
else
{
    max=y;
}

if(max==nb1){
    strcpy(marque,"marqueA");
}
if(max==nb2){
    strcpy(marque,"marqueB");
}
if(max==nb3){
    strcpy(marque,"marqueC");
}
if(max==nb4){
    strcpy(marque,"marqueD");
}

}

fclose(F);
emarque = lookup_widget(button, "label105");
gtk_label_set_text(GTK_LABEL(emarque),marque);



}
}




void
on_actu_ad_ay_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview7");
	gchar *type;
        gchar *maintenance;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
         {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&maintenance,3,&etat,4,&date,5,&nb,-1);
  	GtkWidget *dd,*type,*maintenance,*etate,*date,*ty,*se,*da,*po;
	 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry29")),id);
	dd = lookup_widget (objet,"entry29");
	type = lookup_widget(objet, "label120");
	maintenance = lookup_widget(objet, "label121");
	etate = lookup_widget(objet, "label122");
	date = lookup_widget(objet, "label123");

	ty = lookup_widget (objet,"entry30");
	se = lookup_widget (objet,"entry31");
	da = lookup_widget (objet,"combobox9");
	po = lookup_widget (objet,"entry32");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	equip A= rech_ay(id);

	gtk_label_set_text(GTK_LABEL(type),A.type);
	gtk_label_set_text(GTK_LABEL(maintenance),A.maintenance);
	gtk_label_set_text(GTK_LABEL(etate),A.etate);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.type);
	gtk_entry_set_text(GTK_LABEL(se),A.maintenance);
	gtk_label_set_text(GTK_LABEL(da),A.etate);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
		
        gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook5")));//redirection vers la page precedente
}

//mise a jour treeview
afficher_ad_ay(p ,"equipement.txt");

}


void
on_ajou_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labelty,*labelmain,*labeldate;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
equip A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "1a2z3e4r5t6y7u8i9opqsdfghjklmwxcvbn";
int b=1;
ty = lookup_widget (objet_graphique,"entry26");
se = lookup_widget (objet_graphique,"entry27");
da = lookup_widget (objet_graphique,"combobox8");
po = lookup_widget (objet_graphique,"entry28");
nb = lookup_widget (objet_graphique,"spinbutton34");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));

strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.maintenance,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.etate,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));


 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);

labelty=lookup_widget(objet_graphique,"label266");
labelmain=lookup_widget(objet_graphique,"label267");
labeldate=lookup_widget(objet_graphique,"label268");




// controle saisie
if(strcmp(A.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir type! ");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.maintenance,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir maintenance !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_ay(A);
}
//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview7");
afficher_ad_ay(p ,"equipement.txt");

}




void
on_rech_ad_ay_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *dd,*type,*maintenance,*etate,*date,*ty,*se,*da,*po,*lb;



dd = lookup_widget (button,"entry29");
type = lookup_widget(button, "label120");
maintenance = lookup_widget(button, "label121");
etate = lookup_widget(button, "label122");
date = lookup_widget(button, "label123");

ty = lookup_widget (button,"entry30");
se = lookup_widget (button,"entry31");
da = lookup_widget (button,"combobox9");
po = lookup_widget (button,"entry32");
lb= lookup_widget(button, "label378");

char idd[20];

int xr=-1;
char type1[20];
char maintenance1[20];
char date1[20];
char nb1[20];
char id[20];
char etate1[20];

FILE *F;



strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xr=1;
      } 
     } 
    
     fclose (F);
  }

if(xr==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    equip A= rech_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */
gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(maintenance),A.maintenance);
gtk_label_set_text(GTK_LABEL(etate),A.etate);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.maintenance);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}


void
on_modi_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;


/////////////////////////////////////////////////////////////////

int v=-1;
char id[20];
char idd[20];
char type1[20];
char maintenance1[20];
char etate1[20];
char date1[20];
char nb1[20];
equip U ;

dd = lookup_widget (objet_graphique,"entry29");
ty = lookup_widget (objet_graphique,"entry30");
se = lookup_widget (objet_graphique,"entry31");
da = lookup_widget (objet_graphique,"combobox9");
po = lookup_widget (objet_graphique,"entry32");
nb = lookup_widget (objet_graphique,"spinbutton35");

lb = lookup_widget (objet_graphique,"label378");

FILE *F;

F = fopen ("equipement.txt", "r");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

if(v==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.maintenance,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.etate,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));

modi_ay(id,U);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview7");
afficher_ay(p ,"equipement.txt");
//////////////////////////////////////////////////////////////////

}


void
on_supp_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int xs=-1;
char type[20];
char maintenance[20];
char date[20];
char etate[20];
char id[20];
char nb [20];

lb = lookup_widget (objet_graphique,"label378");
dd = lookup_widget (objet_graphique,"entry29");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type,maintenance,etate,date,nb) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xs=1;
      } 
     } 
    
     fclose (F);
  }

if(xs==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}



//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview7");
afficher_ad_ay(p ,"equipement.txt");
}


void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *lb,*username,*password,*authen,*windowEspaceAdmin,*windowtoup,*windowcapt,*windowequi;
GtkWidget *treeview,*treeView4 ,*p;
char user[20];
char pasw[20];
int trouve=0;
int x=-1;
lb = lookup_widget (button,"label314");
username = lookup_widget (button,"us");
password = lookup_widget (button,"Pw");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
FILE *f=NULL;
util t;
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin)!=EOF)
{
if((strcmp(t.User,user)==0)&&(strcmp(t.Pass,pasw)==0))
{
x=1;
}

}
if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"compte n'existe pas ");
}else
{
   trouve=verif(user,pasw); 
    
}



fclose(f);
}






if(trouve==1)
{
    
authen=lookup_widget(button,"auth");
gtk_widget_destroy(authen);
windowequi=create_Gestion_equipment();
gtk_widget_show(windowequi);  
}
if(trouve==2)
{
windowtoup=create_Gestion__troupeaux_();

	int m=0,n=0,h=0,d=0,g=0,c=0;




 GtkWidget* pr=lookup_widget(button,"treeview4");
nbr_troupeaux_mah();
Afficherrr(pr,"nb.txt");

	
   
authen=lookup_widget(button,"auth");
gtk_widget_destroy(authen);
gtk_widget_show(windowtoup);
 
}
if(trouve==3)
{
authen=lookup_widget(button,"auth");
gtk_widget_destroy(authen);
windowcapt=create_Gestion_ouvrier();
gtk_widget_show(windowcapt);  
}
if(trouve==4)
{
authen=lookup_widget(button,"auth");
gtk_widget_destroy(authen);
windowEspaceAdmin=create_Admin();
gtk_widget_show(windowEspaceAdmin); 
}
}


void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ath,*fenetre_insc,*success;
success=lookup_widget(objet,"label261");
fenetre_ath=lookup_widget(objet,"auth");
gtk_widget_destroy(fenetre_ath);
fenetre_insc=create_inscription();
gtk_widget_show(fenetre_insc);
gtk_widget_hide(success);
}


void
on_button1_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ath,*fenetre_insc;
GtkWidget *use,*nom,*prenom,*pass,*choix,*num,*cin;
GtkWidget *labelCin,*labelnom,*labelprenom,*labelpass,*labeluser,*labeltel,*success;
int b=1;

labelCin=lookup_widget(objet,"label260");
labelnom=lookup_widget(objet,"label255");
labelprenom=lookup_widget(objet,"label256");
labelpass=lookup_widget(objet,"label258");
labeluser=lookup_widget(objet,"label257");
labeltel=lookup_widget(objet,"label259");




util t;


nom = lookup_widget (objet,"nom");
prenom = lookup_widget (objet,"prenom");
use = lookup_widget (objet,"user");
pass = lookup_widget (objet,"Pass");
choix = lookup_widget (objet,"combobox1");
num = lookup_widget (objet,"num");
cin = lookup_widget (objet,"cin");



strcpy(t.Nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(t.Prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(t.User,gtk_entry_get_text(GTK_ENTRY(use)));
strcpy(t.Pass,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(t.Num,gtk_entry_get_text(GTK_ENTRY(num)));
strcpy(t.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(t.Choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));




 



// controle saisie
if(strcmp(t.Cin,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelCin),"saisir cin !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelCin),"");
}

if(strcmp(t.Nom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir nom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}
if(strcmp(t.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prenom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}

if(strcmp(t.Num,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeltel),"saisir Num tel !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeltel),"");
}

if(strcmp(t.User,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeluser),"saisir username !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeluser),"");
}


if(strcmp(t.Pass,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelpass),"saisir password !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelpass),"");
}



if(b==1){
        
ajouter(t);


fenetre_insc=lookup_widget(objet,"inscription");
gtk_widget_destroy(fenetre_insc);
fenetre_ath=create_auth();
gtk_widget_show(fenetre_ath);

        }

}


void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelsexe,*labelcin,*labelnt,*labelmail;
ouvrier o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
int b=1;
No = lookup_widget (objet,"entry10");
Pr = lookup_widget (objet,"entry11");
ci = lookup_widget (objet,"entry12");
Am = lookup_widget (objet,"entry14");
Nt = lookup_widget (objet,"entry13");
jour = lookup_widget (objet,"spinbutton2");
mois = lookup_widget (objet,"spinbutton3");
annee = lookup_widget (objet,"spinbutton4");
se = lookup_widget (objet,"combobox6");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
labelnom=lookup_widget(objet,"label333");
labelprenom=lookup_widget(objet,"label334");
labelsexe=lookup_widget(objet,"label335");
labelcin=lookup_widget(objet,"label336");
labelnt=lookup_widget(objet,"label337");
labelmail=lookup_widget(objet,"label338");




// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.num_tl,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir votre numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.Mail,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"saisir Mail !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmail),"");
}
if(b==1){
Ajouter_ch( o);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"ouvrier.txt");



}


void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char sexe[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char num_tl[20];
char Mail[20];
lb = lookup_widget (objet,"label332");
dd = lookup_widget (objet,"entry15");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("ouvrier.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,sexe,CIN,num_tl,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"ouvrier.txt");
}


void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *dd,*Nm,*Pnom,*cin,*SEXE,*Jour,*Mois,*Num,*Annee,*mail,*lb;

char id[20];
char NOM[20];
char Prenom[20];
char sexe[20];
char CIN[20];
char num_tl[20];
char jour[20];
char mois[20];
char annee[20];
char Mail[20];
char idd[20];
ouvrier o ;
int x=-1;
FILE *F;

dd = lookup_widget (button,"entry16");
Nm = lookup_widget(button, "entry17");
Pnom = lookup_widget(button, "entry18");
SEXE = lookup_widget(button, "label355");
cin = lookup_widget (button,"entry19");
Num = lookup_widget(button, "entry20");
Jour = lookup_widget(button, "spinbutton6");
Mois = lookup_widget(button, "spinbutton6");
Annee = lookup_widget(button, "spinbutton7");
mail = lookup_widget(button, "entry21");
lb = lookup_widget(button, "label354");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("ouvrier.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,sexe,CIN,num_tl,jour,mois,annee,Mail) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(SEXE),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(Num),"");
gtk_entry_set_text(GTK_LABEL(mail),"");
}else
{
    ouvrier o = rechercher_ouvrier(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");/* code */


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(SEXE),o.sexe);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(Num),o.num_tl);
gtk_entry_set_text(GTK_LABEL(mail),o.Mail);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),jour);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),mois);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),annee);

}

}


void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
ouvrier o;
char id[20];


dd = lookup_widget (objet_graphique,"entry16");
no = lookup_widget (objet_graphique,"entry17");
pr = lookup_widget (objet_graphique,"entry18");
se = lookup_widget (objet_graphique,"combobox7");
ci = lookup_widget (objet_graphique,"entry19");
nt = lookup_widget (objet_graphique,"entry20");
jour = lookup_widget (objet_graphique,"spinbutton5");
mois = lookup_widget (objet_graphique,"spinbutton6");
annee = lookup_widget (objet_graphique,"spinbutton7");
am = lookup_widget (objet_graphique,"entry21");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.num_tl,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.Mail,gtk_entry_get_text(GTK_ENTRY(am)));
modi_ch(id,o);

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
affi_ch(p,"ouvrier.txt");
}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *Mail;
        gchar *num_tl;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&sexe,4,&CIN,5,&num_tl,6,&jour,7,&mois,8,&annee,9,&Mail,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry16")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry17")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry18")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry19")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry20")),num_tl);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry21")),Mail);

		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook3")));//redirection vers la page precedente








         
}
//mise a jour treeview

affi_ch(p,"ouvrier.txt");
}


void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_affi_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affi,*fenetre_affi1 ;
GtkWidget *da;
GtkWidget *treeView6;
char s[20];
int annee;
da = lookup_widget (objet,"entry22");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
taux_dab(annee);
treeView6=lookup_widget(objet,"treeview6");
affi_abs(treeView6,"Absent.txt");
}


void
on_quit_ay_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *auth,*Gestion_equipment;


  Gestion_equipment = lookup_widget(objet,"Gestion_equipment");
  gtk_widget_destroy (Gestion_equipment);
///////////////////////////////////////
  auth = create_auth ();
  gtk_widget_show (auth);
}



void
on_affi_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *emarque;

char marque[20];
   char etat [20];
   int nb1=0;
int nb2=0;
int nb3=0;
int nb4=0;
int max,x,y;
      
  FILE* F;

F=fopen("marque.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F,"%s %s\n",marque,etat)!=EOF)
    {
        if((strcmp(marque,"marqueA")==0)&&(strcmp(etat,"0")==0))
        nb1++;
                                             
 if(strcmp(marque,"marqueB")==0)
{
      if(strcmp(etat,"0")==0)
      nb2++;
 }
 if(strcmp(marque,"marqueC")==0)
{
      if(strcmp(etat,"0")==0)
      nb3++;
 }
 if(strcmp(marque,"marqueD")==0)
{
      if(strcmp(etat,"0")==0)
      nb4++;
 }

if(nb1>nb2)
x=nb1;
else
{
    x=nb2;
}
if(nb3>nb4)
y=nb3;
else
{
    y=nb4;
}
if(x>y)
max=x;
else
{
    max=y;
}

if(max==nb1){
    strcpy(marque,"marqueA");
}
if(max==nb2){
    strcpy(marque,"marqueB");
}
if(max==nb3){
    strcpy(marque,"marqueC");
}
if(max==nb4){
    strcpy(marque,"marqueD");
}

}

fclose(F);
emarque = lookup_widget(button, "label11");
gtk_label_set_text(GTK_LABEL(emarque),marque);



}
}



void
on_actu_ay_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");
	gchar *type;
        gchar *maintenance;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&maintenance,3,&etat,4,&date,5,&nb,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry1")),id);

GtkWidget *dd,*type,*maintenance,*etate,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entry1");
	type = lookup_widget(objet,"label23");
	maintenance = lookup_widget(objet,"label24");
	etate = lookup_widget(objet, "label25");
	date = lookup_widget(objet, "label26");

	ty = lookup_widget (objet,"entry2");
	se = lookup_widget (objet,"entry3");
	da = lookup_widget (objet,"combobox2");
	po = lookup_widget (objet,"entry5");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	equip A= rech_ay(id);

	gtk_label_set_text(GTK_LABEL(type),A.type);
	gtk_label_set_text(GTK_LABEL(maintenance),A.maintenance);
	gtk_label_set_text(GTK_LABEL(etate),A.etate);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.type);
	gtk_entry_set_text(GTK_LABEL(se),A.maintenance);
	gtk_label_set_text(GTK_LABEL(da),A.etate);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook1")));//redirection vers la page precedente
}

//mise a jour treeview
afficher_ay(p ,"equipement.txt");

}

void
on_rech_ay_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*type,*maintenance,*etate,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int xr=-1;
char type1[20];
char maintenance1[20];
char date1[20];
char nb1[20];
char id[20];
char etate1[20];

FILE *F;
dd = lookup_widget (button,"entry1");
type = lookup_widget(button, "label23");
maintenance = lookup_widget(button, "label24");
etate = lookup_widget(button, "label25");
date = lookup_widget(button, "label26");
lb= lookup_widget(button, "label19");

ty = lookup_widget (button,"entry2");
se = lookup_widget (button,"entry3");
da = lookup_widget (button,"combobox2");
po = lookup_widget (button,"entry5");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");

if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xr=1;
      } 
     } 
    
     fclose (F);
  }

if(xr==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(dd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    equip A= rech_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */
gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(maintenance),A.maintenance);
gtk_label_set_text(GTK_LABEL(etate),A.etate);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.maintenance);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}

}


void
on_Modi_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char type1[20];
char maintenance1[20];
char etate1[20];
char date1[20];
char nb1[20];
equip U ;

dd = lookup_widget (objet_graphique,"entry1");
ty = lookup_widget (objet_graphique,"entry2");
se = lookup_widget (objet_graphique,"entry3");
da = lookup_widget (objet_graphique,"combobox2");
po = lookup_widget (objet_graphique,"entry5");
nb = lookup_widget (objet_graphique,"spinbutton35");
lb = lookup_widget (objet_graphique,"label19");

FILE *F;

F = fopen ("equipement.txt", "r");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));
if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type1,maintenance1,etate1,date1,nb1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

if(v==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");/* code */

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.maintenance,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.etate,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));

modi_ay(id,U);
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_ay(p ,"equipement.txt");
}


void
on_ajou_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
equip A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "1a2z3e4r5t6y7u8i9opqsdfghjklmwxcvbn";
int b=1;

ty = lookup_widget (objet_graphique,"entry6");
se = lookup_widget (objet_graphique,"entry7");
da = lookup_widget (objet_graphique,"combobox3");
po = lookup_widget (objet_graphique,"entry9");
nb = lookup_widget (objet_graphique,"spinbutton33");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.maintenance,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.etate,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"label263");
labelmain=lookup_widget(objet_graphique,"label264");
labeldate=lookup_widget(objet_graphique,"label265");

 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);


// controle saisie
if(strcmp(A.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir type !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.maintenance,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir maintenance !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_ay(A);
}
//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_ay(p ,"equipement.txt");
}

void
on_supp_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int xs=-1;
char type[20];
char maintenance[20];
char date[20];
char etate[20];
char id[20];
char nb [20];

lb = lookup_widget (objet_graphique,"label19");
dd = lookup_widget (objet_graphique,"entry1");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("equipement.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s \n",id,type,maintenance,etate,date,nb) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      xs=1;
      } 
     } 
    
     fclose (F);
  }

if(xs==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ay(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}


//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview1");
afficher_ay(p ,"equipement.txt");
}

void
on_actu_mah_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview3");
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}
}

void
on_rech_affi_mah_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*nb,*treeview;

int n;
char type[20];

ty = lookup_widget (objet_graphique,"combobox24");
nb = lookup_widget(objet_graphique, "spinbutton1");

strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
n=nb_troupeaux_mah(type);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(nb),n);



GtkWidget* pr=lookup_widget(objet_graphique,"treeview4");
nbr_troupeaux_mah();
h=0;
m=0;
Afficherrr2(pr,"nb.txt");
}


void
on_supp_mah2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
char ID1[20];
FILE *F;
int x=-1;
char type[20];
char sexe[20];
char date[20];
char pd[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
lb = lookup_widget (button,"label295");
dd = lookup_widget (button,"entry33");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("troupeaux.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type,sexe,jour,mois,annee,pd) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_mah(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}


GtkWidget* p=lookup_widget(button,"treeview3");
h=0;
m=0;
        Afficherr2(p,"troupeaux.txt");
}


void
on_rech_mah2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb,*ty,*se,*jo,*pdd,*mo,*an,*po;
char idd[20];

int x=-1;
char type[20];
char sexe[20];
char date[20];
char pd[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
FILE *F;

lb = lookup_widget (button,"label363");
dd = lookup_widget (button,"entry35");
ty = lookup_widget(button, "label358");
se = lookup_widget(button, "label359");
jo = lookup_widget(button, "spinbutton8");
mo = lookup_widget(button, "spinbutton9");
an = lookup_widget(button, "spinbutton10");
pdd = lookup_widget(button, "label360");


po = lookup_widget (button,"entry34");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("troupeaux.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s \n",id,type,sexe,jour,mois,annee,pd) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
   gtk_label_set_text(GTK_LABEL(ty),"");
gtk_label_set_text(GTK_LABEL(se),"");
gtk_label_set_text(GTK_LABEL(pdd),"");
gtk_entry_set_text(GTK_LABEL(po),"");
}else
{
    troupeaux s=rech_mah(idd);
    gtk_label_set_text(GTK_LABEL(lb),"1 trouve");
    gtk_label_set_text(GTK_LABEL(ty),s.type);
gtk_label_set_text(GTK_LABEL(se),s.sexe);
gtk_label_set_text(GTK_LABEL(pdd),s.pd);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jo),s.dt_ns.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mo),s.dt_ns.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(an),s.dt_ns.annee);
gtk_entry_set_text(GTK_LABEL(po),s.pd);
}







}


void
on_modi_mah2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*jour,*mois,*annee,*po,*dd;
troupeaux tr;
char id[20];


dd = lookup_widget (objet_graphique,"entry35");
ty = lookup_widget (objet_graphique,"combobox10");
se = lookup_widget (objet_graphique,"combobox11");
jour = lookup_widget (objet_graphique,"spinbutton11");
mois = lookup_widget (objet_graphique,"spinbutton12");
annee = lookup_widget (objet_graphique,"spinbutton13");
po = lookup_widget (objet_graphique,"entry34");



tr.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
tr.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
tr.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));



strcpy(tr.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
strcpy(tr.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(tr.pd,gtk_entry_get_text(GTK_ENTRY(po)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

modi_mah(id,tr);
 GtkWidget* p=lookup_widget(objet_graphique,"treeview3");
h=0;
m=0;
        Afficherr2(p,"troupeaux.txt");
}


void
on_ajou_ad_mah_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview,*ty,*se,*jour,*mois,*annee,*po;
GtkWidget *labeltype,*labelsexe,*labelsucc,*labeldate,*labelpoids;
char poid[20];
char id[20];
int b=1;
troupeaux c;
int i, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8ij8klm9npq0rstuvwxyz";

labeltype=lookup_widget(objet_graphique,"label373");
labelsexe=lookup_widget(objet_graphique,"label374");
labeldate=lookup_widget(objet_graphique,"label377");
labelpoids=lookup_widget(objet_graphique,"label366");
labelsucc=lookup_widget(objet_graphique,"label375");

ty = lookup_widget (objet_graphique,"combobox20");
se = lookup_widget (objet_graphique,"combobox23");
jour = lookup_widget (objet_graphique,"spinbutton30");
mois = lookup_widget (objet_graphique,"spinbutton31");
annee = lookup_widget (objet_graphique,"spinbutton32");
po = lookup_widget (objet_graphique,"entry53");



c.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(c.pd,gtk_entry_get_text(GTK_ENTRY(po)));



 
    
 
    longueurChaine = strlen(chaine);

    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }
    
strcpy(c.id,id);
 


// controle saisie
if(strcmp(c.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labeltype),"saisir type !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeltype),"");
}

if(strcmp(c.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}


if(strcmp(c.pd,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelpoids),"saisir poids !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelpoids),"");
}

if(c.dt_ns.jour==1){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir jour !");

}


if(c.dt_ns.mois==1){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir mois !");

}




if(c.dt_ns.annee==2000){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir annee !");

}


if(b==1){
ajouter_mah(c);
gtk_label_set_text(GTK_LABEL(labeldate),"");
gtk_label_set_text(GTK_LABEL(labeldate),"Ajouter avec succes !");

}



//mise a jour du treeView//
        GtkWidget* p=lookup_widget(objet_graphique,"treeview10");
d=0;
n=0;
        Afficherr(p,"troupeaux.txt");
}



void
on_ajou_mah2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview,*ty,*se,*jour,*mois,*annee,*po;
GtkWidget *labeltype,*labelsucc,*labelsexe,*labeldate,*labelpoids;
char poid[20];
char id[20];
int b=1;

troupeaux c;
int i, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8ij8klm9npq0rstuvwxyz";

labeltype=lookup_widget(objet_graphique,"label290");
labelsexe=lookup_widget(objet_graphique,"label291");
labeldate=lookup_widget(objet_graphique,"label362");
labelpoids=lookup_widget(objet_graphique,"label293");
labelsucc=lookup_widget(objet_graphique,"label375");





ty = lookup_widget (objet_graphique,"combobox22");
se = lookup_widget (objet_graphique,"combobox13");
jour = lookup_widget (objet_graphique,"spinbutton14");
mois = lookup_widget (objet_graphique,"spinbutton15");
annee = lookup_widget (objet_graphique,"spinbutton16");
po = lookup_widget (objet_graphique,"entry36");



c.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
c.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
c.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(c.pd,gtk_entry_get_text(GTK_ENTRY(po)));



 
    
 
    longueurChaine = strlen(chaine);

    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }
    
strcpy(c.id,id);

 
// controle saisie
if(strcmp(c.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labeltype),"saisir type !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeltype),"");
}

if(strcmp(c.sexe,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"saisir sexe !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelsexe),"");
}


if(strcmp(c.pd,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelpoids),"saisir poids !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelpoids),"");
}

if(c.dt_ns.jour==1){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir jour !");

}


if(c.dt_ns.mois==1){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir mois !");

}




if(c.dt_ns.annee==2000){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir annee !");

}



if(b==1){
ajouter_mah(c);
gtk_label_set_text(GTK_LABEL(labeldate),"");
gtk_label_set_text(GTK_LABEL(labeldate),"Ajouter avec succes !");

}





//mise a jour du treeView
        GtkWidget* p=lookup_widget(objet_graphique,"treeview3");
h=0;
m=0;
        Afficherr2(p,"troupeaux.txt");
}





void
on_quit_ad_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_auth,*fenetre_admin;

fenetre_admin=lookup_widget(button,"Admin");
gtk_widget_destroy(fenetre_admin);
fenetre_auth=create_auth();
gtk_widget_show(fenetre_auth);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkWidget *objet;
        gchar *id;
        GtkTreeModel *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(objet,"treeview3");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		/*gtk_widget_hide(lookup_widget(gestion,"label37"));//cacher label modifier avec succees*/
		
                gtk_tree_model_get (model,&iter,0,&id,-1);//recuperer les information de la ligne selectionneé
		//remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry34")),id);
               


/*
                GtkWidget* msgCin=lookup_widget(gestion,"label20");
                GtkWidget* msg1=lookup_widget(gestion,"label36");
                gtk_label_set_text(GTK_LABEL(msgCin),cin);
                gtk_widget_show(msgCin);
                gtk_widget_show(msg1);*/
               // gtk_widget_show(lookup_widget(gestion,"button4"));//afficher le bouton modifier//
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook2")));//redirection vers la page precedente
        }

}


void
on_supp_tree_ad_ay_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview7");;
        //GtkWidget *label;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ay( id);// supprimer la ligne du fichier
}
}

void
on_supp_tree_ay_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview1");;

        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ay( id);// supprimer la ligne du fichier
}
}


void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.youtube.com/");
}


void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/");
}


void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/");
}


void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview5");;
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}

}


void
on_supp_ch2_tree_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview8");
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier

}
}


void
on_modi2_tree_mah_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview10");

	gchar *type;
        gchar *sexe;
        gchar *jour;
        gchar *mois;
        gchar *annee;
        gchar *pd;
      


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&sexe,3,&jour,4,&mois,5,&annee,6,&pd,-1);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label368")),type);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label367")),sexe);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label205")),pd);
   gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry51")),id);
   gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry52")),pd);



		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook8")));//redirection vers la page precedente
}
//mise a jour du treeView
    d=0;
n=0;  

        Afficherr(p,"troupeaux.txt");
}


void
on_modi_tree_mah_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview3");

     	gchar *type;
        gchar *sexe;
        gchar *jour;
        gchar *mois;
        gchar *annee;
        gchar *pd;
    


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&sexe,3,&jour,4,&mois,5,&annee,6,&pd,-1);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label358")),type);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label359")),sexe);
   gtk_label_set_text(GTK_LABEL(lookup_widget(objet_graphique,"label360")),pd);
   gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry35")),id);
   gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry34")),pd);










		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook2")));//redirection vers la page precedente
}
//mise a jour du treeView
h=0;
m=0;

        Afficherr2(p,"troupeaux.txt");
}


void
on_recl_ay_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *Gestion_equipment,*espace_reclamation_ ; 

////////////////////////////////////////////////////////
  Gestion_equipment = lookup_widget(button,"Gestion_equipment");
  gtk_widget_destroy (Gestion_equipment);
  espace_reclamation_ = create_espace_reclamation_ ();
  gtk_widget_show (espace_reclamation_);
}
int x;
int t[2]={0,0};

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}   
}


void
on_ok_ay_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label234");

gtk_label_set_text(GTK_LABEL(output),ch3);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 
}


void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 

}


void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 


}


void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    

}


void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}  

}


void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(objet, "label356");

gtk_label_set_text(GTK_LABEL(output),ch3);





}


void
on_button6_rec_ouvrier_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{

char id[20];
int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";

GtkWidget *rec,*ob;
char objet1[200];
char reclamation[200];

FILE *F=NULL;
ob = lookup_widget (objet,"entry55");
rec = lookup_widget (objet,"entry56");
strcpy(objet1,gtk_entry_get_text(GTK_ENTRY(ob)));
strcpy(reclamation,gtk_entry_get_text(GTK_ENTRY(rec)));
 

F=fopen("reclamation.txt","a");

 longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }








if(F!=NULL)
{

    fprintf(F,"%.4s %.200s %.200s\n",id,objet1,reclamation);
    fclose(F);


}


}


void
on_button7_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";

char id[20];

GtkWidget *rec,*ob;
char objet1[200];
char reclamation[200];


ob = lookup_widget (objet,"entry57");
rec = lookup_widget (objet,"entry58");
strcpy(objet1,gtk_entry_get_text(GTK_ENTRY(ob)));
strcpy(reclamation,gtk_entry_get_text(GTK_ENTRY(rec)));
 FILE *F=NULL;

F=fopen("reclamation.txt","a");






 longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }
if(F!=NULL)
{

    fprintf(F,"%.4s %.200s %.200s\n",id,objet1,reclamation);
    fclose(F);


}

}


void
on_button8_ajou_tr_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
char id[20];
GtkWidget *rec,*ob;
char objet1[200];
char reclamation[200];


ob = lookup_widget (objet,"entry59");
rec = lookup_widget (objet,"entry60");
strcpy(objet1,gtk_entry_get_text(GTK_ENTRY(ob)));
strcpy(reclamation,gtk_entry_get_text(GTK_ENTRY(rec)));
 FILE *F=NULL;

F=fopen("reclamation.txt","a");


 longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }


if(F!=NULL)
{

    fprintf(F,"%.4s %.200s %.200s\n",id,objet1,reclamation);
    fclose(F);


}

}


void
on_button_supp_rec_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[20];
char objet1[200];
char reclamation[200];
 FILE *F,*FW;
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview14");


        gchar *ID;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&ID,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           
 
  
F = fopen ("reclamation.txt", "r");
FW = fopen ("rec.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {
  while (fscanf (F,"%s %s %s\n",id,objet1,reclamation) != EOF)
    if (strcmp (ID,id) != 0)
      fprintf (FW,"%s %s %s\n",id,objet1,reclamation);
  fclose (F);
  fclose (FW);
remove("reclamation.txt");
rename("rec.txt", "reclamation.txt");

}


}



Affi_rec(p,"reclamation.txt");


}


void
on_button9_retour_ouvrier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ouvrier,*fenetre_rec ; 
fenetre_ouvrier=lookup_widget(objet,"espace_reclamation_");
gtk_widget_destroy(fenetre_ouvrier);
fenetre_ouvrier=create_Gestion_ouvrier();
gtk_widget_show(fenetre_ouvrier);
}


void
on_button10_retour_equipement_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_equipment,*espace_reclamation_ ;  
/////////////////////////////////////////////
  espace_reclamation_ = lookup_widget(button,"espace_reclamation_");
  gtk_widget_destroy (espace_reclamation_);
  Gestion_equipment = create_Gestion_equipment ();
  gtk_widget_show (Gestion_equipment);
}


void
on_button11_retour_troupeaux_clicked   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_troupeaux,*fenetre_rec ; 
fenetre_troupeaux=lookup_widget(objet,"espace_reclamation_");
gtk_widget_destroy(fenetre_troupeaux);
fenetre_troupeaux=create_Gestion__troupeaux_();
gtk_widget_show(fenetre_troupeaux);
}


void
on_button8_ret_ad_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *responsable,*fenetre_ad ; 
responsable=lookup_widget(objet_graphique,"espace_responsable_");
gtk_widget_destroy(responsable);
fenetre_ad=create_Admin();
gtk_widget_show(fenetre_ad);



}
int a;
int z[2]={0,0};

void
on_button7_ok_mah_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (a==1) 
strcpy(ch2," jour ");
 else  
strcpy(ch2,"  nuit ");
 if (z[0]==1)
 strcat(ch3," Groupe A "); 
if(z[1]==1)
 strcat (ch3,"  Groupe B ");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(button, "label302");

gtk_label_set_text(GTK_LABEL(output),ch3);
}


void
on_radiobutton10_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {a=2;} 
}



void
on_checkbutton11_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 
  {z[0]=1;} 
}


void
on_checkbutton12_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) 

   {z[1]=1;} 
}


void
on_radiobutton9_mah_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{a=1;} 
}


void
on_button8_rec_mah_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
  GtkWidget *fenetre_troupeaux,*fenetre_rec ; 
fenetre_troupeaux=lookup_widget(objet,"Gestion__troupeaux_");
gtk_widget_destroy(fenetre_troupeaux);
fenetre_rec=create_espace_reclamation_();
gtk_widget_show(fenetre_rec);
}


void
on_button8_re_login_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *fenetre_troupeaux,*fenetre_auth ;
fenetre_troupeaux=lookup_widget(button,"Gestion__troupeaux_");
gtk_widget_destroy(fenetre_troupeaux);
fenetre_auth=create_auth();
gtk_widget_show(fenetre_auth);
}


void
on_button10_affi_lait1_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affi,*fenetre_affi1 ;
GtkWidget *da;
GtkWidget *treeView8;
char s[20];
int annee;
da = lookup_widget (button,"entry62");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
moyenne(annee);
c=0;
treeView8=lookup_widget(button,"treeview16");
Affi_mah_l(treeView8,"moy.txt");
}


void
on_button9_affi_lait2_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affi,*fenetre_affi1 ;
GtkWidget *da;
GtkWidget *treeView6;
char s[20];
int annee;
da = lookup_widget (button,"entry61");
strcpy(s,gtk_entry_get_text(GTK_ENTRY(da)));
annee=atoi(s);
moyenne(annee);
treeView6=lookup_widget(button,"treeview15");
Affi_mahh(treeView6,"moy.txt");
}


void
on_button7_quiter_ouv_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_ouvrier,*fenetre_auth ;
fenetre_ouvrier=lookup_widget(button,"Gestion_ouvrier");
gtk_widget_destroy(fenetre_ouvrier);
fenetre_auth=create_auth();
gtk_widget_show(fenetre_auth);

}


void
on_button8_reclamation_ouv_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *fenetre_ouvrier,*fenetre_rec ; 
fenetre_ouvrier=lookup_widget(objet,"Gestion_ouvrier");
gtk_widget_destroy(fenetre_ouvrier);
fenetre_rec=create_espace_reclamation_();
gtk_widget_show(fenetre_rec);
}

