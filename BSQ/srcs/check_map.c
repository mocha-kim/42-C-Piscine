/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <youngseon0218@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:35 by yoahn             #+#    #+#             */
/*   Updated: 2020/11/04 19:19:34 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_valid_map(char **map)
{
	int i;
	int j;

	if (g_info.width == 0 || g_info.height == 0)
		return (FALSE);
	if (ft_strlen(map[0]) < 4)
		return (FALSE);
	if (map[0][1] == map[0][2] || map[0][1] == map[0][3]
			|| map[0][2] == map[0][3])
		return (FALSE);
	i = 1;
	while (i < g_info.height)
	{
		if (ft_strlen(map[i]) != g_info.width)
			return (FALSE);
		j = 0;
		while (j < g_info.width)
		{
			if (map[i][j] != g_info.empty && map[i][j] != g_info.obstacle)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	free_map(char **map, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
