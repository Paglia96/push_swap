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

