/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:43:09 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/29 11:43:11 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_error(int n)
{
	if (n == -1)
		ft_putendl("usage: ./wolf3d maps/lvl1");
	else if (n == -2)
		ft_putendl("it didn't create connection");
	else if (n == -3)
		ft_putendl("it didn't create the window");
	else if (n == -4)
		ft_putendl("it didn't create the image");
	else if (n == -5)
		ft_putendl("it didn't allocate the memory for image");
	else if (n == -6)
		ft_putendl("it didn't allocate the memory");
	else if (n == -7)
		ft_putendl("bad texture");
	else if (n == -8)
		ft_putendl("not valid map");
	else if (n == -9)
		ft_putendl("not valid size");
	else if (n == -10)
		ft_putendl("not valid position");
	exit(0);
}
