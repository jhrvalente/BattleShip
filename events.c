#include <cairo.h>
#include <gtk/gtk.h>
#include "board.h"
#include "window.h"

GtkWidget *img;

void on_draw_event(GtkWidget *widget, cairo_t * cr, gpointer user_data){
void renderBoard(cairo_t *);
  renderBoard(cr);
}

void btn_destroyer_clicked(GtkWidget *widget, gpointer data){
img=gtk_image_set_from_file("/res/images/destroyer.png");
g_print("destroyer clicked\n");	
/* load image of destroyer and make it appear next to the pointer of the mouse */
}

void btn_submarine_clicked(GtkWidget *widget, gpointer data){
	img=gtk_image_new_from_file("/res/images/submarine.png");
	g_print("submarine clicked\n");
	/* load image of submarine and make it appear next to the pointer of the mouse */
}

void btn_battleship_clicked(GtkWidget *widget, gpointer data){
	img=gtk_image_new_from_file("/res/images/battleship.png");
	g_print("battleship clicked\n");
	/* load image of battleship and make it appear next to the pointer of the mouse */
}

void btn_cruiser_clicked(GtkWidget *widget, gpointer data){
	img=gtk_image_new_from_file("/res/images/cruiser.png");
	g_print("cruiser clicked\n");
	/* load image of cruiser and make it appear next to the pointer of the mouse */
}

void btn_carrier_clicked(GtkWidget *widget, gpointer data){
	img=gtk_image_new_from_file("/res/images/carrier.png");
	g_print("carrier clicked\n");
	/* load image of carrier and make it appear next to the pointer of the mouse */
}

void btn_clear_clicked(GtkWidget *widget, gpointer data){
	g_print("clear clicked\n");
}

void btn_mouse_pressed(GtkWidget *widget, GdkEventKey *event){
    /* if key pressed is equal to left mouse button key then:
    get the coordinates of the pointer of the mouse and place the img previously selected
    at the cell located at those coordinates on the player board when placing ships*/ 
}

void btn_mouse_released(GtkWidget *widget, GdkEventKey *event){
    /* if key released is equal to right mouse button key then:
    rotate (switch from img horizontal to vertical and vice-versa)*/
}

void txtfield_action(GtkWidget *widget, GdkEventKey *event){
	/* if user presses enter on the textfield then:
	- get value from textfield
	- parse string char by char
	- if letter equals one of the letters in the the enum letters then go to that row on enemy board
	- if number equals one of the numbers in the enum numbers then go to that column
	- get the cell located at those coordinates and place img target on that cell on enemy board */
}

void mouse_moved(GtkWidget *widget, GdkEventMotion *event){
	g_print("motion\n");
	/* move the selected image as the pointer of the mouse moves */
}


