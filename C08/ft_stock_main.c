#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

int		main(void)
{
	int			i;
	int			ac;
	char		**av;
	t_stock_str	*stock;

	ac = 10;
	av = (char **)malloc(sizeof(char *) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		av[i] = (char *)malloc(sizeof(char) * 3);
		av[i][0] = (char)(i + 'a');
		av[i][1] = (char)(i + 'b');
		av[i][2] = 0;
		i++;
	}
	stock = ft_strs_to_tab(ac, av);
	ft_show_tab(stock);
	return (0);
}
