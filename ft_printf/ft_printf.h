#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*checkspecifer(char *str, va_list arg, int *bbyte);
char	*myprint(char *format, int *bbyte);
int		ft_printf(const char *format, ...);
char	*ft_itoa3(char *dest, int n, int count, int s);
char	*ft_itoa2(int n, char *dest);
char	*ft_itoa(int n);
void	intoutput(va_list arg, int *pbyte);
void	ft_putchar(char c);
void	charoutput(va_list arg, int *pbyte);
void	ft_putstr(char *s, int *pbyte);
void	base_conversion(unsigned long long t, int *pbyte);
char	*lowercase_conv(char *str);
void	int_conversion(unsigned int t, int *bbyte);
void	int_conversion2(unsigned int t, int *pbyte);
char	*uppercase_conv(char *str);
void	intx_conversion(unsigned int t, int *pbyte);
char	*checkspecifer2(char *str, va_list arg, int *bbyte);
char	*checkspecifer3(char *str, va_list arg, int *bbyte);
char	*checkspecifer4(char *str, va_list arg, int *bbyte);
void	base_conversion2(unsigned long long t, int *pbyte);
void	intx_conversion2(unsigned int t, int *pbyte);
char	*checkspecifer5(char *str, va_list arg, int *bbyte);
char	*checkspecifer6(char *str, va_list arg, int *bbyte);
char	*checkfield(char *str, va_list arg, int *bbyte);
char	*intoutput2(va_list arg, int *count);
char	*checkspecifer61(char *str, int *bbyte, unsigned int ui);
char	*checkspecifer71(char *str, int x, int *bbyte);
char	*checkspecifer72(char *str, int *bbyte, int x);
char	*checkspecifer7(char *str, va_list arg, int *bbyte);
char	*checkspecifer8(char *str, va_list arg, int *bbyte);
char	*checkspecifer81(char *str, int *bbyte, int x);
char	*ft_untoa(unsigned int n);
char	*ft_untoa2(unsigned int n, char *dest);
char	*ft_untoa3(char *dest, unsigned int n,
			unsigned int count, unsigned int s);
#endif