/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:27:25 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/02 17:50:29 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **a, t_list **b, t_count *count)
{
	int	i;
	int	len;
	
	i = 0;
	len = bit_len(greatest_index(a));
	while (i < len)
	push_back_in_a(a, b, count);
}
