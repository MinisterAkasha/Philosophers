#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include "structures.h"
# include <sys/time.h>

long int	ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
long int	get_current_time(t_state *state);

#endif