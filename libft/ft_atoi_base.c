/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:55:03 by lpohribn          #+#    #+#             */
/*   Updated: 2018/01/16 14:55:12 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int str_base, int pow)
{
	int n;

	n = str_base;
	if (pow == 0)
		return (1);
	while (--pow > 0)
		n *= str_base;
	return (n);
}

int	check(char c, int base)
{
	int n;

	if (c >= 'a' && c <= 'f')
		c -= 32;
	if (c == 'A')
		n = 10;
	else if (c == 'B')
		n = 11;
	else if (c == 'C')
		n = 12;
	else if (c == 'D')
		n = 13;
	else if (c == 'E')
		n = 14;
	else if (c == 'F')
		n = 15;
	if (c >= '0' && c <= '9')
		n = c - '0';
	if (n < base)
		return (n);
	return (-1);
}

int	ft_len(const char *s, int str_base)
{
	int i;

	i = 0;
	while (*s != '\0' && check(*s, str_base) != -1)
	{
		s++;
		i++;
	}
	return (i - 1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int s;
	int n;
	int pow;

	s = 1;
	n = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
		*str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			s = -1;
	pow = ft_len(str, str_base);
	while (check(*str, str_base) != -1 && *str)
	{
		n += check(*str, str_base) * ft_pow(str_base, pow);
		str++;
		pow--;
	}
	return (s * n);
}
