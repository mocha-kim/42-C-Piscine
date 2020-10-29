/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunhkim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:00 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 12:27:43 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*atoi_params(char *params);
int		solve_puzzle(int **array, int *params);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		**init_box(int size)
{
	int		i;
	int		j;
	int		**array;

	array = (int **)malloc((size + 1) * sizeof(int *));
	i = 0;
	while (i < size)
	{
		array[i] = (int *)malloc((size + 1) * sizeof(int));
		j = 0;
		while (j < size + 1)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
	array[size] = 0;
	return (array);
}

void	print_box(int **array, int error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (error)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(array[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		progress_box(char *params, int size)
{
	int		i;
	int		**array;
	int		catch_error;
	int		*params_int;

	catch_error = 0;
	params_int = atoi_params(params);
	array = init_box(size);
	catch_error = !solve_puzzle(array, params_int);
	print_box(array, catch_error);
	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	return (catch_error);
}
