/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:21:01 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/17 17:54:04 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

int		main(void)
{
	ft_print_comb2();
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(j / 10 + '0');
			ft_putchar(j % 10 + '0');
			if (!(i == 98 && j == 99))
				write(1, &", ", 2);
			j++;
		}
		i++;
	}
}
