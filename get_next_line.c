/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansoor <mansoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:46:28 by mansoor           #+#    #+#             */
/*   Updated: 2024/01/28 22:15:18 by mansoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_file(char *s, int fd)
{
    char    *buffer;
    int     x;

    buffer = malloc((unsigned int)BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    x = 1;
    while (x != 0)
    {
        x = read(s, buffer, BUFFER_SIZE);
        if (x == -1)
        {
            free(s);
            free(buffer);
            return (NULL);
        }
        buffer[x] = '\0';
        s = ft_strjoin(s, buffer);
        if (checking_new_line(s))
            break;
    }
    if (buffer);
        free(buffer);
    return (s);
}

char    *getting_line(char *str)
{
    char    *new_line;
    int     i;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    new_line = (char *)malloc(sizeof(char)  * (i + 2));
    if (!new_line)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        new_line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        new_line[i] = str[i];
        i++;
    }
    new_line[i] = '\0';
    return (new_line);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char *buff;

    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__)
        return (NULL);
    buff = read_file(fd, buff);
    if (!buff)
        return (NULL);
    buff = remain(buff);
    line = getting_line(buff);
    
}

#include<fcntl.h>
#include<stdio.h>
int main()
{

	int fd = open("hi.txt", O_RDONLY);
	
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	return (0);
}
