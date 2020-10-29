/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:32:28 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/20 22:02:56 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str);

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
	result = ft_strupcase(str);
	printf("after : %s\n", result);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
