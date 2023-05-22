/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:08:32 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/22 15:58:55 by rofuente         ###   ########.fr       */
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
/* FT_UTILS.C */
int		ft_open(char *file, int x);
void	ft_command(char *command, char **env);

/* FT_ERROR.C */
void	ft_error(char *s);
void	free_mtx(char **mtx);

#endif
