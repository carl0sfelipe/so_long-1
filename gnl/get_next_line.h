/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:59:24 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 18:08:12 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *memory, char const *tmp);
char	*ft_strchr( const char *s, int c);
char	*ft_new_string(char *memory);
char	*ft_put_line(char *memory);
char	*ft_read_string(int fd, char *memory);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif