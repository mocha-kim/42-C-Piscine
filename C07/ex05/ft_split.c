/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:14:32 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/05 19:05:48 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchar(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == str[i])
		return ((char *)&str[i]);
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

int				count_word(char *str, char *charset)
{
	int	i;
	int	count;

	if (!str[0])
		return (0);
	i = 0;
	count = 0;
	while (str[i] && ft_strchar(charset, str[i]))
		i++;
	while (str[i])
	{
		if (ft_strchar(charset, str[i]))
		{
			count++;
			while (str[i] && ft_strchar(charset, str[i]))
				i++;
			continue ;
		}
		i++;
	}
	if (!ft_strchar(charset, str[i - 1]))
		count++;
	return (count);
}

void			ft_next_str(char **next, int *next_len, char *charset)
{
	int i;

	*next += *next_len;
	*next_len = 0;
	i = 0;
	while (**next != 0 && ft_strchar(charset, **next))
		(*next)++;
	while ((*next)[i])
	{
		if (ft_strchar(charset, (*next)[i]))
			return ;
		(*next_len)++;
		i++;
	}
}

char			**ft_split(char *str, char *charset)
{
	char	**tab;
	char	*next;
	int		next_len;
	int		count;
	int		i;

	count = count_word(str, charset);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	next = str;
	next_len = 0;
	while (i < count)
	{
		ft_next_str(&next, &next_len, charset);
		if (!(tab[i] = malloc(sizeof(char) * (next_len + 1))))
			return (0);
		ft_strlcpy(tab[i], next, next_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
