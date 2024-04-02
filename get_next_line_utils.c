/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:58:14 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/02 20:38:24 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
  size_t len;

  len = 0;
  while (str[len])
	len++;
   return len;
}

char  *ft_free(char **str)
{
  free(*str);
  *str = NULL;
  return(NULL);
}

char *ft_strchr(const char *s, int c)
{
  char  ch;
  int i;

  ch = c;
  i = 0;
  while(s[i] != '\0')
  {
    if (s[i] == ch)
      return ((char *)&s[i]);
    i++;
  }
  if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}


char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (ft_free(&s1));
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}

static	size_t	ft_check_size(size_t size_s, size_t len, int start)
{
	size_t	len_new_ptr;

	if (len + start <= size_s)
		len_new_ptr = len;
	else
	{
		if ((size_t)start >= size_s)
			len_new_ptr = 0;
		else
			len_new_ptr = size_s - start;
	}
	return (len_new_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_substr;
	size_t	size_s;
	size_t	i;

	size_s = ft_strlen(s);
	len_substr = ft_check_size(size_s, len, start);
	substr = (char *) malloc(len_substr + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len_substr && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}


char	*ft_strdup(const char *s1)
{
	size_t	size_s1;
	size_t	i;
	char	*duplicate;

	// Verificar si s1 es nulo
	if (!s1)
        return (NULL);

	size_s1 = ft_strlen(s1);
	duplicate = malloc(sizeof(char) * (size_s1 + 1));
	if (!duplicate)
		return (NULL);

	i = 0;
	while (s1[i] != '\0')
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}


/*char  *read_buf(int fd, char*storage)
{
  int   id_read;
  char  *buffer_id;

  id_read = 1;  //indica que leera desde el primer byte del archivo
  buffer_id = malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer_id)
    return(ft_free(&storage));
  buffer_id[0] = '\0'; //esto inicializa buffer como una cadena vacia
  while (id_read > 0 && !ft_strchr(buffer_id, '\n')) //s pueda leer y no \n
  {
    id_read = read(fd, buffer_id, BUFFER_SIZE);
    if (id_read > 0)
    {
      buffer_id[id_read] = '\0';
      storage = ft_strjoin(storage, buffer_id);
    }
  }

  free(buffer_id);
  if (id_read == -1)
    return(ft_free(&storage));
  return(storage);

}*/
