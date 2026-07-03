/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:50:34 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/03 10:59:41 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	main(void)
{
	int	n;

	n = 0;
	printf("%d", bit_len(n));
	return (0);
}