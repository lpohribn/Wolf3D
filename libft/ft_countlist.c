/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:43:32 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/16 18:43:35 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_countlist(t_list *list)
{
	size_t i;

	i = 0;
	if (!list)
		return (0);
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}
