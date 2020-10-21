/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:12:45 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/19 20:34:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int		main(void)
{
	int number[4];

	number[0] = 2;
	number[1] = 4;
	number[2] = 6;
	number[3] = 8;
	printf("before : %d, %d, %d, %d\n", number[0], number[1], number[2], number[3]);
	ft_rev_int_tab(&number[0], 4);
	printf("after : %d, %d, %d, %d\n", number[0], number[1], number[2], number[3]);
	return (0);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	while(i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}
