/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:07:59 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/01 17:06:07 by caguiari         ###   ########.fr       */
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