#include "validate.h"
#include "utils.h"

static int	check_for_non_numbers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_arguments(int argc, char **argv)
{
	int	error;

	error = 0;
	if (argc > 6 || argc < 5)
	{
		ft_putstr_fd("Error:\nWrong number of arguments\n", 2);
		error = 1;
	}
	else if (check_for_non_numbers(argv))
	{
		ft_putstr_fd("Error:\nNot valid argument\n", 2);
		error = 1;
	}
	return (error);
}
