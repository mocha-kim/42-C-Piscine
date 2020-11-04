/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:35 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/05 00:53:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			g_fd;
int			g_eof;
t_map_info	g_info;

int		main(int argc, char **argv)
{
	int		i;
	char	**map;

	if (argc == 1)
	{
		g_fd = 0;
		map = ft_stdread();
		if (is_valid_map(map))
			progress_map(map);
		else
			print_error();
	}
	else if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			map = ft_open(argv[i]);
			if (g_fd < 0 || !is_valid_map(map))
				print_error();
			else
				progress_map(map);
		}
	}
	return (0);
}
