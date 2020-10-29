/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:33:02 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/26 19:23:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_addr(void *addr)
{
	int		i;
	char	addr_tab[16];
	long	addr_num;

	addr_num = (long)addr;
	i = 0;
	while (addr_num > 0)
	{
		addr_tab[i] = addr_num % 16;
		if (addr_tab[i] < 10)
			addr_tab[i] = addr_tab[i] + '0';
		else
			addr_tab[i] = addr_tab[i] + 87;
		addr_num = addr_num / 16;
		i++;
	}
	i--;
	while (++i < 16)
		addr_tab[i] = '0';
	while (--i >= 0)
		ft_putchar(addr_tab[i]);
}

void	to_hexa(char c)
{
	char	div;
	char	mod;
	int		c_ne;

	if (c < 0)
	{
		c_ne = c + 256;
		div = c_ne / 16;
		mod = c_ne % 16;
	}
	else
	{
		div = c / 16;
		mod = c % 16;
	}
	if (div < 10)
		ft_putchar(div + '0');
	else
		ft_putchar(div + 87);
	if (mod < 10)
		ft_putchar(mod + '0');
	else
		ft_putchar(mod + 87);
}

void	print_str(void *addr, int size)
{
	int		i;
	int		space;
	char	*curr;

	i = 0;
	curr = (char *)addr;
	while (i < size)
	{
		to_hexa(curr[i]);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	i = 0;
	space = (16 - size) * 2 + (16 - size + 1) / 2;
	while (i++ < space)
		write(1, " ", 1);
	i = -1;
	while (i++ < size)
	{
		if (curr[i] >= 32 && curr[i] <= 126)
			write(1, &curr[i], 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	curr;
	unsigned int	column_len;

	curr = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			column_len = 16;
			size = size - 16;
		}
		else
		{
			column_len = size;
			size = 0;
		}
		print_addr(addr + curr);
		write(1, ": ", 2);
		print_str(addr + curr, column_len);
		write(1, "\n", 1);
		curr = curr + 16;
	}
	return (addr);
}
