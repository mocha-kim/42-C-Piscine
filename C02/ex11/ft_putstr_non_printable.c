/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:58:12 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 16:36:35 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_hexa(char c)
{
	char	div;
	char	mod;
	int		c_ne;

	ft_putchar('\\');
	if (c < 0)
	{
		c_ne = c + 256;
		div = c_ne / 16;
		mod = c_ne % 16;
	}
	else
	{
		div = c / 16;
		mod = c % 16;
	}
	if (div < 10)
		ft_putchar(div + '0');
	else
		ft_putchar(div + 87);
	if (mod < 10)
		ft_putchar(mod + '0');
	else
		ft_putchar(mod + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			to_hexa(str[i]);
		i++;
	}
}
