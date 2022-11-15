#include <gtk/gtk.h>
typedef struct
{
    int jour;
    int mois;
    int annee;

}date;
typedef struct
{
char type[20];
char sexe[20];
char date[20];
char pd[20];
char id[20];
date dt_ns;
}troupeaux;

troupeaux rech_mah(char id[]);
void ajouter_mah(troupeaux c);
void Afficherr(GtkWidget* treeview1,char*l);
void Afficherr2(GtkWidget* treeview1,char*l);
int nb_troupeaux_mah(char type[]);
void supp_mah(char id[]);
void modi_mah(char id[],troupeaux tr);
