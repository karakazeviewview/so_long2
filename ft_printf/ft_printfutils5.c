#include "ft_printf.h"

char	*checkspecifer5(char *str, va_list arg, int *bbyte)
{
	char			*pstr;
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'u')
		{
			pstr = ft_untoa(va_arg(arg, unsigned int));
			ft_putstr(pstr, bbyte);
			free(pstr);
			str = &str[+1];
			break ;
		}
		else
		{
			str = checkspecifer6(&str[i], arg, bbyte);
			break ;
		}
	}
	return (str);
}
