#include "so_long.h"

static char	*ft_err_message(t_map_vars *map)
{
	if (map->c == 0)
		return (
			"エラー: 要素Cがありません");
	if (map->e == 0)
		return (
			"エラー: 要素Eがありません");
	if (map->e > 1)
		return (
			"エラー: 要素Eが1つ以上ある");
	if (map->p == 0)
		return (
			"エラー: 要素Pがありません");
	if (map->p > 1)
		return (
			"エラー: 要素Pが1つ以上ある");
	return ("エラー: 要素がありません");
}

char	*unknown_element(t_vars ***v, char c)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	ft_printf("エラー: 不明な要素 %c", c);
	exit(1);
}

void	check_elements(t_vars **vars)
{
	t_map_vars	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*vars)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*vars)->map[map.y][map.x] != '\0')
		{
			if ((*vars)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*vars)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*vars)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*vars)->map[map.y][map.x] != '1' &&
				(*vars)->map[map.y][map.x] != '0')
				unknown_element(&vars, (*vars)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1 || map.e > 1)
		ft_error(&vars, ft_err_message(&map));
}
