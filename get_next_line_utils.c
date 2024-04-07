/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:58:14 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/07 18:06:19 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
  size_t len;

  len = 0;
  while (str[len] != '\0')
	len++;
   return len;
}

void	ft_free(void *ptr)
{
    free(ptr);
	ptr = NULL;
}

int ft_strchr(char *s, char c)
{
    int index = 0;
    while (s[index] != '\0')
    {
        if (s[index] == c)
            return index;
        index++;
    }
    return (-1);
}

/*int	ft_strchr( char *s, char *c)
{
  int  jump;
  int i;

  jump = 0;
  while(s[jump] != '\0')
  {
    i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == s[jump])
			return (jump);
		i++;
	}
	jump++;
  }
  return(-1);
}*/

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
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
	{
		ft_free(ptr);
		return (NULL);
	}	
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	if (start + len < size)
	size = len;
	else
	{
		if (start > size)
			size = 0;
		else
			size = size - start;
	}
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}	
	ptr[i] = '\0';
	return (ptr);

}

/*char	*ft_strdup(const char *s1)
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
}*/
