#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	int		byte;
	char	*str;

	str = (char *)format;
	va_start(arg, format);
	byte = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str == NULL)
			break ;
		str = myprint(&str[i], &byte);
		if (str == NULL)
			break ;
		str = checkspecifer(&str[i], arg, &byte);
	}
	va_end(arg);
	return (byte);
}

char	*myprint(char *str, int *bbyte)
{
	size_t	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
	{
		ft_putchar(str[i++]);
		*bbyte += 1;
	}
	if (str[i] == '\0')
	{
		str = NULL;
		return (str);
	}
	return (&str[++i]);
}

char	*checkspecifer(char *str, va_list arg, int *bbyte)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'c')
		{
			charoutput(arg, bbyte);
			str = &str[+1];
			break ;
		}
		if (str[i] == 'd' || str[i] == 'i')
		{
			intoutput(arg, bbyte);
			str = &str[+1];
			break ;
		}
		else
		{
			str = checkspecifer2(&str[i], arg, bbyte);
			break ;
		}
	}
	return (str);
}

void	intx_conversion2(unsigned int t, int *pbyte)
{
	unsigned int	i;
	unsigned int	j;
	char			*henkan;
	char			answer[20];

	i = 0;
	j = 0;
	henkan = "0123456789ABCDEF";
	while (t > 0)
	{
		j = t % 16;
		t = t / 16;
		answer[i] = henkan[j];
		i++;
	}
	answer[i] = '\0';
	i--;
	j = i;
	while (j >= 0 && j != UINT_MAX)
	{
		write(1, &answer[j], 1);
		j--;
		*pbyte += 1;
	}
}
