/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:19:48 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/04 18:45:56 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	size_3(t_list **a, int lst_size, t_count *count)
{
	if (lst_size == 3)
	{
		while (!is_ordered(*a))
		{
			if ((*a)->nb > (*a)->next->nb)
			{
				if (is_greatest_number((*a)->nb, *a))
					rotate(a, 'a', count);
				else
					swap(a, 'a', count);
			}
			else
				reverse_rotate(a, 'a', count);
		}
	}
}

static void	size_4(t_list **a, t_list **b, int lst_size, t_count *count)
{
	if (is_smallest_number((*a)->nb,*a))
		push(b, a, 'b', count);
}

void	parsing_size(t_list **a, t_list **b, int lst_size, t_count *count)
{
	if (lst_size == 2)
		swap(a, 'a', count);
	else if (lst_size == 3)
		size_3(a, lst_size, count);
	else if (lst_size == 4)
		size_4(a, b, lst_size, count);
}