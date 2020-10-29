/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunhkim_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:57 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 12:27:03 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_success(int **array, int *params);

int		ft_power(int x, int n)
{
	int result;

	result = 1;
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result *= x;
		n--;
	}
	return (result);
}

int		fill_row(int *row, int offset)
{
	int i;
	int j;
	int offset_cal;

	i = 0;
	offset_cal = 1;
	while (i < 4)
	{
		row[3 - i] = (offset / offset_cal) % 4 + 1;
		offset_cal *= 4;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (row[i] == row[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		solve_recursive(int **array, int *params, int max, int row)
{
	int offset;
	int success;

	offset = 0;
	if (row >= 4)
		return (check_success(array, params));
	while (offset < max)
	{
		success = fill_row(array[row], offset);
		if (success)
		{
			success = solve_recursive(array, params, max, row + 1);
			if (success)
				return (1);
		}
		offset++;
	}
	return (0);
}

int		solve_puzzle(int **array, int *params)
{
	int success;
	int max;

	max = ft_power(4, 4);
	success = solve_recursive(array, params, max, 0);
	return (success);
}
