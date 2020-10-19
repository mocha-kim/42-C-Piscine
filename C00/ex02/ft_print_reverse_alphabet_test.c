/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet_test.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:24:30 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/17 15:59:38 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_print_reverse_alphabet(void);

int		main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}

void ft_print_reverse_alphabet(void)
{
	char	alphabet;

	alphabet = 'z';
	while (alphabet >= 'a')
	{
		write(1, &alphabet, 1);
		alphabet--;
	}
}
