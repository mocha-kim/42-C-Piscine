/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:50:24 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/18 17:11:03 by sakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int row;

	row = 0;
	if (x > 0 && y > 0)
	{
		while (row < y)
		{
			if (row == 0)
				print_row(x, 'A', 'B');
			else if (row == y - 1)
				print_row(x, 'C', 'B');
			else
				print_row(x, 'B', ' ');
			row++;
		}
	}
}
