/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:45:48 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/20 19:58:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_numeric(char *str);

int		main(void)
{
	char str1[4];
	char str2[4];
	char str3[4];
	int result1;
	int result2;
	int result3;

	str1[0] = 'A';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0';
	str2[0] = '0';
	str2[1] = '4';
	str2[2] = '2';
	str2[3] = '\0';
	str3[0] = '\0';
	str3[1] = '\0';
	str3[2] = '\0';
	str3[3] = '\0';
	printf("str1 : %s\tstr2 : %s\tstr3 : %s\n", str1, str2, str3);
	result1 = ft_str_is_numeric(str1);
	result2 = ft_str_is_numeric(str2);
	result3 = ft_str_is_numeric(str3);
	printf("str1 : %d\tstr2 : %d\tstr3 : %d\n", result1, result2, result3);
	return (0);
}

int		ft_str_is_numeric(char *str)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			result = 0;
			break;
		}
		i++;
	}
	return (result);
}
