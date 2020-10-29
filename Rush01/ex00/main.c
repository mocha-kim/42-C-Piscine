/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunhkim_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:13:11 by sunhkim           #+#    #+#             */
/*   Updated: 2020/10/25 15:28:37 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		validate_params(char *params);
int		progress_box(char *params, int size);

void	print_error(void)
{
	write(1, "Error\n", 6);
}

int		is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		check_size(char *params)
{
	int		i;
	int		count_num;
	int		count_other;

	i = 0;
	count_num = 0;
	count_other = 0;
	while (params[i] != '\0')
	{
		if (is_numeric(params[i]))
			count_num++;
		if (!is_numeric(params[i + 1]))
			count_other++;
		i++;
	}
	if (count_num == count_other)
		return (count_num);
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	int		params_num;
	int		catch_error;

	catch_error = 0;
	if (argc != 2)
		catch_error = 1;
	if (catch_error == 0)
	{
		catch_error = validate_params(argv[1]);
		params_num = check_size(argv[1]);
		if (params_num % 4 != 0 || params_num / 4 != 4 || catch_error == 1)
			catch_error = 1;
		else
			catch_error = progress_box(argv[1], 4);
	}
	if (catch_error)
		print_error();
	return (0);
}
