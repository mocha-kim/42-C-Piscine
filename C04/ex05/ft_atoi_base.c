/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:39:13 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/29 14:41:35 by sunhkim          ###   ########.fr       */
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

int		del_space_sign(char *str, int *index)
{
	int		i;
	int		sign;

	i = 0;
	while (str[i] == ' '|| str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == '\v')
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

int		get_base(char c, char *base)
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

int		ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		sign;
	int		result;
	int		i;

	base_len = 0;
	while(base[base_len] != '\0')
		base_len++;
	result = 0;
	sign = del_space_sign(str, &i);
	i = 0;
	while (str[i] && (get_base(str[i], base) != -1))
	{
		result *= base_len;
		result += get_base(str[i], base);
		i++;
	}
	return (result * sign);
}
