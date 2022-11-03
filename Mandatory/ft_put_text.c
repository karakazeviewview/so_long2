#include "so_long.h"

void	put_text(t_vars ***v)
{
	char	*number;

	number = ft_itoa1(++(**v)->movement);
	ft_printf("%s\n", number);
	free(number);
}
