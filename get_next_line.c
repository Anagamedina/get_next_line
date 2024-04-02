/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:01:03 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/02 21:18:46 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char buf[BUFFER_SIZE + 1];
    static char *storage = NULL;
    int bytes_was_read;
    char *ptr;

    if (storage == NULL)
        storage = ft_strdup("");

    line = ft_strdup(""); 
    if (!line)
        return NULL;

    // Concatenar el contenido no procesado del storage al principio de la línea

    line = ft_strjoin(line, storage);
    ft_free(&storage);  

    while ((bytes_was_read = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[bytes_was_read] = '\0';
        if ((ptr = ft_strchr(buf, '\n')))
        {
            *ptr = '\0';
            storage = ft_strdup(ptr + 1); // Actualizar storage 
            line = ft_strjoin(line, buf);
            return line;  
        }
        line = ft_strjoin(line, buf);
    }

    if (bytes_was_read == 0)
    {
        if (ft_strlen(storage) > 0)
        {
            line = ft_strjoin(line, storage); // Concatenar el contenido restante de storage
            ft_free(&storage);
            return line;
        }
        ft_free(&storage); 
        ft_free(&line); 
        return NULL;
    }

    ft_free(&line); // Liberar line si hubo un error de lectura
    return NULL;
}

   

    
int main()
{
  int fd;
  char  *line;
    
  fd = open("test01.txt", O_RDONLY);
  if (fd == -1) {
    perror("Error al abrir el archivo");
    return 1;
  }
  while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    if (line == NULL)
    {
        printf("Fnal del archivo o hay un error.\n");
    }

    close(fd);

    return 0;
}

/*int main()
{
    int fd;
    char *line;

    fd = open("test01.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Llamar a get_next_line la primera vez
    line = get_next_line(fd);
    if (line != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    else
    {
        printf("Final del archivo o hay un error.\n");
    }

    // Llamar a get_next_line la segunda vez
    line = get_next_line(fd);
    if (line != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    else
    {
        printf("Final del archivo o hay un error.\n");
    }

    close(fd);

    return 0;
}*/
