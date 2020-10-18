/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:02:45 by sakang            #+#    #+#             */
/*   Updated: 2020/10/18 17:26:55 by sakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(int x, char side, char middle)
{
	int column;

	column = 0;
	if (x == 1)
		ft_putchar(side);
	else
	{
		ft_putchar(side);
		while (column < x - 2)
		{
			ft_putchar(middle);
			column++;
		}
		ft_putchar(side);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int b;

	b = 0;
	while (b < y)
	{
		if (b == 0 || b == (y - 1))
		{
			print_row(x, 'o', '-');
		}
		else
		{
			print_row(x, '|', ' ');
		}
		b++;
	}
}
