/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-ketb <mal-ketb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:58:36 by mansoor           #+#    #+#             */
/*   Updated: 2024/02/11 14:14:46 by mal-ketb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_str_init(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strj;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_str_init();
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	strj = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strj)
		return (0);
	while (s1[i])
	{
		strj[i] = s1[i];
		i++;
	}
	while (s2[j])
		strj[i++] = s2[j++];
	strj[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (strj);
}

char	*remain(char *full_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (full_buffer[i] != '\0' && full_buffer[i] != '\n')
		i++;
	if (full_buffer[i] == '\0')
	{
		free(full_buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(full_buffer) - i + 1));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	if (!full_buffer[i])
		return (free(new_buffer), free(full_buffer), NULL);
	j = 0;
	while (full_buffer[i] != '\0')
		new_buffer[j++] = full_buffer[i++];
	new_buffer[j] = '\0';
	free(full_buffer);
	return (new_buffer);
}
