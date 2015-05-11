#include <gtk/gtk.h>
#include "window.h"
#include "board.h"
#include "events.h"
#include "termInit.h"

int main(int argc, char **argv)
{
    initTerm();
    gtk_init(&argc, &argv);
    createWindow();
    gtk_main();

return 0;
}
