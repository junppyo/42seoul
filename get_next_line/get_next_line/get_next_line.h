/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:10:33 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/04 14:10:35 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char *s2, int len);
size_t		ft_strlen(char *s);
int			chk_str(char *s);
char		*ft_strtrim(char *s);
char		*make_save(char *s);
char		*ft_strndup(char *src, int len);
char		*make_str(char *ret, char *buf, int len);
#endif
