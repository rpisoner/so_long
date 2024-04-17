/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit_errors2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:47:33 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 20:11:26 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	not_valid_file(void)
{
	write(2, "Error\n", 6);
	write(2, "No existe ese archivo\n", 22);
	exit(1);
}

void	not_valid_args(void)
{
	write(2, "Error\n", 6);
	write(2, "Argumentos no válidos\n", 22);
	exit(1);
}

void	not_playable_map(void)
{
	write(2, "Error\n", 6);
	write(2, "El mapa no se puede completar\n", 30);
	exit(1);
}

void	not_rectangular_map(void)
{
	write(2, "Error\n", 6);
	write(2, "El mapa no es rectangular\n", 26);
	exit(1);
}

void	malloc_error(void)
{
	write(2, "Error\n", 6);
	write(2, "Error al alocar memoria (error de malloc)\n", 42);
	exit(1);
}
