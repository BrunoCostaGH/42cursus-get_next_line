/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:55:26 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/23 13:19:55 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, int n)
{
	unsigned char	*ps;

	ps = s;
	while (n--)
		*ps++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;

	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, nmemb * size);
	return (result);
}

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
		s1 = 0;
	}
	while (*s2 && len--)
		str[i++] = *s2++;
	return (str);
}

static int	char_count(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str != c && *str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_split(char const *s, char c)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_calloc(char_count(s, c) + 2, sizeof(char));
	if (!result)
		return (0);
	while ((*s) != c && *s)
		result[i++] = *s++;
	if (*s)
		result[i] = c;
	return (result);
}
