/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:31 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 20:43:50 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ---------- LIBRERIAS ---------- */
# include "../libft/include/libft.h"
# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/gnl/include/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/wait.h>

/* ---------- FUNCIONES ---------- */
/* FT_ERROR.C */
void	ft_error(char *s);
void	ft_free(char **s);

/* UTILS.C */
int	ft_open(char *file, int c);
void	ft_command(char *command, char **com);

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"
#endif
