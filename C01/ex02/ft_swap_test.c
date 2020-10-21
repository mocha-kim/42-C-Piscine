/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:16:17 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/19 18:18:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int		main(void)
{
	int a;
	int b;

	a = 0;
	b = 42;
	printf("before : a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("after : a = %d, b = %d\n", a, b);
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
