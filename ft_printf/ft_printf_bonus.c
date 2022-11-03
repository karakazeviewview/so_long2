#include "ft_printf.h"

char	*checkspecifer6(char *str, va_list arg, int *bbyte)
{
	size_t			i;
	unsigned int	ui;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			i++;
			ui = va_arg(arg, unsigned int);
			if (str[i] == 'x')
			{
				if (ui != 0)
					ft_putstr("0x", bbyte);
				int_conversion(ui, bbyte);
				str = &str[2];
			}
			else if (str[i] == 'X')
				str = checkspecifer61(&str[i], bbyte, ui);
		}
		else
			str = checkspecifer7(&str[i], arg, bbyte);
		break ;
	}
	return (str);
}

char	*checkspecifer7(char *str, va_list arg, int *bbyte)
{
	size_t	i;
	int		x;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
		{
			x = va_arg(arg, int);
			if (x >= 0)
			{
				ft_putstr("+", bbyte);
				str = checkspecifer72(str, bbyte, x);
			}
			else if (x < 0)
				str = checkspecifer71(str, x, bbyte);
		}
		else
			str = checkspecifer8(str, arg, bbyte);
		break ;
	}
	return (str);
}

char	*checkspecifer71(char *str, int x, int *bbyte)
{
	char	*pstr;

	pstr = ft_itoa(x);
	ft_putstr(pstr, bbyte);
	free (pstr);
	str = &str[2];
	return (str);
}

char	*checkspecifer8(char *str, va_list arg, int *bbyte)
{
	size_t	i;
	int		x;
	char	*sstr;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			x = va_arg(arg, int);
			if (x < 0)
			{
				sstr = ft_itoa(x);
				ft_putstr(sstr, bbyte);
				free (sstr);
				str = &str[2];
			}
			else if (x >= 0)
				str = checkspecifer81(str, bbyte, x);
		}
		break ;
	}
	return (str);
}

char	*checkspecifer61(char *str, int *bbyte, unsigned int ui)
{
	size_t	i;

	i = 0;
	if (str[i] == 'X')
	{
		if (ui != 0)
			ft_putstr("0X", bbyte);
		intx_conversion(ui, bbyte);
	}
	str = &str[+1];
	return (str);
}
