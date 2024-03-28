/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:52:48 by rpisoner          #+#    #+#             */
/*   Updated: 2024/03/28 13:15:09 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (n == 0 || d == s)
		return (dst);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*mem;
	int		length;

	length = ft_strlen(s);
	mem = malloc(length + 1);
	if (mem == 0)
		return (mem);
	ft_memcpy(mem, s, length);
	mem[length] = '\0';
	return (mem);
}
