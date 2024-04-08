/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:38:41 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/08 15:46:35 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

char      *get_next_line(int fd);
size_t    ft_strlen(const char *str);
//char  	  *ft_strdup(const char *s1);
char      *ft_strjoin(char *s1, char *s2);
int       ft_strchr( char *s, char c);
void      *ft_free(void *ptr);
char      *update_line_from_storage(char **storage, int bytes_read);
char      *clean_storage(char *storage, char *read_storage, int bytes_read);
char      *initial_buffer(char *storage);
char	  *ft_substr(const char *s, size_t start, size_t len);

#endif
