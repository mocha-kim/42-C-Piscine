/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:03:15 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/17 15:11:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	ft_print_alphabet(void);

int		main(void)
{
	ft_print_alphabet();
	return (0);
}

void	ft_print_alphabet(void)
{
	char	alphabet;

	alphabet = 'a';
	while (alphabet <= 'z')
	{
		write(1, &alphabet, 1);
		alphabet++;
	}
}
