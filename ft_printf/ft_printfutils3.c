#include "ft_printf.h"

char	*uppercase_conv(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] += 32;
		i++;
	}
	return (str);
}

void	intx_conversion(unsigned int t, int *pbyte)
{
	if (t == 0)
	{
		write(1, "0", 1);
		*pbyte += 1;
		return ;
	}
	intx_conversion2(t, pbyte);
}

char	*ft_untoa3(char *dest, unsigned int n,
			unsigned int count, unsigned int s)
{
	while (count > 0)
	{
		dest[s] = n / count + '0';
		n = n % count;
		count = count / 10;
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

char	*ft_untoa2(unsigned int n, char *dest)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	s;

	count = 1;
	s = 0;
	i = n;
	while (i > 9)
	{
		i = i / 10;
		count = count * 10;
	}
	return (ft_untoa3(dest, n, count, s));
}

char	*ft_untoa(unsigned int n)
{
	unsigned int		size;
	unsigned int		temp;
	char				*dest;

	size = 0;
	if (n == 0)
		size = 1;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	if (n < 0)
		size++;
	dest = (char *)malloc(size + 1);
	if (!dest)
		return (NULL);
	return (ft_untoa2(n, dest));
}
