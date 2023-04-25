/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmarque <anmarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:45:06 by anmarque          #+#    #+#             */
/*   Updated: 2022/11/08 18:04:58 by anmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_and_save(int fd, char *save_line)
{
	char		*buffer;
	ssize_t		read_bytes;

	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(save_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save_line = ft_strjoin(save_line, buffer);
	}
	free(buffer);
	return (save_line);
}

char	*ft_get_line(char *save_line)
{
	int		i;
	char	*s;

	i = 0;
	if (!save_line[i])
		return (NULL);
	while (save_line[i] && save_line[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	ft_strlcpy(s, save_line, i + 1);
	if (save_line[i] == '\n')
		s[i] = save_line[i];
	s[++i] = '\0';
	return (s);
}

char	*ft_save_next_line(char *save_line)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	if (!save_line[i])
	{
		free(save_line);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(save_line) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (save_line[i])
		s[j++] = save_line[i++];
	s[j] = '\0';
	free(save_line);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_line = ft_read_and_save(fd, save_line);
	if (!save_line)
		return (NULL);
	line = ft_get_line(save_line);
	save_line = ft_save_next_line(save_line);
	return (line);
}
