/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <jsg2804@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:52 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/05 00:49:06 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			find_bsq_at_point(char **map, t_location location, int size)
{
	int i;
	int j;

	while (1)
	{
		i = location.x;
		while (i < size + location.x && i < g_info.height)
		{
			j = location.y - 1;
			while (++j < size + location.y && j < g_info.width)
			{
				if (i + 1 != g_info.height)
				{
					if (map[i + 1][j] == g_info.obstacle)
						return (size);
				}
				else
					return (size);
				if (map[i][j + 1] == g_info.obstacle || map[i][j + 1] == 0)
					return (size);
			}
			i++;
		}
		size++;
	}
}

t_location	find_bsq(char **map)
{
	t_location	max;
	t_location	curr;

	curr.x = 0;
	max.max_size = 0;
	curr.max_size = 0;
	while (++curr.x < g_info.height)
	{
		if (curr.max_size >= g_info.height - curr.x)
			break ;
		curr.y = -1;
		while (++curr.y < g_info.width)
		{
			if (map[curr.x][curr.y] == g_info.obstacle)
				continue ;
			curr.max_size = find_bsq_at_point(map, curr, max.max_size);
			if (curr.max_size > max.max_size)
			{
				max.x = curr.x;
				max.y = curr.y;
				max.max_size = curr.max_size;
			}
		}
	}
	return (max);
}

void		fill_map(char **map, t_location location)
{
	int		i;
	int		j;
	char	**result;

	if (!(result = (char **)malloc(sizeof(char *) * g_info.height)))
		return ;
	i = 0;
	while (i < g_info.height)
	{
		result[i] = (char *)malloc(sizeof(char) * g_info.width);
		ft_strcpy(result[i], map[i]);
		i++;
	}
	i = 0;
	while (i < location.max_size)
	{
		j = -1;
		while (++j < location.max_size)
			result[i + location.x][j + location.y] = g_info.full;
		i++;
	}
	print_map(result);
	free_map(result, g_info.height);
}

void		progress_map(char **map)
{
	t_location location;

	location = find_bsq(map);
	fill_map(map, location);
	free_map(map, g_info.height);
}
