/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:17:00 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/22 01:12:13 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int		main(void)
{
	char str1[6];
	char str2[6];

	str1[0] = 'H';
	str1[1] = 'e';
	str1[2] = 'l';
	str1[3] = 'l';
	str1[4] = 'o';
	str1[5] = '\0';
	str2[0] = 'W';
	str2[1] = 'o';
	str2[2] = 'r';
	str2[3] = 'l';
	str2[4] = 'd';
	str2[5] = '\0';
	printf("str1 : %s, str2 : %s, n : %d\n", str1, str2, 3);
	printf("ft_strcat : %s\n", ft_strncat(str1, str2, 3));
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int dest_len;
	unsigned int i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
