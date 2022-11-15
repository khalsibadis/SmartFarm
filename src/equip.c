
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "equip.h"
#include <string.h>
#include <time.h>

#include <stdio.h>



void ajouter_ay(equip A)
{
    FILE *F=NULL;

F=fopen("equipement.txt","a");
if(F!=NULL)
{

    fprintf(F,"%.4s %s %s %s %s %d\n",A.id,A.type,A.maintenance,A.etate,A. date,A.nb);
    fclose(F);
    

}

}
void supp_ay(char id[])
{
  
   FILE *F, *FW;
  equip D ;
  
F = fopen ("equipement.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %d ",D.id,D.type,D.maintenance,D.etate,D. date,&D.nb) == 6)
    if (strcmp (D.id, id) != 0)
      fprintf (FW, "%s %s %s %s %s %d \n", D.id,D.type,D.maintenance,D.etate,D. date,D.nb);
}
  fclose (F);
  fclose (FW);
remove("equipement.txt");
rename("tr.txt", "equipement.txt");




}
equip rech_ay(char id[])
{
char ch;
FILE *F;
  equip Q;
  equip A;
  
F = fopen ("equipement.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d ", Q.id,Q.type,Q.maintenance,Q.etate,Q. date, &Q.nb) != EOF)
    if (strcmp (Q.id, id) == 0)
        {
        strcpy(A.type,Q.type);
        strcpy(A.maintenance,Q.maintenance);
        strcpy(A.etate,Q.etate);
        strcpy(A.date,Q.date);
	
        }
        /*else
        {
        strcpy(A.type,"Not_Found_XD");
        strcpy(A.maintenance," ");  
        strcpy(A.etate," ");  
        strcpy(A.date," ");
       }*/
  }
  return (A);
  fclose (F);  
}



void modi_ay(char id [] , equip U) 
{
   FILE *F, *FW;
  equip c; 
  
F = fopen ("equipement.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d",c.id,c.type,c.maintenance,c.etate,c. date,&c.nb) ==6)
	
    if (strcmp (c.id, id) == 0)
     {

fprintf (FW, "%s %s %s %s %s %d\n",id,U.type,U.maintenance,U.etate,U. date,U.nb);

     }
     else
     {

       fprintf (FW, "%s %s %s %s %s %d \n", c.id,c.type,c.maintenance,c.etate,c. date,c.nb);
     }
}    

  fclose (F);
  fclose (FW);
remove("equipement.txt");
rename("tr.txt", "equipement.txt");

}
void afficher_ay (GtkWidget *treeview1, char*l )

{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


	char id[30];
	char type[30];
	char nb[30];
	char maintenance[30];
	char etate[30];
	char date[30];


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",id,type,maintenance,etate,date,nb)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,maintenance,
                            3,etate,
                            4,date,
			    5,nb,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(o==0)
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




	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MAINTENANCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NB",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	o++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}
void afficher_ad_ay (GtkWidget *treeview1, char*l )

{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


	char id[30];
	char type[30];
	char nb[30];
	char maintenance[30];
	char etate[30];
	char date[30];


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",id,type,maintenance,etate,date,nb)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,maintenance,
                            3,etate,
                            4,date,
			    5,nb,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(q==0)
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




	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MAINTENANCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NB",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	q++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

