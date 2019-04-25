/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:22:07 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/16 12:22:09 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort(int *mass, int len)
{
	int i;

	if (!mass || !len)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (mass[i] > mass[i + 1])
		{
			ft_swap(&mass[i], &mass[i + 1]);
			i = 0;
		}
		i++;
	}
	return (mass);
}
