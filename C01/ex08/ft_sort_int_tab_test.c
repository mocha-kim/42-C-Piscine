/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:39:43 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/19 21:14:51 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int		main(void)
{
	int num[5];

	num[0] = 4;
	num[1] = 2;
	num[2] = 5;
	num[3] = 1;
	num[4] = 6;
	printf("before : %d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4]);
	ft_sort_int_tab(&num[0], 6);
	printf("after : %d, %d, %d, %d, %d\n", num[0], num[1], num[2], num[3], num[4]);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
