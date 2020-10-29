/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:12:44 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/22 12:58:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int		main(void)
{
	char str[6];
	char result[4];
	char ft_result[4];
	unsigned int return_int;

	str[0] = 'H';
	str[1] = 'E';
	str[2] = 'L';
	str[3] = 'L';
	str[4] = 'O';
	str[5] = '\0';
	printf("before : %s, %s\n", result, ft_result);
	printf("============strlcpy============\n");
	return_int = strlcpy(result, str, 0);
	printf("source : %s, destination : %s, return : %d\n", str, result, return_int);
	printf("===========ft_strlcpy===========\n");
	return_int = ft_strlcpy(ft_result, str, 0);
	printf("source : %s, destination : %s, return : %d\n", str, ft_result, return_int);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int src_size;

	i = 0;
	src_size = 0;
	while (src[i] != '\0')
	{
		src_size++;
		i++;
	}
	i = 0;
	if (size)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_size);
}
