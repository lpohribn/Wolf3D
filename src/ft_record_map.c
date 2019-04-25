/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_record_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:25:39 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/23 13:25:41 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static	void	ft_record(t_info *w, char **tmp, int i)
{
	int j;

	j = 0;
	while (j < w->m.width)
	{
		w->map[i][j] = ft_atoi(tmp[j]);
		if (w->map[i][j] > 9 || w->map[i][j] < 0)
			ft_error(-8);
		free(tmp[j]);
		j++;
	}
}

int				ft_create_mass(t_info *w, char **array)
{
	int		i;
	char	**tmp;

	if (!(w->map = (int**)malloc(sizeof(int*) * (w->m.height + 1))))
		ft_error(-6);
	i = 0;
	while (i < w->m.height)
	{
		tmp = ft_strsplit(array[i], ' ');
		if (!(w->map[i] = (int*)malloc(sizeof(int) * w->m.width)))
			ft_error(-6);
		ft_record(w, tmp, i);
		free(tmp);
		free(array[i]);
		i++;
	}
	w->map[w->m.height] = NULL;
	ft_check_confines(w);
	ft_current_position(w);
	return (0);
}
