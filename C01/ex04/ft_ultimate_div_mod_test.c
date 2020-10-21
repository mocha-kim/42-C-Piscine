/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:14:01 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/19 19:19:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int		main(void)
{
	int a;
	int b;

	a = 42;
	b = 10;
	printf("before : a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after : a = %d, b = %d\n", a, b);
	return (0);
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}
