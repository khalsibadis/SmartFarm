#include <gtk/gtk.h>

int i,j,k,l,m,n,h,d,o,q,r,c,g,p;


void
on_res__clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_quit_admin_activate                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_ch2__clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_ch2__clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_ch2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ch2__clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_actu_ch2_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_AFF_CH2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_actu_ad_mah_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_aff_mah_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_ad_mah_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ad_mah_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affi_ad_ay_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_actu_ad_ay_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajou_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rech_ad_ay_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_ad_ay_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_login_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affi_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_quit_ay_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affi_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_actu_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modi_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajou_ay_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_actu_mah_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_affi_mah_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_mah2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_mah2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_mah2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajou_ad_mah_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajou_mah2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_ay_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_quit_ad_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supp_tree_ad_ay_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_supp_tree_ay_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_ch2_tree_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modi2_tree_mah_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modi_tree_mah_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recl_ay_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ok_ay_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_rec_ouvrier_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_ajou_tr_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_supp_rec_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button9_retour_ouvrier_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button10_retour_equipement_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_retour_troupeaux_clicked   (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button8_ret_ad_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button7_ok_mah_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton10_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton11_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton12_mah_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton9_mah_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button8_rec_mah_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button8_re_login_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_affi_lait1_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_affi_lait2_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_quiter_ouv_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button8_reclamation_ouv_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);
