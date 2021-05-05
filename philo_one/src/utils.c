#include "utils.h"
#include "structures.h"
#include <sys/time.h>

long int	ft_atoi(const char *str)
{
	int			sign;
	long int	sum;

	sign = 1;
	sum = 0;
	while (*str == 0 || *str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
	{
		if (*str++ == '\0')
			return (0);
	}
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sum * 10 < sum && sign == 1)
			return (-1);
		if (sum * 10 < sum && sign == -1)
			return (0);
		sum = sum * 10 + (*str++ - 48);
	}
	return ((long int)(sum * sign));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * (-1), fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

long int get_current_time(t_state *state)
{
	static struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - state->start_time);
}
