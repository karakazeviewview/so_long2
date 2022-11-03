#include "ft_printf.h"

char	*checkspecifer2(char *str, va_list arg, int *bbyte)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'x')
		{
			int_conversion(va_arg(arg, unsigned int), bbyte);
			str = &str[+1];
			break ;
		}
		if (str[i] == 'X')
		{
			intx_conversion(va_arg(arg, unsigned int), bbyte);
			str = &str[+1];
			break ;
		}
		else
		{
			str = checkspecifer3(&str[i], arg, bbyte);
			break ;
		}
	}
	return (str);
}

char	*checkspecifer3(char *str, va_list arg, int *bbyte)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			write(1, &str[i], 1);
			*bbyte += 1;
			str = &str[+1];
			break ;
		}
		if (str[i] == 'p')
		{
			base_conversion(va_arg(arg, unsigned long long), bbyte);
			str = &str[+1];
			break ;
		}
		else
		{
			str = checkspecifer4(&str[i], arg, bbyte);
			break ;
		}
	}
	return (str);
}

char	*checkspecifer4(char *str, va_list arg, int *bbyte)
{
	char			*pstr;
	size_t			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 's')
		{
			pstr = va_arg(arg, char *);
			ft_putstr(pstr, bbyte);
			str = &str[+1];
			break ;
		}
		else
		{
			str = checkspecifer5(&str[i], arg, bbyte);
			break ;
		}
	}
	return (str);
}

void	int_conversion2(unsigned int t, int	*pbyte)
{
	unsigned int	i;
	unsigned int	j;
	char			answer[20];
	char			*str;
	char			*henkan;

	henkan = "0123456789ABCDEF";
	i = 0;
	j = 0;
	while (t > 0)
	{
		j = t % 16;
		t = t / 16;
		answer[i++] = henkan[j];
	}
	answer[i] = '\0';
	i--;
	j = i;
	str = lowercase_conv(answer);
	while (j >= 0 && j != UINT_MAX)
	{
		write(1, &str[j], 1);
		j--;
		*pbyte += 1;
	}
}

void	base_conversion2(unsigned long long t, int *pbyte)
{
	unsigned long long	i;
	unsigned long long	j;
	char				answer[20];
	char				*str;
	char				*henkan;

	henkan = "0123456789ABCDEF";
	i = 0;
	j = 0;
	while (t > 0)
	{
		j = t % 16;
		t = t / 16;
		answer[i++] = henkan[j];
	}
	answer[i] = '\0';
	i--;
	j = i;
	str = lowercase_conv(answer);
	while (j >= 0 && j != ULLONG_MAX)
	{
		write(1, &str[j], 1);
		j--;
		*pbyte += 1;
	}
}
