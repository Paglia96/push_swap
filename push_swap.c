#include "push_swap.h"

void	error_call()
{
	write(1, "Error\n", 6);
	exit(1);
}

void	flags_initializer(t_flags *flag)
{
	flag->bench = FALSE;
	flag->simple = FALSE;
	flag->medium = FALSE;
	flag->complex_s = FALSE;
	flag->adaptive = FALSE;
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags flag;

	lst_a = NULL;
	lst_b = NULL;
	flags_initializer(&flag);

	if (argc == 1)
		error_call();
	else
	{
		args_parser(argv, &lst_a, &flag, 1);
		if (!lst_a)
			error_call();
	}
/*
	//PUSH_TEST
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	push(&lst_b, &lst_a, 'b');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	push(&lst_b, &lst_a, 'b');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	double_swap(&lst_a, &lst_b);
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	push(&lst_a, &lst_b, 'a');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	rotate(&lst_a, 'a');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	reverse_rotate(&lst_a, 'a');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	rotate(&lst_b, 'b');
	ft_lstprint(lst_a, lst_b);
	write(1, "----\n", 5);
	reverse_rotate(&lst_b, 'b');
	ft_lstprint(lst_a, lst_b);
*/
	//printf("\n%d", is_ordered(lst_a));
	//printf("\n%d", is_reverse_ordered(lst_a));

	insertion_sort(&lst_a, &lst_b);	
}
