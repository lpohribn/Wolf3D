/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:08:52 by lpohribn          #+#    #+#             */
/*   Updated: 2017/12/28 19:09:01 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_list(t_list *p, const int fd)
{
	while (p->next != NULL)
	{
		if (((int)p->content_size) != fd)
			p = p->next;
		else
			return (p);
	}
	if (((int)p->content_size) != fd)
	{
		if (!(p->next = ft_lstnew("", fd)))
			return (NULL);
		p = p->next;
	}
	return (p);
}

int		ft_read(t_list *p, char *buff, const int fd)
{
	int		i;
	char	*tmp;

	while ((ft_strchr(p->content, '\n')) == NULL &&
		(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = p->content;
		if (!(p->content = ft_strjoin(p->content, buff)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int		ft_rest_of_line(t_list *p, int i)
{
	int		j;
	void	*tmp;

	if (((char*)p->content)[i] == '\n')
		i++;
	tmp = p->content;
	j = ft_strlen(&((char*)p->content)[i]);
	if (!(p->content = ft_strsub(p->content, i, j)))
		return (-1);
	free(tmp);
	return (1);
}

int		ft_line(char **line, t_list *p)
{
	int i;

	i = 0;
	if ((ft_strlen(p->content)) == 0)
		return (0);
	while (((char*)p->content)[i] != '\0' && ((char*)(p->content))[i] != '\n')
		i++;
	if (!(*line = ft_strnew(i)))
		return (-1);
	ft_strncpy(*line, p->content, i);
	if (ft_rest_of_line(p, i) == -1)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_list	*begin;
	t_list			*p;
	int				ret;

	if (BUFF_SIZE < 0)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (begin == NULL)
	{
		if (!(begin = ft_lstnew("", fd)))
			return (-1);
	}
	if (!(p = ft_create_list(begin, fd)))
		return (-1);
	if (!(ft_read(p, buff, fd) == 1))
		return (-1);
	free(buff);
	if ((ret = ft_line(line, p)) == -1)
		return (-1);
	return (ret == 1 ? 1 : 0);
}
