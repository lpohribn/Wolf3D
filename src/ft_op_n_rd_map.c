/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_n_rd_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:15:54 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/16 16:15:56 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

char				*ft_read_map(int fd)
{
	int		ret;
	char	*buff;
	char	*str;
	char	*tmp;

	str = ft_strnew(1);
	buff = ft_strnew(BUFF_S + 1);
	if ((!str || !buff) || read(fd, buff, 0) < 0)
	{
		ft_putendl(strerror(errno));
		ft_putendl("usage: ./wolf3d maps/lvl1");
		return (NULL);
	}
	while ((ret = read(fd, buff, BUFF_S)) > 0)
	{
		tmp = str;
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	free(buff);
	return (str);
}

int					ft_open(char *argv)
{
	int fd;

	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl(strerror(errno));
		ft_putendl("usage: ./wolf3d maps/lvl1");
		return (-1);
	}
	return (fd);
}
