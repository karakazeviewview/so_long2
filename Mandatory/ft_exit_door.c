#include "so_long.h"

void	exit_door(t_vars ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	mlx_destroy_window((**v)->mlx, (**v)->win);
	exit(1);
}
