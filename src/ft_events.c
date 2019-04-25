/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:52:48 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/17 14:52:50 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		ft_exit(void)
{
	system("pkill afplay");
	exit(1);
}

void	ft_key1(int key, t_info *w)
{
	if (key == 24 && w->p.mvspeed <= 0.9)
		w->p.mvspeed += 0.1;
	else if (key == 27 && w->p.mvspeed >= 0.3)
		w->p.mvspeed -= 0.1;
	else if (w->p.rotspeed <= 0.1 && key == 69)
		w->p.rotspeed += 0.01;
	else if (w->p.rotspeed >= 0.03 && key == 78)
		w->p.rotspeed -= 0.01;
}

int		ft_key(int key, t_info *w)
{
	if (key == 53)
		ft_exit();
	else if (key == 13)
		w->fl.up = 1;
	else if (key == 1)
		w->fl.down = 1;
	else if (key == 0)
		w->fl.left = 1;
	else if (key == 2)
		w->fl.right = 1;
	else if (key == 18)
		w->fl.tex_num = 0;
	else if (key == 19)
		w->fl.tex_num = 1;
	else if (key == 20)
		w->fl.tex_num = 2;
	else if (key == 21)
		w->fl.tex_num = 3;
	else
		ft_key1(key, w);
	ft_move(w);
	ft_draw(w);
	return (0);
}

int		ft_key_unpressed(int key, t_info *w)
{
	if (key == 13)
		w->fl.up = 0;
	if (key == 1)
		w->fl.down = 0;
	if (key == 0)
		w->fl.left = 0;
	if (key == 2)
		w->fl.right = 0;
	return (0);
}
