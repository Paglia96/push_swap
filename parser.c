#include "push_swap.h"

static int	duplicate_check(int n, t_list *lst)
{
	while (lst)
	{
		if (lst->nb == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static void	set_flag_move_index(int *flag, int *y, int offset)
{
	*flag = TRUE;
	*y += offset;
}

static void	flags_parser(t_flags *flag, char *str, int *y)
{
	*y += 2;
	if (str[2] == 'b' && !ft_strncmp(&str[2], "bench", 5))
		set_flag_move_index(&flag->bench, y, 5);		
	else if (str[2] == 's' && !ft_strncmp(&str[2], "simple", 6))
		set_flag_move_index(&flag->simple, y, 6);		
	else if (str[2] == 'm' && !ft_strncmp(&str[2], "medium", 6))
		set_flag_move_index(&flag->medium, y, 6);		
	else if (str[2] == 'c' && !ft_strncmp(&str[2], "complex", 7))
		set_flag_move_index(&flag->complex_s, y, 7);		
	else if (str[2] == 'a' && !ft_strncmp(&str[2], "adaptive", 8))
		set_flag_move_index(&flag->adaptive, y, 8);	
	else
		error_call();
}

void	args_parser(char **argv, t_list **lst, t_flags *flag, int i)
{
	int	y;
	int	nb;

	nb = 0;

	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (ft_isspace(argv[i][y]))
				y++;
			else if (argv[i][y] == '-' && argv[i][y + 1] == '-')
				flags_parser(flag, &argv[i][y], &y);
			else if (ft_isdigit(argv[i][y]) || ((argv[i][y] == '-' || argv[i][y] == '+') && ft_isdigit(argv[i][y + 1])))
			{
				nb = ft_atoi(&argv[i][y], &y);
				if (!duplicate_check(nb, *lst))
					ft_lstpush(lst, ft_lstnew(nb));
				else
					error_call();
			}
			else
				error_call();
		}
		i++;
	}
}

