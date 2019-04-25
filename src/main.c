/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:03:10 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/15 18:03:11 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_info(t_info *w)
{
	w->p.pos_x = 1 + 0.5;
	w->p.pos_y = 1 + 0.5;
	w->p.dir_x = -1;
	w->p.dir_y = 0;
	w->p.plane_x = 0;
	w->p.plane_y = 0.66;
	w->p.mvspeed = 0.1;
	w->p.rotspeed = 0.03;
	w->fl.tex_num = 0;
}

void		ft_init(t_info *w)
{
	if (!(w->mlx = mlx_init()))
		ft_error(-2);
	if (!(w->win = mlx_new_window(w->mlx, W, H, "Wolf3d")))
		ft_error(-3);
	if (!(w->img = mlx_new_image(w->mlx, W, H)))
		ft_error(-4);
	if (!(w->str = (int*)mlx_get_data_addr(w->img, &w->bp, &w->bl, &w->endian)))
		ft_error(-5);
}

int			main(int argc, char **argv)
{
	t_info	w;
	char	*str;
	char	**array;

	if (argc != 2)
		ft_error(-1);
	if (!(str = (ft_read_map(ft_open(argv[1])))))
		return (0);
	array = ft_strsplit(str, '\n');
	if (ft_validation(array, &w) != 0)
	{
		ft_info(&w);
		ft_create_mass(&w, array);
		ft_init(&w);
		ft_textures(&w);
		ft_draw(&w);
		ft_events(w);
		system("afplay SOAD.mp3&");
		free(array);
		free(str);
		mlx_loop(w.mlx);
	}
	return (0);
}
