/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:55:57 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 17:24:47 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int		main(void)
{
	char *str;
	char find1[3];
	char find2[2];
	int i;

	i = 0;
	str = "Hello world!";
	find1[0] = 'o';
	find1[1] = 'r';
	find1[2] = '\0';
	find2[0] = '\0';
	find2[1] = '\0';
	printf("============test1============\n");
	printf("str : %s, to_find : %s\n", str, find1);
	printf("strstr : %s\n", strstr(str, find1));
	printf("ft_strstr : %s\n", ft_strstr(str, find1));
	printf("============test2============\n");
	printf("str : %s, to_find : %s\n", str, find2);
	printf("strstr : %s\n", strstr(str, find2));
	printf("ft_strstr : %s\n", ft_strstr(str, find2));
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
