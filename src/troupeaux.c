#include "troupeaux.h"
#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "callbacks.h"
#include <string.h>
#include <gtk/gtk.h>

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

void ajouter_mah(troupeaux c)
{
    FILE *F=NULL;

F=fopen("troupeaux.txt","a");
if(F!=NULL)
{

    fprintf(F,"%.4s %s %s %d %d %d %s \n",c.id,c.type,c.sexe,c.dt_ns.jour,c.dt_ns.mois,c.dt_ns.annee,c.pd);
    fclose(F);
    

}
}

void supp_mah(char id[])
{


  
  troupeaux d;

   FILE *F, *FW;
 
  
F = fopen ("troupeaux.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 
{

  while (fscanf (F, "%s %s %s %d %d %d %s \n", d.id,d.type,d.sexe,&d.dt_ns.jour,&d.dt_ns.mois,&d.dt_ns.annee,d.pd)!=EOF)
    if (strcmp (d.id, id) != 0)
      fprintf (FW, "%s %s %s %d %d %d %s \n", d.id,d.type,d.sexe,d.dt_ns.jour,d.dt_ns.mois,d.dt_ns.annee,d.pd);

  fclose (F);
  fclose (FW);
remove("troupeaux.txt");
rename("tr.txt", "troupeaux.txt");


}

}

troupeaux rech_mah(char id[]){

FILE *F;
  troupeaux q;
  troupeaux t;

F = fopen ("troupeaux.txt", "r");


  if (F!=NULL)
 {


    while (fscanf (F, "%s %s %s %d %d %d %s\n",q.id,q.type,q.sexe,&q.dt_ns.jour,&q.dt_ns.mois,&q.dt_ns.annee,q.pd)!=EOF)
    if (strcmp (q.id, id) == 0){
      
        strcpy(t.type,q.type);
        strcpy(t.sexe,q.sexe);
		t.dt_ns.jour=q.dt_ns.jour;
		t.dt_ns.mois=q.dt_ns.mois;
		t.dt_ns.annee=q.dt_ns.annee;
        strcpy(t.pd,q.pd);

    }
    
      return(t);

  fclose (F);
 }
}

void modi_mah(char id[],troupeaux tr)
{


  troupeaux c;
  
   FILE *F, *FW;
  
  
F = fopen ("troupeaux.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %d %d %d %s\n",c.id,c.type,c.sexe,&c.dt_ns.jour,&c.dt_ns.mois,&c.dt_ns.annee,c.pd)!=EOF)
    if (strcmp (c.id, id) == 0)
     {
fprintf (FW, "%s %s %s %d %d %d %s\n",id,tr.type,tr.sexe,tr.dt_ns.jour,tr.dt_ns.mois,tr.dt_ns.annee,tr.pd);

     }
     else
     {
       fprintf (FW, "%s %s %s %d %d %d %s\n", c.id,c.type,c.sexe,c.dt_ns.jour,c.dt_ns.mois,c.dt_ns.annee,c.pd);
     }
     
}
     
     

  fclose (F);
  fclose (FW);
remove("troupeaux.txt");
rename("tr.txt", "troupeaux.txt");




}




int nb_troupeaux_mah(char type[])
{

  FILE* F;

troupeaux n;
int nb=0;


F=fopen("troupeaux.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F, "%s %s %s %d %d %d %s\n",n.id,n.type,n.sexe,&n.dt_ns.jour,&n.dt_ns.mois,&n.dt_ns.annee,n.pd)!=EOF)
    {

      if(strcmp(n.type,type)==0)
      nb++;
    
}
fclose(F);
return(nb);


}
}



void Afficherr(GtkWidget* treeview1,char*l)
{

char id[30];
	char type[30];
	char sexe[30];
	char jour[30];
    char mois[30];
    char annee[30];
	char poid[30];


        /* Creation du modele */
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,type,sexe,jour,mois,annee,poid)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,sexe,
                            3,jour,
                            4,mois,
                            5,annee,
                            6,poid,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(h==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("POIDS",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	h++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

void Afficherr2(GtkWidget* treeview1,char*l)
{

char id[30];
	char type[30];
	char sexe[30];
	char jour[30];
    char mois[30];
    char annee[30];
	char poid[30];


        /* Creation du modele */
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",id,type,sexe,jour,mois,annee,poid)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,sexe,
                            3,jour,
                            4,mois,
                            5,annee,
                            6,poid,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(d==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("POIDS",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	d++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}