/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim </var/mail/sunhkim>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:58:12 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/22 17:00:52 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int		main(void)
{
	char str1[] = "scqwe?\afdfa1af*/f\nfAsfdR. fdvfdavw l;NB(q] rrs%sd%g\%\";";
	char str2[5];

	str2[0] = -11;
	str2[1] = 4;
	str2[2] = '\203';
	str2[3] = 28;
	str2[4] = 0;
	printf("============test1============\n");
	printf("before : %s\n", str1);
	ft_putstr_non_printable(str1);
	printf("============test2============\n");
	printf("before : %s\n", str2);
	ft_putstr_non_printable(str2);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_hexa(char c)
{
	char div;
	char mod;
	int c_ne;

	ft_putchar('\\');
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

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			to_hexa(str[i]);
		i++;
	}
}
