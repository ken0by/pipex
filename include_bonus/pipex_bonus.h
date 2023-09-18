/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:08:32 by rofuente          #+#    #+#             */
/*   Updated: 2023/09/18 16:27:03 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

/* DEFINICION */
# define INFILE 0
# define OUTFILE 1
# define HERE_DOC 2

/* ---------- FUNCIONES ---------- */
/* FT_UTILS_BONUS.C */
int		ft_open(char *file, int x);
void	ft_command(char *command, char **env);

/* FT_ERROR_BONUS.C */
void	ft_error(char *command, char *s, int n);
void	free_mtx(char **mtx);
void	ft_perror(char *s, int n);
void	ft_error_perror(char *command, char *s, int n);

#endif
