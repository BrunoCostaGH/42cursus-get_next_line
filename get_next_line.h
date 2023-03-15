/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <bsilva-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:35:34 by bsilva-c          #+#    #+#             */
/*   Updated: 2023/03/15 19:25:28 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(const char *str);

char	*get_next_line(int fd);
char	*ft_split(char const *s, char c);
char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char *s1, char const *s2, int len);

void	ft_bzero(void *s, int n);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
