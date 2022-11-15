#include <gtk/gtk.h>
typedef struct {
    char Nom[20];
char Prenom[20];
char User[20];
char Pass[20];
char Choix[20];
char Num[20];
char Cin[20];
}util;
int verif(char log[], char Pw[]);
void ajouter(util t);
void Affi_rec(GtkWidget* treeview1,char*l);