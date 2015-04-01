#include <gtk/gtk.h>
#include "board.h"

#define WINDOW_WIDTH 	670
#define WINDOW_HEIGHT 	640
#define BORDER_WIDTH 	10
#define TITLE 	"BattleShip"
#define WINDOW_POSITION 	GTK_WIN_POS_CENTER
#define BOARD_WIDTH		280
#define BOARD_HEIGHT	280
#define GRID_SPACE	10

GtkWidget *window;
GtkWidget *player_board;
GtkWidget *enemy_board;
GtkWidget *f_boards;
GtkWidget *f_buttons;
GtkWidget *f_messages;
GtkWidget *hbox;
GtkWidget *hboxfield;
GtkWidget *vbox;
GtkWidget *grid;
GtkWidget *btn_destroyer;
GtkWidget *img_destroyer;
GtkWidget *btn_submarine;
GtkWidget *img_submarine;
GtkWidget *btn_battleship;
GtkWidget *img_battleship;
GtkWidget *btn_cruiser;
GtkWidget *img_cruiser;
GtkWidget *btn_carrier;
GtkWidget *img_carrier;
GtkWidget *btn_clear;
GtkWidget *player_field;
GtkWidget *lbl_console;
GtkWidget *lbl_target;
GdkRGBA black = {0, 0, 0, 0};
GdkRGBA white = {1, 1, 1, 1};

void createWindow(){
  void setSize(int, int);
  void setBorderWidth(int);
  void setTitle(char *);
  void setPosition(GtkWindowPosition);
  void placeBoards(void);
  void placeButtons(void);
  void placeTextfield(void);
  void placeConsole(void);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_override_background_color(window, 0, &black);
  setPosition(WINDOW_POSITION);
  setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  setTitle(TITLE);
  setBorderWidth(BORDER_WIDTH);
  placeTextfield();
  placeBoards();
  placeConsole();
  placeButtons();
  placeConsole();
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);
 }

 void setSize(int width, int height){
  gtk_window_set_default_size (GTK_WINDOW (window), width, height);
 }

 void setBorderWidth(int width){
 	gtk_container_set_border_width (GTK_CONTAINER (window), width);
 }

 void setTitle(char *title){
 	gtk_window_set_title(GTK_WINDOW(window), title);
 }

 void setPosition(GtkWindowPosition position){
 	gtk_window_set_position(GTK_WINDOW(window), position);
 }

 void placeTextfield(){
    player_field=gtk_entry_new();
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    lbl_target=gtk_label_new("CHOOSE A TARGET: ");
    gtk_widget_override_color(lbl_target, 0, &white);
    hboxfield=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign (hboxfield, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(hboxfield), lbl_target);
    gtk_container_add(GTK_CONTAINER(hboxfield), player_field);
    gtk_container_add(GTK_CONTAINER(vbox), hboxfield);
 }

 void placeBoards(){
 	player_board = gtk_drawing_area_new();
 	enemy_board = gtk_drawing_area_new();
 	gtk_widget_set_size_request (player_board, BOARD_WIDTH, BOARD_HEIGHT);
	gtk_widget_set_size_request (enemy_board, BOARD_WIDTH, BOARD_HEIGHT);
	f_boards = gtk_frame_new("");
  gtk_widget_set_size_request (f_boards, 620, 300);
  gtk_container_add(GTK_CONTAINER(vbox), f_boards);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 70);
  gtk_container_add(GTK_CONTAINER(f_boards), hbox);
  gtk_container_add(GTK_CONTAINER(hbox), player_board);
  gtk_container_add(GTK_CONTAINER(hbox), enemy_board);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  g_signal_connect(G_OBJECT(player_board), "draw", G_CALLBACK(on_draw_event), NULL); 
  g_signal_connect(G_OBJECT(enemy_board), "draw", G_CALLBACK(on_draw_event), NULL); 
 }

 void placeButtons(){
 	f_buttons = gtk_frame_new("");
  gtk_widget_set_size_request (f_buttons, 620, 110);
 	grid=gtk_grid_new();
	btn_destroyer=gtk_button_new_with_label("DESTROYER");
	btn_submarine=gtk_button_new_with_label("SUBMARINE");
	btn_battleship=gtk_button_new_with_label("BATTLESHIP");
	btn_cruiser=gtk_button_new_with_label("CRUISER");
	btn_carrier=gtk_button_new_with_label("CARRIER");
  btn_clear=gtk_button_new_with_label("CLEAR");
	gtk_grid_set_column_spacing((GtkGrid *) grid, GRID_SPACE);
  gtk_grid_set_row_spacing((GtkGrid *) grid, GRID_SPACE);
	gtk_grid_attach((GtkGrid *) grid, btn_destroyer, 0, 0, 1, 1);
  gtk_widget_set_hexpand (btn_destroyer, TRUE);
	gtk_grid_attach((GtkGrid *) grid, btn_submarine, 1, 0, 1, 1);
  gtk_widget_set_hexpand (btn_submarine, TRUE); 
	gtk_grid_attach((GtkGrid *) grid, btn_battleship, 2, 0, 1, 1);
  gtk_widget_set_hexpand (btn_battleship, TRUE);
	gtk_grid_attach((GtkGrid *) grid, btn_cruiser, 0, 1, 1, 1);
  gtk_widget_set_hexpand (btn_cruiser, TRUE);
	gtk_grid_attach((GtkGrid *) grid, btn_carrier, 1, 1, 1, 1);
  gtk_widget_set_hexpand (btn_carrier, TRUE);
  gtk_grid_attach((GtkGrid *) grid, btn_clear, 2, 1, 1, 1);
  gtk_widget_set_hexpand (btn_clear, TRUE);
	gtk_container_add(GTK_CONTAINER(vbox), f_buttons);
  gtk_widget_set_valign (grid, GTK_ALIGN_START);
	gtk_container_add(GTK_CONTAINER(f_buttons), grid);
 }

 void placeConsole(){
    f_messages=gtk_frame_new("");
    lbl_console=gtk_label_new("");
    gtk_widget_override_color(window, 0, &white);
    gtk_widget_set_size_request (f_messages, 620, 50);
    gtk_widget_set_halign (lbl_console, GTK_ALIGN_START);
    gtk_widget_set_valign (lbl_console, GTK_ALIGN_START);
    gtk_container_add(GTK_CONTAINER(vbox), f_messages);
    gtk_container_add(GTK_CONTAINER(f_messages), lbl_console);
 }
