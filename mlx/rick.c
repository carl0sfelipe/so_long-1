#include <stdlib.h>
#include "mlx.h"

/* XPM image of the Rick spaceship */
static char *spaceship[] = {
/* width height num_colors chars_per_pixel */
"10 10 3 1",
/* colors */
"  c white",
". c black",
"X c red",
/* pixels */
"X  .X  .X",
" X .XX . X",
"  .XXX.  ",
" X .XX . X",
"X  .X  .X",
" X .XX . X",
"  .XXX.  ",
" X .XX . X",
"X  .X  .X",
"          "
};

int main(void)
{
    void *mlx;
    void *win;
    int img_w;
    int img_h;
    int *img_data;
    void *img;

    /* Initialize Minilibx and create a window */
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "Window");

    /* Create an image using the XPM image data */
img = mlx_xpm_to_image(mlx, spaceship, &img_w, &img_h);

    /* Display the image on the window */
    mlx_put_image_to_window(mlx, win, img, 0, 0);

/* Set up a loop to keep the window open and wait for user input */
mlx_loop(mlx);

/* Clean up and exit the program when the user closes the window */
mlx_destroy_image(mlx, img);
mlx_destroy_window(mlx, win);
exit(0);

return 0;
}
