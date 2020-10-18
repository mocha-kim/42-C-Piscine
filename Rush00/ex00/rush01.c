/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:53:03 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/18 16:54:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_row(int x, char first, char middle, char last)
{
	int column;

	column = 0;
	if (x == 1)
		ft_putchar(first);
	else if (x == 2)
	{
		ft_putchar(first);
		ft_putchar(last);
	}
	else
	{
		ft_putchar(first);
		while (column < x - 2)
		{
			ft_putchar(middle);
			column++;
		}
		ft_putchar(last);
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
				print_row(x, '/', '*', '\\');
			else if (row == y - 1)
				print_row(x, '\\', '*', '/');
			else
				print_row(x, '*', ' ', '*');
			row++;
		}
	}
}
