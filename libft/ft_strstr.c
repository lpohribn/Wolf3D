/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:12:57 by lpohribn          #+#    #+#             */
/*   Updated: 2017/10/29 18:20:08 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	if (str2[i] == '\0')
		return (&((char*)str1)[i]);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
				return (&((char*)str1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
