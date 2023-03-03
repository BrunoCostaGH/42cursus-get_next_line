/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:35:34 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/23 14:31:04 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
