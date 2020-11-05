/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:35:39 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/01 11:54:19 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int		cal_total_len(int size, char **strs, char *sep)
{
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		total_len;

	i = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_len = cal_total_len(size, strs, sep);
	if (!(result = (char *)malloc(sizeof(char) * (total_len + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
