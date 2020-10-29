/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunhkim_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:38 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 12:26:25 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		validate_params(char *params)
{
	int i;
	int catch_error;

	i = -1;
	while (params[++i] != '\0')
	{
		if (params[i] >= '1' && params[i] <= '4')
			catch_error = 0;
		else if (params[i] == ' ')
		{
			if (params[i + 1] >= '1' && params[i + 1] <= '4')
				catch_error = 0;
			else
			{
				catch_error = 1;
				break ;
			}
		}
		else
		{
			catch_error = 1;
			break ;
		}
	}
	return (catch_error);
}

int		*atoi_params(char *params)
{
	int i;
	int j;
	int *result;

	i = 0;
	j = 0;
	result = (int *)malloc(16 * sizeof(int));
	while (params[i] != '\0')
	{
		if (params[i] >= '1' && params[i] <= '4')
		{
			result[j] = params[i] - '0';
			j++;
		}
		i++;
	}
	return (result);
}
