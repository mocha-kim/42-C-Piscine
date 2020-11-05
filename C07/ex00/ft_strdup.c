/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:10:24 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/29 16:47:22 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != 0)
		i++;
	copy = (char *)malloc((i + 1) * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}
