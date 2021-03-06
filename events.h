int selButton;
GdkPixbuf *pix;
GtkWidget *img;
GtkAllocation allocation;
cairo_surface_t *surface;
cairo_t *cr;
GError *pixbuf_error;

void on_draw_event(GtkWidget *, cairo_t *, gpointer);
void redraw(cairo_t *, gdouble, gdouble);
void btn_destroyer_clicked(GtkWidget *, gpointer);
void btn_submarine_clicked(GtkWidget *, gpointer);
void btn_battleship_clicked(GtkWidget *, gpointer);
void btn_cruiser_clicked(GtkWidget *, gpointer);
void btn_carrier_clicked(GtkWidget *, gpointer);
void btn_clear_clicked(GtkWidget *, gpointer);
void btn_mouse_pressed(GtkWidget *, GdkEventButton *);
void btn_mouse_released(GtkWidget *, GdkEventButton *);
void txtfield_action(GtkWidget *, GdkEventKey *);
void mouse_moved(GtkWidget *, GdkEventMotion *);
