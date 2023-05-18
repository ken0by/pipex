/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:41 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/18 11:51:06 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../../include/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ---------- GNL ---------- */
char	*ft_read(int fd, char *s);
int		s_line(char *s, char **line);
int		ft_clean2(char **s, char *aux, int x);
int		ft_clean(char **s);
char	*get_next_line(int fd);

/* ---------- UTILS ---------- */
char	*get_next_line(int fd);
char	*ft_fill_s(char *s, char *b);
char	*ft_newline(char *s, char **line);
char	*ft_copy(char *s, char *aux);
char	*ft_free(char *s, char *b);
int		check_newline(char *s, int y);
#endif
