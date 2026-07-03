/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:07:59 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/03 17:39:42 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disorder(t_list *lst, t_count *count)
{
	int	mistakes;
	int	total_pairs;
	t_list	*j;

	mistakes = 0;
	total_pairs = 0;
	while (lst)
	{
		j = lst->next;
		while (j)
		{
			total_pairs++;
			if (lst->nb > j->nb)
				mistakes++;
			j = j->next;
		}
		lst = lst->next;
	}
	count->disorder = (float) mistakes / (float) total_pairs;
}

void	choose_algorithm(t_list **a, t_list **b, t_count *count)
{
	count->adaptive_called = TRUE;
	if (count->disorder < 0.2)
	{
		simple_min_max_extraction_method(a, b, count);
		count->strategy = ft_strdup("Adaptive / O(n²)");
	}
	else if (count->disorder >= 0.2 && count->disorder < 0.5)
	{	
		chunk_sort(a, b, count);
		count->strategy = ft_strdup("Adaptive / O(n√n)");
	}
	else
	{
		radix_sort(a, b, count);
		count->strategy = ft_strdup("Adaptive / O(n log n)");
	}
}