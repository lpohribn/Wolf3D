/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:48:59 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/25 16:49:03 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_put_pix(t_info *w, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			ft_put_pixel(w, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_put_pix2(t_info *w, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			ft_put_pixel(w, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void		ft_minimap(t_info *w)
{
	int x;
	int i;
	int j;

	x = W - w->m.width * 7;
	i = 0;
	while (i < w->m.height)
	{
		j = 0;
		while (j < w->m.width)
		{
			if (w->map[i][j] != 0)
				ft_put_pix(w, x + j * 7, i * 7, 0x808080);
			ft_put_pix2(w, (int)(x + w->p.pos_y * 7),
			(int)(w->p.pos_x * 7), 0x00FF00);
			j++;
		}
		i++;
	}
}
