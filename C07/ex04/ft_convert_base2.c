/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:35:29 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/03 19:57:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		del_space_sign(char *str, int *index);
int		is_valid_base(char *base);
int		get_base_index(char c, char *base);

int		ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int		cal_result_len(int nbr, int base_len)
{
	int		length;

	length = 0;
	if (nbr < 0)
		length++;
	while (1)
	{
		length++;
		if (nbr / base_len == 0)
			break ;
		nbr /= base_len;
	}
	return (length);
}

char	*decimal_to_base(char *base, unsigned int nbr, int neg, int base_len)
{
	int		i;
	int		length;
	char	*result;

	length = cal_result_len(nbr, base_len);
	if (nbr == 0)
		neg = 0;
	if (nbr == 2147483648)
		length--;
	if (!(result = (char *)malloc(sizeof(char) * (length + neg + 1))))
		return (0);
	if (neg)
		result[0] = '-';
	i = 0;
	while (i < length)
	{
		result[length - 1 + neg - i] = base[nbr % base_len];
		nbr /= base_len;
		i++;
	}
	result[length + neg] = 0;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				i;
	int				neg;
	int				base_index;
	int				base_len;
	unsigned int	nbr_unsigned;

	if (!is_valid_base(base_from) || !(is_valid_base(base_to)))
		return (0);
	nbr_unsigned = 0;
	if (del_space_sign(nbr, &i) == -1)
		neg = 1;
	else
		neg = 0;
	base_len = ft_strlen(base_from);
	while ((base_index = get_base_index(nbr[i], base_from)) != -1)
	{
		nbr_unsigned *= base_len;
		nbr_unsigned += base_index;
		i++;
	}
	base_len = ft_strlen(base_to);
	return (decimal_to_base(base_to, nbr_unsigned, neg, base_len));
}
