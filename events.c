#include <cairo.h>
#include <gtk/gtk.h>
#include "events.h"
#include "board.h"
#include "window.h"


void on_draw_event(GtkWidget *widget, cairo_t *dr, gpointer user_data)
{
void renderBoard(cairo_t *); // Prototype of the function renderBoard

    renderBoard(dr);
} 


/* On button Destroyer clicked:

  1. Load image of destroyer and make it appear next to the pointer of the mouse
  2. Decrement counter*/


void btn_destroyer_clicked(GtkWidget *widget, gpointer button)
{
    g_print("destroyer clicked\n");	

    selButton=0;
    pix=gdk_pixbuf_new_from_file("/res/images/Destroyer_Top_Horizontal.png", &pixbuf_error);

    if(!pix)
    {
        g_print("%s\n", pixbuf_error->message);
        g_error_free(pixbuf_error);
    }
    else surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));
}


/* On button Submarine clicked:

  1. Load image of submarine and make it appear next to the pointer of the mouse
  2. Decrement counter*/


void btn_submarine_clicked(GtkWidget *widget, gpointer data)
{
    g_print("submarine clicked\n");
    
    selButton=1;
    pix=gdk_pixbuf_new_from_file("/res/images/Submarine_top_horizontal.png", &pixbuf_error);

    if(!pix)
    {
        g_print("%s\n", pixbuf_error->message);
        g_error_free(pixbuf_error);
    }
    else surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));

}


/* On button Battleship clicked:

  1. Load image of battleship and make it appear next to the pointer of the mouse
  2. Decrement counter*/


void btn_battleship_clicked(GtkWidget *widget, gpointer data)
{
    g_print("battleship clicked\n");

    selButton=2;
    pix=gdk_pixbuf_new_from_file("/res/images/Battleship_top_horizontal.png", &pixbuf_error);

    if(!pix)
    {  
        g_print("%s\n", pixbuf_error->message);
        g_error_free(pixbuf_error); 
    }
    else surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));

}


/* On button Cruiser clicked:

  1. Load image of cruiser and make it appear next to the pointer of the mouse
  2. Decrement counter*/


void btn_cruiser_clicked(GtkWidget *widget, gpointer data)
{
    g_print("cruiser clicked\n");

    selButton=3;
    pix=gdk_pixbuf_new_from_file("/res/images/cruiser_top_horizontal.png", &pixbuf_error); 

    if(!pix)
    {
        g_print("%s\n", pixbuf_error->message);
        g_error_free(pixbuf_error);
    }
    else surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));

}


/* On button Carrier clicked: 

   1. Load image of carrier and make it appear next to the pointer of the mouse 
   2. Decrement counter*/


void btn_carrier_clicked(GtkWidget *widget, gpointer data)
{
    g_print("carrier clicked\n");

    selButton=4;
    pix=gdk_pixbuf_new_from_file("/res/images/carrier_top_horizontal.png", &pixbuf_error);

    if(!pix)
    { 
        g_print("%s\n", pixbuf_error->message);
        g_error_free(pixbuf_error);
    }
    else surface=gdk_cairo_surface_create_from_pixbuf(pix, 0, gtk_widget_get_window(player_board));

}

void btn_clear_clicked(GtkWidget *widget, gpointer data)
{
    g_print("clear clicked\n");
}


/* if key pressed is equal to left mouse button key then:

1. Get the coordinates of the pointer of the mouse 
2. Place the img previously selected at the cell located at those coordinates on the player board when placing ships */ 


void btn_mouse_pressed(GtkWidget *widget, GdkEventButton * event)
{

}


/* if key released is equal to right mouse button key then:

1. rotate (switch from img horizontal to vertical and vice-versa) */


void btn_mouse_released(GtkWidget *widget, GdkEventButton * event)
{
    if(event->button == 2)
    {
        switch(selButton)
        {
            case 0: pix=gdk_pixbuf_new_from_file("/res/images/Destroyer_Top_vertical.png", &pixbuf_error);
                    break;
            case 1: pix=gdk_pixbuf_new_from_file("/res/images/Submarine_top_vertical.png", &pixbuf_error);
                    break;
            case 2: pix=gdk_pixbuf_new_from_file("/res/images/Battleship_top_vertical.png", &pixbuf_error);
                    break;
            case 3: pix=gdk_pixbuf_new_from_file("/res/images/cruiser_top_vertical.png", &pixbuf_error);
                    break;
            case 4: pix=gdk_pixbuf_new_from_file("/res/images/carrier_top_vertical.png", &pixbuf_error);
                    break;
            default: g_print("Invalid Button selected.");
        }

    }

}

/* If user presses the key 'Enter' on the textfield then:

  1. Get value from Textfield
  2. Parse string char by char
  3. If letter equals one of the letters in the the enum Letters then go to that row on enemy board
  4. If number equals one of the numbers in the enum Numbers then go to that column
  5. Get the cell located at those coordinates and place img target on that cell on enemy board */

void txtfield_action(GtkWidget *widget, GdkEventKey *event)
{

}

 
/* On redraw:
1. Redraw a region of the Drawing area, which is basically the area defined by Img. */ 

void redraw(cairo_t *er, gdouble x, gdouble y)
{     
    er=cairo_create(surface);

    cairo_rectangle(er, x, y, cairo_image_surface_get_width(surface), cairo_image_surface_get_height(surface));
    cairo_paint(er);
    cairo_fill(er);
    cairo_destroy(er);
}

/* On mouse moved within the PlayerBoard bounds: 
1. Drag the selected image as mouse pointer moves within the Drawing Area 
2. Queue a Redraw with the redraw method previously defined as the mouse pointer moves
3. In this method, the image should be redrawn on a layer on top of Drawing Area, not on Drawing Area itself.
4. After redrawing at the mouse pointer coordinates, as the mouse moves over the Drawing Area, the previous image should be removed */


void mouse_moved(GtkWidget *widget, GdkEventMotion *event)
{
void redraw(cairo_t *, gdouble, gdouble); // Prototype of the function redraw

    g_print("motion\n");
    //redraw(cr, event->x, event->y);
    //gtk_widget_queue_draw_area (widget, event->x, event->y, cairo_image_surface_get_width(surface), cairo_image_surface_get_height(surface));

}


