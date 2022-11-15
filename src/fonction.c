#include "fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "troupeaux.h"


GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

int verif(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
util t;
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin)!=EOF)
{
if((strcmp(t.User,log)==0)&&(strcmp(t.Pass,Pw)==0))
{
if(strcmp(t.Choix,"Technicien1")==0)
trouve=1;
else if(strcmp(t.Choix,"Technicien2")==0)
trouve=2;
else if(strcmp(t.Choix,"RH")==0)
trouve=3;
else if(strcmp(t.Choix,"Admin")==0)
trouve=4;
}

}
fclose(f);
}
return (trouve);
}

void ajouter(util t)
{
    FILE *f=NULL;

f=fopen("utilisateur.txt","a");
if(f!=NULL)
{

    fprintf(f,"%s %s %s %s %s %s %s\n",t.Nom,t.Prenom,t.User,t.Pass,t.Choix,t.Num,t.Cin);
    fclose(f);
    

}


}




void Affi_rec(GtkWidget* treeview1,char*l)
{

char id[20];
char objet1[200];
char reclamation[200];


        /* Creation du modele */
        adstore = gtk_list_store_new(3,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s\n",id,objet1,reclamation)!= EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,objet1,
                            2,reclamation,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(p==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("OBJET",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("RECLAMATION",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	p++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}







