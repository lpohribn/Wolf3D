/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:18:48 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/23 13:18:50 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	ft_put_pixel(t_info *w, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && y < H && x < W)
		w->str[(y * W) + x] = color;
}

void	ft_draw(t_info *w)
{
	mlx_clear_window(w->mlx, w->win);
	ft_bzero(w->str, H * W * 4);
	ft_raycasting(w);
	ft_minimap(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	mlx_put_image_to_window(w->mlx, w->win, w->w[w->fl.tex_num].img,
	W / 2 - w->w[w->fl.tex_num].tex_w / 2, H - w->w[w->fl.tex_num].tex_h);
}

void	ft_events(t_info w)
{
	mlx_hook(w.win, 2, 5, ft_key, &w);
	mlx_hook(w.win, 3, 5, ft_key_unpressed, &w);
	mlx_hook(w.win, 17, 1L << 17, ft_exit, &w);
}
