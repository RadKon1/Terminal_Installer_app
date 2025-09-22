#include "glib-object.h"
#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
  g_print("Hello World\n");
}

static void print_line(GtkWidget *widget, gpointer data) {
  g_print("My first GTK project is currently running\n");
}

static void update_system_cmd(GtkWidget *widget, gpointer data) {
  g_print("updating your system\n");
  system("sudo pacman -Syu --noconfirm");
}

static void install_vim_cmd(GtkWidget *widget, gpointer data) {
  g_print("Installing vim\n");
  system("sudo pacman -S --noconfirm vim");
}

static void uninstall_vim_cmd(GtkWidget *widget, gpointer data) {
  g_print("Uninstalling vim\n");
  system("sudo pacman -R --noconfirm vim");
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *button;
  GtkWidget *sec_button;
  GtkWidget *update_button;
  GtkWidget *install_vim_button;
  GtkWidget *uninstall_vim_button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "TERMINAL INSTALLER APP");
  gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
  gtk_window_set_child(GTK_WINDOW(window), box);

  update_button = gtk_button_new_with_label("SYSTEM UPDATE");
  g_signal_connect(update_button, "clicked", G_CALLBACK(update_system_cmd),
                   NULL);
  gtk_box_append(GTK_BOX(box), update_button);

  install_vim_button = gtk_button_new_with_label("INSTALL VIM");
  g_signal_connect(install_vim_button, "clicked", G_CALLBACK(install_vim_cmd),
                   NULL);
  gtk_box_append(GTK_BOX(box), install_vim_button);

  uninstall_vim_button = gtk_button_new_with_label("UNINSTALL VIM");
  g_signal_connect(uninstall_vim_button, "clicked",
                   G_CALLBACK(uninstall_vim_cmd), NULL);
  gtk_box_append(GTK_BOX(box), uninstall_vim_button);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
