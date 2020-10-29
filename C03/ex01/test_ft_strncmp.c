/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:10:19 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 17:18:40 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	char str1[6];
	char str2[3];
	char str3[5];
	int i;

	str1[0] = 'H';
	str1[1] = 'E';
	str1[2] = 'L';
	str1[3] = 'L';
	str1[4] = 'O';
	str1[5] = '\0';
	str2[0] = '\0';
	str2[1] = '\0';
	str2[2] = '\0';
	i = 0;
	while (str1[i] != '\0')
	{
		str3[i] = str1[i];
		i++;
	}
	str3[4] = '\0';
	printf("========test1 : %s vs %s, %d========\n", str1, str2, 2);
	printf("strncmp : %d, ft_strncmp : %d\n", strncmp(str2, str1, 2), ft_strncmp(str2, str1, 2));
	printf("========test2 : %s vs %s, %d========\n", str1, str3, 4);
	printf("strncmp : %d, ft_strncmp : %d\n", strncmp(str1, str3, 4), ft_strncmp(str1, str3, 4));
	printf("========test3 : %s vs %s, %d========\n", str1, str3, 5);
	printf("strncmp : %d, ft_strncmp : %d\n", strncmp(str1, str3, 5), ft_strncmp(str1, str3, 5));
	return (0);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0 || s2 == 0)
	{
		if (s1 > s2)
			return (1);
		else
			return (-1);
	}
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] != '\0' && i < (n - 1))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
