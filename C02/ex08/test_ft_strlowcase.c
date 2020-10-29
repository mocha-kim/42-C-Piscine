/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:04:30 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/20 22:05:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int		main(void)
{
	char str[6];
	char *result;

	str[0] = 'h';
	str[1] = 'E';
	str[2] = 'l';
	str[3] = 'L';
	str[4] = 'o';
	str[5] = '\0';
	printf("before : %s, ", str);
	result = ft_strlowcase(str);
	printf("after : %s\n", result);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

