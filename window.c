#include <gtk/gtk.h>
#include "events.h"
#include "window.h"

#define V_SPACING    5
#define H_SPACING    2*V_SPACING
#define CENTER_IMG_WIDTH    140  
#define FRAME_WIDTH    620    
#define F_BOARD_HEIGHT    300
#define F_MESSAGES_HEIGHT    50
#define F_BUTTONS_HEIGHT    110  

GdkRGBA black = {0, 0, 0, 0}, white = {1, 1, 1, 1};
GtkSettings *default_settings;

void createWindow()
{
//Prototypes of the functions needed within this method
void init(void);
void overrideColors(void);
void setAll(void);
void attachToGrid();
void addToWindow(void);
void connectSignals(void);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    default_settings = gtk_settings_get_default();

    init();
    gtk_widget_add_events(player_board, GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK |GDK_POINTER_MOTION_HINT_MASK);
    overrideColors();
    setAll();
    attachToGrid();
    addToWindow();
    connectSignals();

    gtk_widget_show_all(window); 
}

void init()
{
    player_field=gtk_entry_new();
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, V_SPACING);
    lbl_target = gtk_label_new("CHOOSE A TARGET: ");
    hboxfield = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, H_SPACING);
    player_board = gtk_drawing_area_new();
    enemy_board = gtk_drawing_area_new();
    f_boards = gtk_frame_new("");
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, CENTER_IMG_WIDTH);
    f_messages = gtk_frame_new("");
    lbl_console = gtk_label_new("");
    f_buttons = gtk_frame_new("");
    grid = gtk_grid_new();
    img_battleship = gtk_image_new_from_file("res/images/battleship.png");
    img_submarine = gtk_image_new_from_file("res/images/submarine.png");
    img_carrier = gtk_image_new_from_file("res/images/carrier.png");
    img_destroyer = gtk_image_new_from_file("res/images/destroyer.png");
    img_cruiser = gtk_image_new_from_file("res/images/cruiser.png");
    img_clear = gtk_image_new_from_file("res/images/clear.png");
    btn_destroyer = gtk_button_new_with_label("  DESTROYER");
    btn_submarine = gtk_button_new_with_label("  SUBMARINE");
    btn_battleship = gtk_button_new_with_label("  BATTLESHIP");
    btn_cruiser = gtk_button_new_with_label("  CRUISER");
    btn_carrier = gtk_button_new_with_label("  CARRIER");
    btn_clear = gtk_button_new_with_label("  CLEAR");
}

void overrideColors()
{
    gtk_widget_override_background_color(window, 0, &black);
    gtk_widget_override_color(lbl_target, 0, &white);
    gtk_widget_override_color(f_boards, 0, &white);
    gtk_widget_override_color(f_messages, 0, &white);
}

