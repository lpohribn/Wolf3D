/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:31:43 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/07 18:59:38 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*s;
	size_t	i;

	if (!size)
		return (NULL);
	i = 0;
	if (!(s = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char*)s)[i] = 0;
		i++;
	}
	return (s);
}
