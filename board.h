#define N_ROWS	10
#define N_COLS	10
#define POS_X	25
#define POS_Y	20
#define SEA_WIDTH	25
#define SEA_HEIGHT	25
#define BOARD_WIDTH 	SEA_WIDTH*N_ROWS
#define BOARD_HEIGHT	SEA_HEIGHT*N_ROWS
#define CENTER_WIDTH 	50
#define CENTER_HEIGHT 	50

enum letters{A, B, C, D, E, F, G, H, I, J, K, L, M};

void renderBoard(cairo_t *);
void renderUnit(cairo_t *, int, int, int, int);
