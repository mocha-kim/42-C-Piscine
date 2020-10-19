/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:36:31 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/18 18:47:41 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		last_printed(int *numbers, int n)
{
	int count;
	int i;

	count = 0;
	i = n - 1;
	while (i >= 0)
	{
		if (numbers[i] == 10 + i - n)
		{
			count++;
		}
		i--;
	}
	if (count == n)
		return (1);
	else
		return (0);
}

void	ft_print_combn_recursive(int *numbers, int n, int curr, int prev)
{
	int i;

	i = 0;
	if (curr == n)
	{
		while (i < n)
		{
			ft_putchar(numbers[i] + '0');
			i++;
		}
		if (last_printed(numbers, n) == 0)
		{
			write(1, &", ", 2);
		}
	}
	else
	{
		i = prev + 1;
		while (i <= (10 - n) + curr)
		{
			numbers[curr] = i;
			ft_print_combn_recursive(numbers, n, curr + 1, i);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int numbers[n];
	int i;

	i = 0;
	if (n < 10 && n > 0)
	{
		while (i < n)
		{
			numbers[i] = -1;
			i++;
		}
		ft_print_combn_recursive(numbers, n, 0, -1);
	}
}
