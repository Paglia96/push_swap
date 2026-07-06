/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:31:33 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/06 17:46:14 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_call(t_list *lst)
{
	t_list	*ptr;

	(void)ptr;
	write(2, "Error\n", 6);
	free_lst(lst);
	exit(1);
}

void	ft_putnbr_moves(int n)
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

void	dispatcher(
	t_list **lst_a,
	t_list **lst_b,
	t_count *count,
	t_flags *flag)
{
	if (parsing_size(lst_a, lst_b, ft_lstsize(*lst_a), count))
		count->strategy = ft_strdup("Adaptive");
	if (!is_ordered(*lst_a))
	{
		if (flag->simple == 1 && !flag->complex_s && !flag->medium && !flag->adaptive)
			simple_min_max_extraction_method(lst_a, lst_b, count);
		else if (flag->medium == 1 && !flag->complex_s && !flag->simple && !flag->adaptive)
			chunk_sort(lst_a, lst_b, count);
		else if (flag->complex_s == 1 && !flag->medium && !flag->simple && !flag->adaptive)
			radix_sort(lst_a, lst_b, count);
		else if ((flag->adaptive == 1 || flag->adaptive == 0) && !flag->medium && !flag->complex_s && !flag->simple)
			choose_algorithm(lst_a, lst_b, count);
		else
			error_call(*lst_a);
	}
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_flags	flag;
	t_count	count;

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
	dispatcher(&lst_a, &lst_b, &count, &flag);
	if (flag.bench == 1)
		print_stats_on_stderr(&count);
	if (flag.bench == 0)
		free(count.strategy);
	free_lst(lst_a);
}
