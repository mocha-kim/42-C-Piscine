/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:23:08 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/01 14:26:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		del_space_sign(char *str, int *index)
{
	int		i;
	int		sign;

	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	while (is_sign(str[i]) != '\0')
	{
		sign *= is_sign(str[i]);
		i++;
	}
	*index = i;
	return (sign);
}

int		is_valid_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (is_sign(base[i]) || is_space(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		get_base_index(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
