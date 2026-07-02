/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:50:34 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/02 18:02:36 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	bit_len(int nb)
{
	int	i;
	int	bit;
	int	bit_len;
	int	nb_moved;

	i = 1;
	bit = 0;//non credo sia necessaria
	bit_len = 0;//non credo sia necessaria pt.2
	nb_moved = nb;
	while (i <= 32)//32 perche' al massimo sono 31 bit, ma si parte da 0
	{
		bit = nb_moved &1;
		nb_moved = nb_moved >> 1;
		if (bit == 1)
			bit_len = i;
		i++;
	}
	return (bit_len);
}