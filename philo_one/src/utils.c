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

long int get_current_time(t_state *state)
{
	static struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - state->start_time);
}
