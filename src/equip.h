#include<gtk/gtk.h>
typedef struct 
{
char id[30];
char type[30];
char maintenance[30];
char etate[30];
char date[30];
int nb;
}equip ;

void ajouter_ay(equip A);
void supp_ay(char id[]);
equip rech_ay(char id[]);
void modi_ay(char id[], equip U);
void afficher_ay (GtkWidget *treeview1 ,char *l);
void afficher_ad_ay (GtkWidget *treeview1, char*l );