void setAll()
{
    g_object_set(default_settings, "gtk-button-images", TRUE, NULL);
    gtk_window_set_title(GTK_WINDOW(window), TITLE);
    gtk_container_set_border_width (GTK_CONTAINER (window), BORDER_WIDTH);
    gtk_window_set_position(GTK_WINDOW(window), WINDOW_POSITION);
    gtk_window_set_default_size (GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_widget_set_halign (hboxfield, GTK_ALIGN_CENTER);
    gtk_widget_set_size_request (player_board, B_DRAWING_WIDTH, B_DRAWING_HEIGHT);
    gtk_widget_set_size_request (enemy_board, B_DRAWING_WIDTH, B_DRAWING_HEIGHT);
    gtk_widget_set_size_request (f_boards, FRAME_WIDTH, F_BOARD_HEIGHT);
    gtk_widget_set_size_request (f_messages, FRAME_WIDTH, F_MESSAGES_HEIGHT);
    gtk_widget_set_size_request (f_buttons, FRAME_WIDTH, F_BUTTONS_HEIGHT);
    gtk_widget_set_halign (lbl_console, GTK_ALIGN_START);
    gtk_widget_set_valign (lbl_console, GTK_ALIGN_START);
    gtk_button_set_image((GtkButton *)btn_battleship, img_battleship);
    gtk_button_set_image((GtkButton *)btn_submarine, img_submarine);
    gtk_button_set_image((GtkButton *)btn_carrier, img_carrier);
    gtk_button_set_image((GtkButton *)btn_destroyer, img_destroyer);
    gtk_button_set_image((GtkButton *)btn_cruiser, img_cruiser);
    gtk_button_set_image((GtkButton *)btn_clear, img_clear);
    gtk_widget_set_hexpand (btn_destroyer, TRUE);
    gtk_widget_set_hexpand (btn_submarine, TRUE); 
    gtk_widget_set_hexpand (btn_battleship, TRUE);
    gtk_widget_set_hexpand (btn_cruiser, TRUE);
    gtk_widget_set_hexpand (btn_carrier, TRUE);
    gtk_widget_set_hexpand (btn_clear, TRUE);
    gtk_grid_set_column_spacing((GtkGrid *) grid, GRID_SPACE);
    gtk_grid_set_row_spacing((GtkGrid *) grid, GRID_SPACE);
    gtk_widget_set_valign (grid, GTK_ALIGN_START);

}

void attachToGrid()
{ 	
    gtk_grid_attach((GtkGrid *) grid, btn_destroyer, 0, 0, 1, 1);
    gtk_grid_attach((GtkGrid *) grid, btn_submarine, 1, 0, 1, 1);
    gtk_grid_attach((GtkGrid *) grid, btn_battleship, 2, 0, 1, 1);
    gtk_grid_attach((GtkGrid *) grid, btn_cruiser, 0, 1, 1, 1);
    gtk_grid_attach((GtkGrid *) grid, btn_carrier, 1, 1, 1, 1);
    gtk_grid_attach((GtkGrid *) grid, btn_clear, 2, 1, 1, 1);  
}

void addToWindow()
{
    gtk_container_add(GTK_CONTAINER(hboxfield), lbl_target);
    gtk_container_add(GTK_CONTAINER(hboxfield), player_field);
    gtk_container_add(GTK_CONTAINER(vbox), hboxfield);
    gtk_container_add(GTK_CONTAINER(vbox), f_boards);
    gtk_container_add(GTK_CONTAINER(f_boards), hbox);
    gtk_container_add(GTK_CONTAINER(hbox), player_board);
    gtk_container_add(GTK_CONTAINER(hbox), enemy_board);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_container_add(GTK_CONTAINER(vbox), f_messages);
    gtk_container_add(GTK_CONTAINER(f_messages), lbl_console);
    gtk_container_add(GTK_CONTAINER(vbox), f_buttons);
    gtk_container_add(GTK_CONTAINER(f_buttons), grid);
}

void connectSignals()
{
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(btn_destroyer), "clicked", G_CALLBACK(btn_destroyer_clicked), NULL); 
    g_signal_connect(G_OBJECT(btn_submarine), "clicked", G_CALLBACK(btn_submarine_clicked), NULL); 
    g_signal_connect(G_OBJECT(btn_battleship), "clicked", G_CALLBACK(btn_battleship_clicked), NULL); 
    g_signal_connect(G_OBJECT(btn_cruiser), "clicked", G_CALLBACK(btn_cruiser_clicked), NULL); 
    g_signal_connect(G_OBJECT(btn_carrier), "clicked", G_CALLBACK(btn_carrier_clicked), NULL); 
    g_signal_connect(G_OBJECT(btn_clear), "clicked", G_CALLBACK(btn_clear_clicked), NULL);
    g_signal_connect(G_OBJECT(player_board), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(G_OBJECT(enemy_board), "draw", G_CALLBACK(on_draw_event), NULL); 
    g_signal_connect(G_OBJECT(player_board), "motion-notify-event", G_CALLBACK(mouse_moved), NULL);  
    //g_signal_connect(G_OBJECT(player_board), "draw", G_CALLBACK(redraw), NULL); 

}
