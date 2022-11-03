#include "ft_printf.h"

char	*lowercase_conv(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

void	ft_putstr(char *s, int *pbyte)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", pbyte);
	}
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		*pbyte += 1;
	}
}

void	base_conversion(unsigned long long t, int *pbyte)
{
	ft_putstr("0x", pbyte);
	if (t == 0)
	{
		write(1, "0", 1);
		*pbyte += 1;
		return ;
	}
	base_conversion2(t, pbyte);
}

void	int_conversion(unsigned int t, int *bbyte)
{
	if (t == 0)
	{
		write(1, "0", 1);
		*bbyte += 1;
		return ;
	}
	int_conversion2(t, bbyte);
}
