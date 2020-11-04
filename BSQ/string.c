/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <youngseon0218@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:18:10 by yoahn             #+#    #+#             */
/*   Updated: 2020/11/04 19:18:11 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_space(char ch)
{
	if (ch == '\n' || ch == '\v' || ch == '\f'
			|| ch == '\r' || ch == '\t' || ch == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int		size;
	int		result;
	int		len;

	size = 0;
	result = 0;
	len = ft_strlen(str);
	len -= 3;
	while (size < len && str[size] >= '0' && str[size] <= '9')
	{
		result = result * 10 + (str[size] - '0');
		size++;
	}
	return (result);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	*str;

	str = dest;
	while (*dest)
		dest++;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str);
}

char	*ft_strdup(char *result, char *src)
{
	int i;

	i = 0;
	if (!(result = (char*)malloc(sizeof(char) * (MAX_SIZE + 1))))
		return (0);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
