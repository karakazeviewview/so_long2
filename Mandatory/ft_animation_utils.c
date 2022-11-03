#include "so_long.h"

void	open_exit(t_vars **vars)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*vars)->map);
	while (y != height)
	{
		x = 0;
		while ((*vars)->map[y][x] != '\0')
		{
			if ((*vars)->map[y][x] == 'E')
			{
				(*vars)->img = mlx_xpm_file_to_image(
						(*vars)->mlx, "./img2/o_exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*vars)->mlx, (*vars)->win, (*vars)->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
