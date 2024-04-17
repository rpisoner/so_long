/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:21:57 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/17 20:11:28 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	char_error(void)
{
	write(2, "Error\n", 6);
	write(2, "Existe un carácter no válido en el mapa\n", 42);
	exit(1);
}

void	not_ber_file(void)
{
	write(2, "Error\n", 6);
	write(2, "El archivo no es de tipo .ber\n", 30);
	exit(1);
}

void	not_enough_coins(void)
{
	write(2, "Error\n", 6);
	write(2, "No hay suficientes monedas en el mapa\n", 38);
	exit(1);
}

void	player_error(void)
{
	write(2, "Error\n", 6);
	write(2, "El número de jugadores en el mapa es incorrecto\n", 49);
	exit(1);
}

void	not_sourrounded_by_walls(void)
{
	write(2, "Error\n", 6);
	write(2, "El mapa no está rodeado de muros\n", 34);
	exit(1);
}
