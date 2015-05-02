#include <cairo.h>
#include <gtk/gtk.h>
#include "events.h"
#include "board.h"
#include "window.h"

void on_draw_event(GtkWidget *widget, cairo_t *dr, gpointer user_data){
    
    void renderBoard(cairo_t *);

	renderBoard(dr);

} 

gboolean btn_destroyer_clicked(GtkWidget *widget, gpointer button){

	g_print("destroyer clicked\n");	
    
  pix=gdk_pixbuf_new_from_file("/res/images/Destroyer_Top_Horizontal.png", &pixbuf_error);
  
    if(pix==NULL){
       
       g_print("%s\n", pixbuf_error->message);
       g_error_free(pixbuf_error);

    }
    else{
       
       surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
    
    }
    
	/* load image of destroyer and make it appear next to the pointer of the mouse */
    
    selButton=0;

return TRUE;
}

void btn_submarine_clicked(GtkWidget *widget, gpointer data){

	pix=gdk_pixbuf_new_from_file("/res/images/Submarine_top_horizontal.png", &pixbuf_error);

    if(pix==NULL){
       
       g_print("%s\n", pixbuf_error->message);
       g_error_free(pixbuf_error);
    
    }
    else{
       
       surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
    
    }

	g_print("submarine clicked\n");
	/* load image of submarine and make it appear next to the pointer of the mouse */

  selButton=1;

}

void btn_battleship_clicked(GtkWidget *widget, gpointer data){

	pix=gdk_pixbuf_new_from_file("/res/images/Battleship_top_horizontal.png", &pixbuf_error);

    if(pix==NULL){
       
       g_print("%s\n", pixbuf_error->message);
       g_error_free(pixbuf_error);
       
    }
    else{
       
       surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
    
    }

	g_print("battleship clicked\n");

  selButton=2;
	/* load image of battleship and make it appear next to the pointer of the mouse */

}

void btn_cruiser_clicked(GtkWidget *widget, gpointer data){

	pix=gdk_pixbuf_new_from_file("/res/images/cruiser_top_horizontal.png", &pixbuf_error); 

    if(pix==NULL){
       
       g_print("%s\n", pixbuf_error->message);
       g_error_free(pixbuf_error);
    
    }
    else{
       
       surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
    
    }

	g_print("cruiser clicked\n");

  selButton=3;
	/* load image of cruiser and make it appear next to the pointer of the mouse */

}

void btn_carrier_clicked(GtkWidget *widget, gpointer data){

	pix=gdk_pixbuf_new_from_file("/res/images/carrier_top_horizontal.png", &pixbuf_error);

    if(pix==NULL){
        
       g_print("%s\n", pixbuf_error->message);
       g_error_free(pixbuf_error);
    
    }
    else{
       
       surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
    
    }

	g_print("carrier clicked\n");

  selButton=4;

	/* load image of carrier and make it appear next to the pointer of the mouse */

}

void btn_clear_clicked(GtkWidget *widget, gpointer data){

	g_print("clear clicked\n");

}

void btn_mouse_pressed(GtkWidget *widget, GdkEventButton * event){

    /* if key pressed is equal to left mouse button key then:
    get the coordinates of the pointer of the mouse and place the img previously selected
    at the cell located at those coordinates on the player board when placing ships*/ 

}

void btn_mouse_released(GtkWidget *widget, GdkEventButton * event){

    if(event->button == 2){
      
      switch(selButton){
        
        case 0: 

          pix=gdk_pixbuf_new_from_file("/res/images/Destroyer_Top_vertical.png", &pixbuf_error);
          break;

        case 1:

          pix=gdk_pixbuf_new_from_file("/res/images/Submarine_top_vertical.png", &pixbuf_error);
          break;

        case 2:

          pix=gdk_pixbuf_new_from_file("/res/images/Battleship_top_vertical.png", &pixbuf_error);
          break;

        case 3:

          pix=gdk_pixbuf_new_from_file("/res/images/cruiser_top_vertical.png", &pixbuf_error);
          break;

        case 4: 

          pix=gdk_pixbuf_new_from_file("/res/images/carrier_top_vertical.png", &pixbuf_error);
          break;

        default:
          
          g_print("Invalid Button selected.");

      }
      
    }

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

void redraw(cairo_t *er, gdouble x, gdouble y){
        
        er=cairo_create(surface);
        //gdk_cairo_set_source_pixbuf(cr, pix, event->x, event->y);
        cairo_rectangle(er, x, y, cairo_image_surface_get_width(surface), cairo_image_surface_get_height(surface));
        //surface=gdk_window_create_similar_surface (gtk_widget_get_window (widget), CAIRO_CONTENT_COLOR, gdk_pixbuf_get_width(pix), gdk_pixbuf_get_height(pix));
        cairo_paint(er);
        cairo_fill(er);
        cairo_destroy(er);

}

void mouse_moved(GtkWidget *widget, GdkEventMotion *event){
   
    void redraw(cairo_t *, gdouble, gdouble);
    g_print("motion\n");

        redraw(cr, event->x, event->y);
    
        gtk_widget_queue_draw_area (widget, event->x, event->y, cairo_image_surface_get_width(surface), cairo_image_surface_get_height(surface));

	/* move the selected image as the pointer of the mouse moves */

}


