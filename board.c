#include <cairo.h>
#include <gtk/gtk.h>
#include "board.h"	

void renderUnit(cairo_t * cr, int x, int y, int width, int height){

	cairo_rectangle(cr, x, y, width, height);
	cairo_set_source_rgb(cr, 0, 1, 1);
	cairo_fill_preserve (cr);
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_stroke (cr);

}

void renderBoard(cairo_t * cr){

	int i, j, x, y;

    x=POS_X;
    y=POS_Y;

	for (i=0; i<N_ROWS; i++){

		for (j=0; j<N_COLS; j++){

			renderUnit(cr, x, y, SEA_WIDTH, SEA_HEIGHT);
			x+=SEA_WIDTH;

		}

	    x-=BOARD_WIDTH;

	y+=SEA_HEIGHT;

	}

}
