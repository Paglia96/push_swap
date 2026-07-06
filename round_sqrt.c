/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguiari <caguiari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:13:14 by caguiari          #+#    #+#             */
/*   Updated: 2026/07/06 17:13:15 by caguiari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	round_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb + 1)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	i--; // arrotondata per difetto
	return (i);
}
/*
int	main(void)
{
	printf("%d", round_sqrt(500));
}
*/
