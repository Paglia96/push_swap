/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:07:59 by caguiari          #+#    #+#             */
/*   Updated: 2026/06/30 16:23:22 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_list *lst)
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
	return ((float) mistakes / (float) total_pairs);
}