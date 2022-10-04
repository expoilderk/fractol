/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:27:26 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 21:47:03 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*make_line(char *backup, int index)
{
	char	*line;

	if (backup == NULL)
		return (NULL);
	if (backup[0] == '\0')
		return (NULL);
	while (backup[index] != '\n' && backup[index] != '\0')
		index++;
	if (backup[index] == '\n')
		line = malloc(sizeof(char) * (index + 2));
	else
		line = malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (backup[index] != '\n' && backup[index] != '\0')
	{
		line[index] = backup[index];
		index++;
	}
	if (backup[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*cut_line(char *backup)
{
	int		index;
	char	*line;

	index = 0;
	if (backup == NULL)
		return (NULL);
	while (backup[index] != '\n' && backup[index] != '\0')
		index++;
	if (backup[index] == '\0')
	{
		free(backup);
		return (NULL);
	}
	if (backup[index] == '\n')
		index++;
	line = ft_strdup(&backup[index]);
	free(backup);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*read_str;
	static char	*backup[FD_MAX];
	char		*line;
	int			read_size;
	int			index;

	index = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	read_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_str)
		return (NULL);
	while (!ft_strchr(backup[fd], '\n'))
	{
		read_size = read(fd, read_str, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], read_str);
	}
	line = make_line(backup[fd], index);
	backup[fd] = cut_line(backup[fd]);
	free(read_str);
	return (line);
}
