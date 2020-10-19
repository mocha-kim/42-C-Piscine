/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:24:43 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/17 16:32:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_is_negative(int n);

int		main(void)
{
	ft_is_negative(20);
	ft_is_negative(-10);
	return (0);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, &"N", 1);
	else
		write(1, &"P", 1);
}
