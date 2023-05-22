/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:36:20 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/22 15:55:42 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
		free(mtx[i++]);
	free(mtx);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
