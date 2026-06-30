#include "push_swap.h"

void	error_call(t_list *lst)
{
	t_list	*ptr;

	write(1, "Error\n", 6);
	while (lst)
	{
		ptr = lst;
		lst = lst->next;
		free(ptr);
	}
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
		error_call(lst_a);
	else
	{
		args_parser(argv, &lst_a, &flag, 1);
		if (!lst_a)
			error_call(lst_a);
	}
	index_list(lst_a);
	if (flag.simple == 1 && !flag.complex_s && !flag.medium && !flag.adaptive)
		simple_min_max_extraction_method(&lst_a, &lst_b, &count);
	else if (flag.medium == 1 && !flag.complex_s && !flag.simple && !flag.adaptive)
		chunk_sort(&lst_a, &lst_b, &count);
	//else if (flag.complex_s == 1 && !flag.medium && !flag.simple && !flag.adaptive)
		//radix_sort();
	else if ((flag.adaptive == 1 || flag.adaptive == 0) && !flag.medium && flag.complex_s && !flag.simple)
		printf("%f", disorder(lst_a));
	else
		error_call(lst_a);
	//printf("pa: %d, pb: %d, sa: %d, sb: %d, ss: %d, ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d, total %d", count.pa, count.pb, count.sa, count.sb, count.ss, count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr, count.total);
}
