/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:22:59 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/23 13:23:01 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int				ft_check_confines(t_info *w)
{
	int i;

	i = 0;
	while (i < w->m.width - 1)
	{
		if (w->map[0][i] == 0)
			ft_error(-8);
		if (w->map[w->m.height - 1][i] == 0)
			ft_error(-8);
		i++;
	}
	i = 0;
	while (i < w->m.height - 1)
	{
		if (w->map[i][0] == 0)
			ft_error(-8);
		if (w->map[i][w->m.width - 1] == 0)
			ft_error(-8);
		i++;
	}
	return (0);
}

void			ft_current_position(t_info *w)
{
	if (w->map[(int)w->p.pos_x][(int)w->p.pos_y] != 0)
		ft_error(-10);
}

static int		ft_check_char(char **array)
{
	int i;
	int j;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == ' ' ||
			(array[i][j] >= '0' && array[i][j] <= '9') ||
			array[i][j] <= '\n')
				j++;
			else
				ft_error(-8);
		}
		i++;
	}
	return (0);
}

static int		ft_id_parameters(t_info *w, char **array)
{
	w->m.height = 0;
	w->m.width = ft_countwords(array[0], ' ');
	while (array[w->m.height] != NULL)
	{
		if (w->m.width != ft_countwords(array[w->m.height], ' '))
			ft_error(-9);
		w->m.height++;
	}
	if (w->m.width < 2 || w->m.height < 2)
		ft_error(-9);
	return (w->m.height);
}

int				ft_validation(char **array, t_info *w)
{
	if (ft_check_char(array) == 0)
	{
		if (!(ft_id_parameters(w, array)))
			return (0);
	}
	else
		return (0);
	return (1);
}
