/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:21:25 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/09 20:05:16 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *init_buffer(char *storage)
{
    char    *buf;

    buf = storage;
    if (buf == NULL)
    {
        buf = (char *) malloc(sizeof(char));
        if (buf == NULL)
            return (NULL);
        *buf = '\0';
    }
    return (buf);
}

static char *line_read_storage(int fd, char **storage)
{
    char    *read_storage;
    int     bytes;

    bytes = 1;
    read_storage = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!read_storage)
        return (NULL);
    while (bytes > 0)
    {
        if (ft_strchr(*sotage, '\n'))
            break ; 
        bytes = read(fd, read_storage, BUFFER_SIZE);
            //return (ft_free(read_storage));
        if (bytes == -1)
            return (ft_free(storage, NULL));
        else if (bytes == 0)
            break ; 
        storage[bytes] = '\0';
        *storage = ft_strjoin(*storage, read_storage);
        if (!*(storage))
            return (ft_free(read_storage, NULL));
    }
    return (ft_free(read_storage));
}




/*
 *#include "get_next_line.h"
#include <fcntl.h>

char	*free_buf(char **buf, char *out)
{
	free(*buf);
	*buf = NULL;
	return (out);
}

static char	*read_buffer(int fd, char **stash)
{
	char	*buf;
	int		seen;

	seen = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (seen > 0)
	{
		if (ft_strchr(*stash, '\n'))
			break ;
		seen = read(fd, buf, BUFFER_SIZE);
		if (seen == -1)
			return (free_buf(&buf, NULL));
		else if (seen == 0)
			break ;
		buf[seen] = '\0';
		*stash = ft_strjoin(*stash, buf);
		if (!*(stash))
			return (free_buf(&buf, NULL));
	}
	return (free_buf(&buf, "ok"));
}

char	*get_next_line(int fd)
{
	size_t		i;
	static char	*stash;
	char		*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!read_buffer(fd, &stash))
		return (free_buf(&stash, NULL));
	if (!ft_strlen(stash))
		return (free_buf(&stash, NULL));
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_substr(stash, 0, i + 1, 0);
	if (!line)
		return (NULL);
	stash = ft_substr(stash, i + 1, ft_strlen(stash) - i, 1);
	if (!stash)
		return (NULL);
	return (line);
}
 *
 *
 *
 */
