#include <gtk/gtk.h>
#include "window.h"
#include "board.h"

int main(int argc, char **argv){
  gtk_init(&argc, &argv);
  createWindow();
  gtk_main();
  return 0;
}
