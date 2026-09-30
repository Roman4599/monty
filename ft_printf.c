#include "monty.h"
#include <unistd.h>

/*
** ft_putchar - Write one character on a file descriptor
** fd: the file descriptor to write on (int)
** c: the character to write (char)
** return: nothing
*/
void	ft_putchar(int fd, char c)
{
	if (write(fd, &c, 1) == -1)
		return ;
}

/*
** ft_putstr - Write a string on a file descriptor
** fd: the file descriptor to write on (int)
** str: the string to write (char *)
** return: nothing
*/
void	ft_putstr(int fd, char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len == 0)
		return ;
	if (write(fd, str, len) == -1)
		return ;
}

/*
** ft_putnbr - Write an integer on a file descriptor
** fd: the file descriptor to write on (int)
** n: the number to write (int)
** return: nothing
*/
void	ft_putnbr(int fd, int n)
{
	char	digits[12];
	int		len;
	int		i;

	len = 0;
	if (n < 0)
	{
		ft_putchar(fd, '-');
		n = -n;
	}
	if (n == 0)
		digits[len++] = '0';
	while (n > 0)
	{
		digits[len] = (char)('0' + (n % 10));
		n = n / 10;
		len++;
	}
	digits[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		ft_putchar(fd, digits[i]);
		i--;
	}
}
