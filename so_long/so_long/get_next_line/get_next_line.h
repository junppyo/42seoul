/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:10:33 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 14:43:00 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*get_next_line(int fd);
size_t		ft_strlcpy_(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_(char *s1, char *s2, int len);
size_t		ft_strlen_(char *s);
int			chk_str(char *s);
char		*ft_strtrim_(char *s);
char		*make_save(char *s);
char		*ft_strndup(char *src, int len);
char		*make_str(char *ret, char *buf, int len);
#endif
