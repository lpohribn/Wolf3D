/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:53:45 by lpohribn          #+#    #+#             */
/*   Updated: 2017/10/28 16:21:44 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] == str2[i] &&
		str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (i < n && (unsigned char)str1[i] != (unsigned char)str2[i])
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
