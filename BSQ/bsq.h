/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:29:55 by sunhkim           #+#    #+#             */
/*   Updated: 2020/11/04 21:03:54 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_map_info
{
	int				width;
	int				height;
	char			empty;
	char			obstacle;
	char			full;
}					t_map_info;

typedef struct		s_location
{
	int				x;
	int				y;
	int				max_size;
}					t_location;

# define MAX_SIZE 512
# define TRUE 1
# define FALSE 0

extern int			g_fd;
extern int			g_eof;
extern t_map_info	g_info;

void				first_line(char *line);
char				**ft_open(char *path);
char				*last_line(void);
char				*ft_fread(void);
char				**ft_stdread(void);

int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *result, char *src);
int					ft_atoi(char *str);
int					is_space(char ch);

void				ft_putchar(char c);
void				print_error(void);
void				print_map(char **map);

int					is_valid_map(char **map);
void				free_map(char **map, int height);

int					find_bsq_at_point(char **map, t_location loc, int cur_max);
t_location			find_bsq(char **map);
void				fill_map(char **map, t_location location);
void				progress_map(char **map);

#endif
