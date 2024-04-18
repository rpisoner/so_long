/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:34 by rpisoner          #+#    #+#             */
/*   Updated: 2024/04/18 17:38:05 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static int	int_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_swap(char *s)
{
	char	swap;
	size_t	i;
	size_t	j;

	if (s[0] == '-')
		i = 1;
	else
		i = 0;
	j = 0;
	while (j < ft_strlen(s) / 2)
	{
		swap = *(s + i);
		*(s + i) = *(s + ft_strlen(s) - j - 1);
		*(s + ft_strlen(s) - j - 1) = swap;
		i++;
		j++;
	}
}

static int	is_min_int(int n, char *num)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		num[i++] = '-';
		num[i++] = '8';
		n /= 10;
		n *= -1;
		while (n != 0)
		{
			num[i++] = (n % 10) + '0';
			n /= 10;
		}
		num[i] = '\0';
		ft_swap(num);
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	i;

	i = 0;
	num = (char *)malloc(int_len(n) + 1);
	if (!num)
		return (0);
	if (n == 0)
		num[i++] = '0';
	if (is_min_int(n, num) == 1)
		return (num);
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	num[i] = '\0';
	ft_swap(num);
	return (num);
}
