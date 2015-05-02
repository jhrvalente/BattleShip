#define WINDOW_WIDTH 	670
#define WINDOW_HEIGHT 	640
#define BORDER_WIDTH 	10
#define TITLE 	"BattleShip"
#define WINDOW_POSITION 	GTK_WIN_POS_CENTER
#define B_DRAWING_WIDTH		280
#define B_DRAWING_HEIGHT	280
#define GRID_SPACE	10

GtkWidget *window;
GtkWidget *player_board, *enemy_board;
GtkWidget *f_boards, *f_buttons, *f_messages;
GtkWidget *hbox, *hboxfield, *vbox;
GtkWidget *grid;
GtkWidget *btn_destroyer;
GtkWidget *img_destroyer, *img_submarine, *img_battleship, *img_cruiser, *img_carrier, *img_clear;
GtkWidget *btn_submarine, *btn_battleship, *btn_cruiser, *btn_carrier, *btn_clear;
GtkWidget *player_field;
GtkWidget *lbl_console, *lbl_target;

void createWindow(void);
void setSize(int, int);
void setBorderWidth(int);
void setTitle(char *);
void setPosition(GtkWindowPosition);
void placeBoards(void);
void placeButtons(void);
void placeTextfield(void);
void placeConsole(void);
