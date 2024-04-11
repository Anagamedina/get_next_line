/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:29:56 by anamedin          #+#    #+#             */
/*   Updated: 2024/04/11 18:14:59 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define OPEN_MAX

# endif

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strchr( char *s, char c);
void		*ft_free(void *ptr);
char		*ft_substr(const char *s, size_t start, size_t len);

#endif