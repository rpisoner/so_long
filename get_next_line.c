/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:41:41 by rpisoner          #+#    #+#             */
/*   Updated: 2023/12/26 17:47:27 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char	*stuff;
	char	*tmp;
	ssize_t	o_read;

	tmp = NULL;
	o_read = 1;
	stuff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stuff)
		return (NULL);
	stuff[BUFFER_SIZE] = '\0';
	while (o_read > 0 && !ft_strchr(buffer, '\n'))
	{
		o_read = read(fd, stuff, BUFFER_SIZE);
		if (o_read < 0)
			break ;
		stuff[o_read] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, stuff);
		free(tmp);
	}
	free(stuff);
	stuff = NULL;
	if (o_read < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*is_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		line = ft_substr(buffer, 0, i + 1);
	else if (buffer[i] == '\0')
		line = ft_substr(buffer, 0, ft_strlen(buffer));
	if (!line || line[0] == '\0')
	{
		if (line[0] == '\0')
			free(line);
		return (NULL);
	}
	return (line);
}

char	*leftovers(char *buffer)
{
	char	*remainings;
	size_t	i;
	size_t	aux;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	aux = i;
	while (buffer[i])
		i++;
	if (i - aux <= 0)
	{
		free (buffer);
		return (NULL);
	}
	remainings = ft_substr(buffer, aux + 1, i - aux);
	free(buffer);
	if (!remainings)
		return (NULL);
	return (remainings);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = is_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = leftovers(buffer);
	return (line);
}

// void	leaks(void)
// {
// 	system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int		file;
// 	char	*next;

// 	file = open("pruebas.txt", O_RDWR);
// 	while ((next = get_next_line(file)) != NULL)
// 	{
// 		printf("%s", next);
// 		free(next);
// 	}
// 	atexit(leaks);
// 	close(file);
// 	return (0);
// }
