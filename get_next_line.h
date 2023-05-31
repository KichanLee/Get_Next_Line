/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:59:36 by kichan            #+#    #+#             */
/*   Updated: 2023/04/17 17:35:40 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen_d(const char *ch);
char	*get_next_line(int fd);
int		ft_errorcheck(int fd, char **where);
#endif