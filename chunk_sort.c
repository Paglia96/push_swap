/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:19:20 by caguiari          #+#    #+#             */
/*   Updated: 2026/06/29 14:26:26 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_list **a, t_list **b, t_count *count)
{
	push_in_b(a, b, count);
	//push_back_in_a();
}

void	push_in_b(t_list **a, t_list **b, t_count *count)
{
	int	size;
	int	chunk;
	int	*intset;
	int	i;
	//int	nearest;
	//int j = 0;
	
	(void)a;
	(void)b;
	(void)count;
	//nearest = 
	i = 0;
	size = ft_lstsize(*a);
	chunk = round_sqrt(size);//qui decidiamo quanti chunk e da quanti numeri ciascuno
	intset = NULL;
	while (i < size)
	{
		if ( i % chunk == 0)
		{
			free(intset);
			intset = fill_intset(i, chunk);
		}
		if (nearest_nb(intset, a, chunk) <= ft_lstsize(*a) / 2)
		{
			while (nearest_nb(intset, a, chunk) != 0)
				rotate (a, 'a', count);
		}
		else
		{
			while (nearest_nb(intset, a, chunk) != 0)
				reverse_rotate (a, 'a', count);
		}
		push (b, a, 'b', count);
		i++;
	}
	//printf("%d\n", nearest_nb(intset, a, chunk));
	push_back_in_a(a, b, count);
	free(intset);
}

int	*fill_intset(int i, const int chunk)
{
	int	*ptr;
	int	j;

	j = 0;
	ptr = malloc (sizeof(int) * chunk);
	if (!ptr)
		return (NULL);
	while (j < chunk)
	{
		ptr[j] = i;
		i++;
		j++;
	}
	return (ptr);
}

int	nearest_nb(int *intset, t_list **a, int chunk)
{
	int	i;
	int	nearest;
	int	tmp;

	i = 0;
	nearest = INT_MAX;
	while (i < chunk)
	{
		tmp = target_idx_distance(intset[i], *a);
		if (tmp != -1 && tmp < nearest)
			nearest = tmp;
		i++;
	}
	return (nearest);
}