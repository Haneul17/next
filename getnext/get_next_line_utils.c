/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czekai <czekai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:28:25 by czekai            #+#    #+#             */
/*   Updated: 2023/11/28 13:28:37 by czekai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_join_strings(char *joined_str, char *string, char *buffer)
{
	int	l1;
	int	l2;

	l1 = 0;
	l2 = 0;
	while (string[l1] != '\0')
	{
		joined_str[l1] = string[l1];
		l1++;
	}
	while (buffer[l2] != '\0')
	{
		joined_str[l1] = buffer[l2];
		l1++;
		l2++;
	}
	joined_str[l1] = '\0';
	return (joined_str);
}

char	*ft_strjoin(char *string, char *buffer)
{
	char	*joined_str;
	int		len;

	if (string == NULL)
	{
		string = malloc(1);
		if (!string)
			return (NULL);
		string[0] = '\0';
	}
	if (string == NULL || buffer == NULL)
		return (NULL);
	len = ft_strlen(string) + ft_strlen(buffer);
	joined_str = malloc(len + 1);
	if (!joined_str)
		return (free(string), NULL);
	joined_str = ft_join_strings(joined_str, string, buffer);
	free(string);
	return (joined_str);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}
