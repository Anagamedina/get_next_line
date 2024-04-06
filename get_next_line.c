/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:01:03 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/06 15:35:50 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *initial_buffer(char *storage)
{
        
    char          *buf;
  
    buf = storage;
    if (buf == NULL)
    {
      buf  = (char*)malloc(1);
      if (buf == NULL)
        return(NULL);
      *buf = '\0';
    }
     return (buf);

 }

char *clean_storage(char *storage, char *read_storage, int bytes_read)
{
  char *new_storage;

  new_storage = NULL;
  if (bytes_read > 0)
  {
    new_storage = ft_strjoin(storage, read_storage);
    if (new_storage == NULL)
      return(NULL);
    free(storage);
  }
  if (bytes_read == 0)
    new_storage = storage;
  return(new_storage);
}

char *update_line_from_storage(char **storage, int bytes_read)


    //SUBSTR(cadena; inicio; longitud)
{
  char    *line;
  int     jump;
  char    *tmp;
  size_t  len;

  line = NULL;
  len = ft_strlen(*storage);
  jump = ft_strchr(*storage, "\n");

  if(jump >= 0)
  {
    //subcadena antes del salto de linia
    line = ft_substr(*storage, 0, jump + 1);
    if (line == NULL)
    {
      return NULL;
    }

    //actualizar storage para apuntar antes de saltoo de linia
    tmp = *storage;
    *storage = ft_substr(*storage, jump + 1, len - jump - 1);
    if (*storage == NULL)
    {
      free(line);
      return(NULL);
    }
    free(tmp);
  } else if (bytes_read == 0){
    line = ft_substr(*storage, 0, len);
    if (line == NULL){
      return NULL;
    }
    free(*storage);
    *storage = NULL;
  }
    return(line);
}

char  *line_read(char **storage, int fd)
{
  char  *read_storage;
  char  *line;
  int   bytes;

  read_storage = (char *)malloc(BUFFER_SIZE +1);
  if (read_storage == NULL)
    return (NULL);
  line = NULL;
  while (line == NULL)
  {
    bytes = read(fd, storage_read, BUFFER_SIZE);
    if (bytes < 0)
      return (ft_free(storage_read));
    storage[bytes] = '\0';
    *storage = clean_storage(*storage, tmp_storage)
  }

}












char  *get_next_line(int fd)
{
  static char   *storage;
  char          *line;


  if (fd < 0 || BUFFER_SIZE <= 0)
    return(NULL);
  storage = initial_buffer(storage);
  if (storage == NULL)
    return (NULL);
  // EMPIEZA LEER LINIAS
  line = line_read(&storage, fd);
  if (line == NULL)
    storage =  ft_free(storage);
  if (line != NULL && ft_strlen(line) == 0)
    line =  ft_free(line);
  return(line);

}

int	main(void)
{
  int		fd;
  char	    *line;
  int		count;

  fd = open("test01.txt", O_RDONLY);
  if (fd < 0)
	return (0);
  count = 0;
  while (line)
  {
	line = get_next_line(fd);
	printf("LINE [%d] - %s", count, line);
	count++;
	free(line);
  }
  close(fd);
  return (0);

}
