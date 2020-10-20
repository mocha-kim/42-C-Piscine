/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:57:09 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/17 16:08:20 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_print_numbers(void);

int		main(void)
{
	ft_print_numbers();
	return (0);
}

void	ft_print_numbers(void)
{
	char number;

	number = '0';
	while (number <= '9')
	{
		write(1, &number, 1);
		number++;
	}
}