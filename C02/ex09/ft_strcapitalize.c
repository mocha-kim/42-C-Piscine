/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:52:24 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/21 16:10:59 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int		is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	alpha_uplow(char *c, int is_first)
{
	if (is_first == 0 && *c >= 'A' && *c <= 'Z')
		*c = *c + 32;
	else if (is_first == 1 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

char	*ft_strcapitalize(char *str)
{
	int is_first;
	int i;

	is_first = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(is_alpha(str[i]) == 1 || is_numeric(str[i]) == 1))
			is_first = 1;
		else
		{
			if (is_first == 1)
			{
				alpha_uplow(&str[i], is_first);
				is_first = 0;
			}
			else
				alpha_uplow(&str[i], is_first);
		}
		i++;
	}
	return (str);
}
