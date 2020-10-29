/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:29:16 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 20:36:15 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_valid_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		count_base(char *base)
{
	int i;
	
	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	to_base_recursive(int nbr, char *base, int base_len)
{
	int	div;
	int mod;

	if (nbr >= base_len)
	{
		div = nbr / base_len;
		to_base_recursive(div, base, base_len);
	}
	mod = nbr % base_len;
	ft_putchar(base[mod]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	if (is_valid_base(base))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
		}
		base_len = count_base(base);
		to_base_recursive(nbr, base, base_len);
	}
}

int		main(void)
{
	int		number;
	char	base[] = "0123456789ABCDEF";

	number = -42;
	printf("number : %d, base : %s\n", number, base);
	ft_putnbr_base(number, base);
	return (0);
}
