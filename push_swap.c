#include "push_swap.h"

void	error_call()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags flag;
	t_count count;

	lst_a = NULL;
	lst_b = NULL;
	flags_initializer(&flag);
	count_initializer(&count);

	if (argc == 1)
		error_call();
	else
	{
		args_parser(argv, &lst_a, &flag, 1);
		if (!lst_a)
			error_call();
	}

	simple_min_max_extraction_method(&lst_a, &lst_b, &count);

	printf("pa: %d, pb: %d, sa: %d, sb: %d, ss: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d, total %d", count.pa, count.pb, count.sa, count.sb, count.ss, count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr, count.total);
}
