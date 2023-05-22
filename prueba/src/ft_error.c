/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:46:51 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 20:31:59 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

void	ft_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
