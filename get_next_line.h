/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansoor <mansoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:08:23 by mansoor           #+#    #+#             */
/*   Updated: 2024/01/28 22:14:26 by mansoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 7
# endif

char    *read_file(char *s, int fd)
char    *getting_line(char *str)
char    *get_next_line(int fd)
size_t	ft_strlen(const char *s)
char	*ft_strjoin(char const *s1, char const *s2)
char	*ft_strchr(const char *s, int c)
int     checking_new_lines(char *str)
char	*remain(char	*full_buff)

#endif