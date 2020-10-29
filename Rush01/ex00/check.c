/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunhkim_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:20 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 14:31:31 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_duplicate(int **array, int rowcol, int index)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (rowcol == 0)
			{
				if (array[index][i] == array[index][j])
					return (0);
			}
			else
			{
				if (array[i][index] == array[j][index])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		set_target(int *params, int rowcol, int dir, int index)
{
	int result;

	if (rowcol == 0)
	{
		if (dir == 1)
			result = params[8 + index];
		else
			result = params[12 + index];
	}
	else
	{
		if (dir == 1)
			result = params[index];
		else
			result = params[4 + index];
	}
	return (result);
}

int		is_ok_row(int **array, int *params, int row, int dir)
{
	int i;
	int test;
	int target;
	int curr_max;
	int curr;

	i = -1;
	test = 0;
	curr_max = 0;
	if (!check_duplicate(array, 0, row))
		return (0);
	target = set_target(params, 0, dir, row);
	while (++i < 4)
	{
		if (dir == -1)
			curr = array[row][3 - i];
		else
			curr = array[row][i];
		if (curr > curr_max)
		{
			curr_max = curr;
			test++;
		}
	}
	return (test == target);
}

int		is_ok_column(int **array, int *params, int column, int dir)
{
	int i;
	int test;
	int target;
	int curr_max;
	int curr;

	i = -1;
	test = 0;
	curr_max = 0;
	if (!check_duplicate(array, 1, column))
		return (0);
	target = set_target(params, 1, dir, column);
	while (++i < 4)
	{
		if (dir == -1)
			curr = array[3 - i][column];
		else
			curr = array[i][column];
		if (curr > curr_max)
		{
			curr_max = curr;
			test++;
		}
	}
	return (test == target);
}

int		check_success(int **array, int *params)
{
	int row;
	int column;

	row = 0;
	while (row < 4)
	{
		if (!is_ok_row(array, params, row, 1))
			return (0);
		if (!is_ok_row(array, params, row, -1))
			return (0);
		column = 0;
		while (column < 4)
		{
			if (!is_ok_column(array, params, column, 1))
				return (0);
			if (!is_ok_column(array, params, column, -1))
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}
