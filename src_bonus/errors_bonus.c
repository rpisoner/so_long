/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:01 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 19:47:46 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static void	is_ber(char *file)
{
	size_t	i;

	i = 0;
	while (file[i])
		i++;
	i--;
	if (!file[i] || file[i] != 'r')
		not_ber_file();
	i--;
	if (!file[i] || file[i] != 'e')
		not_ber_file();
	i--;
	if (!file[i] || file[i] != 'b')
		not_ber_file();
	i--;
	if (!file[i] || file[i] != '.')
		not_ber_file();
}

static void	argc_not_two(int argc)
{
	if (argc != 2)
		not_valid_args();
}

void	errors(char *file, int argc)
{
	argc_not_two(argc);
	is_ber(file);
}
