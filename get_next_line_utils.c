/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansoor <mansoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:58:36 by mansoor           #+#    #+#             */
/*   Updated: 2024/01/28 22:13:18 by mansoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c || c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

int checking_new_lines(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return(1);
        i++;
    }
    return (0);
}

char	*remain(char	*full_buff)
{
	int		i;
	int		x;
	char	*new_buff;
	
	i = 0;
	while (full_buff[i] != '\0' && full_buff[i] != '\n')
		i++;
	if (full_buff[i] == '\n')
	{
		free(full_buff);
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(full_buff) - i + 1));
	if (!new_buff)
		return (NULL);
	i++;
	if(!full_buff[i])
		return (free(new_buff), free(full_buff), NULL);
	x = 0;
	while (full_buff[i] != '\0')
	{
		new_buff[x] = full_buff[i];
		x++;
		i++;
	}
	new_buff[x] = '\0';
	free(full_buff);
	return (new_buff);
}
