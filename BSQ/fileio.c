/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <youngseon0218@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:18:54 by yoahn             #+#    #+#             */
/*   Updated: 2020/11/05 00:24:35 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	first_line(char *line)
{
	int height;
	int length;

	length = ft_strlen(line);
	if (line == 0 || length < 4)
		return ;
	if (line[0] <= '0' || line[0] >= '9')
		return ;
	g_info.empty = line[length - 3];
	g_info.obstacle = line[length - 2];
	g_info.full = line[length - 1];
	height = ft_atoi(line);
	height++;
	g_info.height = height;
}

char	**ft_open(char *path)
{
	char	*line;
	char	**map;
	int		i;

	if ((g_fd = open(path, O_RDONLY)) == -1)
		return (0);
	i = 1;
	g_eof = 0;
	if (!(line = ft_fread()))
		return (0);
	first_line(line);
	if (!(map = (char**)malloc(sizeof(char*) * (g_info.height + 1))))
		return (0);
	map[0] = ft_strdup(map[0], line);
	free(line);
	while (i < g_info.height && (line = ft_fread()))
	{
		if (g_eof++)
			break ;
		map[i] = ft_strdup(map[i], line);
		free(line);
		i++;
	}
	map[g_info.height] = last_line();
	return (map);
}

char	*last_line(void)
{
	char	*line;
	int		i;

	line = (char*)malloc(sizeof(char) * g_info.width);
	i = 0;
	while (i < g_info.width)
		line[i++] = g_info.obstacle;
	return (line);
}

char	**ft_stdread(void)
{
	char	*line;
	char	**map;
	int		i;

	if (!(line = ft_fread()))
		return (0);
	first_line(line);
	if (!(map = (char**)malloc(sizeof(char*) * (g_info.height + 1))))
		return (0);
	map[0] = ft_strdup(*map, line);
	free(line);
	i = 1;
	while (i < g_info.height && (line = ft_fread()))
	{
		map[i] = ft_strdup(map[i], line);
		free(line);
		i++;
	}
	map[g_info.height] = last_line();
	return (map);
}

char	*ft_fread(void)
{
	char	*line;
	int		i;
	int		size;

	if (!(line = (char*)malloc(sizeof(char) * MAX_SIZE + 1)))
		return (0);
	i = 0;
	while ((size = read(g_fd, &line[i], 1)) == 1)
	{
		g_eof = 0;
		if (i == MAX_SIZE)
		{
			free(line);
			print_error();
			return (0);
		}
		if (line[i] == '\n')
		{
			g_info.width = i;
			line[i] = 0;
			break ;
		}
		i++;
	}
	return (line);
}
