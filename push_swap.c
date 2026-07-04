#include "push_swap.h"

void	error_call(t_list *lst)
{
	t_list	*ptr;

	(void)ptr;
	write(2, "Error\n", 6);
	free_lst(lst);
	exit(1);
}

static void	ft_putnbr_moves(int n)
{
	if (n < 10)
	{
		write (2, &"0123456789"[n % 10], 1);
		return ;
	}
	ft_putnbr_moves(n / 10);
	write (2, &"0123456789"[n % 10], 1);
	return ;
}

static void	first_line(t_count *moves)
{
	float	var_1;
	float	var_2;

	write (2, "[bench] disorder:  ", 19);
	if (moves->disorder == 0.1000)
	{
		write (2, "100.00%\n", 8);
		return ;
	}
	var_1 = moves->disorder * 100;
	var_2 = (var_1 * 100) - ((int)var_1 * 100);
	ft_putnbr_moves((int) var_1);
	write (2, ".", 1);
	ft_putnbr_moves((int) var_2);
	if ((int) var_2 == 0)
		write (2, "0", 1);
	write (2, "%\n", 2);
}

static void	second_line(t_count *moves)
{
	(void)moves;
	write (2, "[bench] strategy:  ", 19);
	write (2, moves->strategy, ft_strlen(moves->strategy));
	free(moves->strategy);
	write (2, "\n", 1);
}

static void	third_and_fourth_lines(t_count *moves)
{
	write (2, "[bench] total_ops:  ", 20);
	ft_putnbr_moves(moves->total);
	write (2, "\n", 1);
	write (2, "[bench] ", 8);
	write (2, "sa:  ", 5);
	ft_putnbr_moves(moves->sa);
	write (2, "  sb:  ", 7);
	ft_putnbr_moves(moves->sb);
	write (2, "  ss:  ", 7);
	ft_putnbr_moves(moves->ss);
	write (2, "  pa:  ", 7);
	ft_putnbr_moves(moves->pa);
	write (2, "  pb:  ", 7);
	ft_putnbr_moves(moves->pb);
	write (2, "\n", 1);
}

static void	last_line(t_count *moves)
{
	write (2, "[bench] ", 8);
	write (2, "ra:  ", 5);
	ft_putnbr_moves(moves->ra);
	write (2, "  rb:  ", 7);
	ft_putnbr_moves(moves->rb);
	write (2, "  rr:  ", 7);
	ft_putnbr_moves(moves->rr);
	write (2, "  rra:  ", 8);
	ft_putnbr_moves(moves->rra);
	write (2, "  rrb:  ", 8);
	ft_putnbr_moves(moves->rrb);
	write (2, "  rrr:  ", 8);
	ft_putnbr_moves(moves->rrr);
	write (2, "\n", 1);
}

static void	print_stats_on_stderr(t_count *moves)
{
	first_line(moves);
	second_line(moves);
	third_and_fourth_lines(moves);
	last_line(moves);
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
	disorder(lst_a, &count);
	if (flag.simple == 1 && !flag.complex_s && !flag.medium && !flag.adaptive)
		simple_min_max_extraction_method(&lst_a, &lst_b, &count);
	else if (flag.medium == 1 && !flag.complex_s && !flag.simple && !flag.adaptive)
		chunk_sort(&lst_a, &lst_b, &count);
	else if (flag.complex_s == 1 && !flag.medium && !flag.simple && !flag.adaptive)
		radix_sort(&lst_a, &lst_b, &count);
	else if ((flag.adaptive == 1 || flag.adaptive == 0) && !flag.medium && !flag.complex_s && !flag.simple)
		choose_algorithm(&lst_a, &lst_b, &count);
	else
		error_call(lst_a);
	if (flag.bench == 1)
		print_stats_on_stderr(&count);
	if (flag.bench == 0)
		free(count.strategy);
}
