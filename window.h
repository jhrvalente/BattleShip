extern GtkWidget *btn_destroyer;
extern GtkWidget *img_destroyer;
extern GtkWidget *btn_submarine;
extern GtkWidget *img_submarine;
extern GtkWidget *btn_battleship;
extern GtkWidget *btn_cruiser;
extern GtkWidget *btn_carrier;
extern GtkWidget *btn_clear;

void createWindow(void);
void setSize(int, int);
void setBorderWidth(int);
void setTitle(char *);
void setPosition(GtkWindowPosition);
void placeBoards(void);
void placeButtons(void);
void placeTextfield(void);
void placeConsole(void);
