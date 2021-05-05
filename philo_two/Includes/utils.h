#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "structures.h"
# include <sys/time.h>

long int	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
long int	get_current_time(t_state *state);
void		my_usleep(unsigned int time);

#endif