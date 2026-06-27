/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:19:20 by caguiari          #+#    #+#             */
/*   Updated: 2026/06/27 17:47:07 by caguiari         ###   ########.fr       */
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
	int j = 0;
	
	(void)a;
	(void)b;
	(void)count;
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
		
		i++;
	}
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
	nearest = target_idx_distance(intset[i], *a);
	while (i < chunk)
	{
		tmp = target_idx_distance(intset[i], *a);
		if ( tmp < nearest)
			nearest = tmp;
		i++;
	}
}