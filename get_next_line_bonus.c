/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:28:35 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/11 16:45:10 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*clean_storage(char *storage, char *read_storage, int bytes_read)
{
	char	*new_storage;

	new_storage = NULL;
	if (bytes_read > 0)
	{
		new_storage = ft_strjoin(storage, read_storage);
		if (new_storage == NULL)
			return (NULL);
		ft_free(storage);
	}
	if (bytes_read == 0)
		new_storage = storage;
	return (new_storage);
}

char	*initial_buffer(char *storage)
{
	char	*buf;

	buf = storage;
	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char));
		if (buf == NULL)
			return (NULL);
		*buf = '\0';
	}
	return (buf);
}

static char	*update_line_from_storage(char **storage, int bytes_read)
{
	char	*line;
	int		jump;
	char	*tmp;
	size_t	len;

	line = NULL;
	len = ft_strlen(*storage);
	jump = ft_strchr(*storage, '\n');
	if (jump >= 0)
	{
		line = ft_substr(*storage, 0, jump + 1);
		tmp = *storage;
		*storage = ft_substr(*storage, jump + 1, len);
		ft_free(tmp);
		return (line);
	}
	if (bytes_read == 0)
	{
		line = ft_substr(*storage, 0, len);
		*storage = ft_free(*storage);
	}
	return (line);
}

static char	*line_read(char **storage, int fd)
{
	char	*read_storage;
	char	*line;
	int		bytes;

	read_storage = (char *)malloc(BUFFER_SIZE + 1);
	if (read_storage == NULL)
		return (NULL);
	line = NULL;
	while (line == NULL)
	{
		bytes = read(fd, read_storage, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(read_storage));
		read_storage[bytes] = '\0';
		*storage = clean_storage(*storage, read_storage, bytes);
		if (*storage == NULL)
			return (ft_free(read_storage));
		line = update_line_from_storage(storage, bytes);
	}
	free(read_storage);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
		|| fd > OPEN_MAX
	{
		return (ft_free(storage[fd]), NULL);
	}
	storage[fd] = initial_buffer(storage[fd]);
	if (storage[fd] == NULL)
		return (NULL);
	line = line_read(&storage[fd], fd);
	if (line == NULL)
		return (ft_free(storage[fd]), NULL);
	if (line != NULL && ft_strlen(line) == 0)
	{
		ft_free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int		fd[2];
	char	*line;
	int		count;
	int		i;

	i = 0;
	fd[0] = open("test01.txt", O_RDONLY);
	fd[1] = open("test02.txt", O_RDONLY);
	if (fd[i] < 0)
	{
		printf("error al abrir el archivo");
		return (1);
	}
	count = 1;
	while ((line = get_next_line(fd[i])) != NULL)
	{
		printf("LINE [%d] - %s", count, line);
		count++;
		free(line);
	}
	close(*fd);
	return (0);
}
