#include "ft_printf.h"

char	*checkspecifer72(char *str, int *bbyte, int x)
{
	char	*pstr;

	pstr = ft_itoa(x);
	ft_putstr(pstr, bbyte);
	free (pstr);
	str = &str[2];
	return (str);
}

char	*checkspecifer81(char *str, int *bbyte, int x)
{
	char	*sstr;

	ft_putstr(" ", bbyte);
	sstr = ft_itoa(x);
	ft_putstr(sstr, bbyte);
	free(sstr);
	str = &str[2];
	return (str);
}
