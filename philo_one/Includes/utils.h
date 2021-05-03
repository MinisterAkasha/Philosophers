#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <unistd.h>

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);

#endif