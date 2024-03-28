/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:01 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 16:42:31 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	is_ber(char *file)
{
	size_t	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (!file[i] || file[i] != 'r')
		print_error();
	i--;
	if (!file[i] || file[i] != 'e')
		print_error();
	i--;
	if (!file[i] || file[i] != 'b')
		print_error();
	i--;
	if (!file[i] || file[i] != '.')
		print_error();
}

static void	argc_not_two(int argc)
{
	if (argc != 2)
		print_error();
}

void	errors(char *file, int argc)
{
	argc_not_two(argc);
	is_ber(file);
}
