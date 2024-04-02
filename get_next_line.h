/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:38:41 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/02 17:29:11 by anamedin         ###   ########.fr       */
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

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char  *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *s, int c);
char  *ft_free(char **str);

#endif
