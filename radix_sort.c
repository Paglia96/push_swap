/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:27:25 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/03 12:54:45 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	bit_len(int nb)
{
	int	bit_len;
	int	nb_moved;

	bit_len = 0;
	nb_moved = nb;
	while (nb_moved > 0)
	{
		bit_len++;
		nb_moved = nb_moved >> 1;
	}
	return (bit_len);
}

int	look_for_bit_0(t_list *a, int i)
{
	while (a)
	{
		if (((a->idx >> i) & 1) == 0)
			return (TRUE);
		a = a->next;
	}
	return (FALSE);
}

void	push_in_b_radix(t_list **a, t_list **b, t_count *count, int i)
{
	while (look_for_bit_0(*a, i))//il return e' booleano: TRUE ci sono ancora 0
	{
		if ((((*a)->idx >> i) & 1) == 0)
			push(b, a, 'b', count);
		else
			rotate(a, 'a', count);
	}
}

void	push_back_in_a_radix(t_list **a, t_list **b, t_count *count)
{
	while (*b)
		push(a, b, 'a', count);
}

void	radix_sort(t_list **a, t_list **b, t_count *count)
{
	int	i;
	int	len;
	
	(void)b;
	(void)count;
	i = 0;
	len = bit_len(greatest_index(*a));
	//printf("%d", len);
	while (i < len)
	{
		push_in_b_radix(a, b ,count, i);
		push_back_in_a_radix(a, b, count);
		i++;
	}
	ft_lstprint(*a, *b);
}

