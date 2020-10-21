/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:25:49 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/19 18:41:31 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 42;
	b = 10;
	ft_div_mod(a, b, &div, &mod);
	printf("div : %d / %d = %d, mod : %d\n", a, b, div, mod);
	return (0);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
