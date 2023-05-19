/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:22:53 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 20:48:10 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_path(char *c, char **com)
{
	ft_printf("%s\n", c);
	ft_printf("%s\n", com[0]);
	return (NULL);
}

void	ft_command(char *command, char **com)
{
	char	**c;
	char	*path;

	c = ft_split(command, ' ');
	path = ft_path(c[0], com);
	if (!path)
	{
		ft_putstr_fd("Invalid command\n", 2);
		exit (127);
	}
	if (execve(path, c, com) == -1)
		exit (1);
}

int	ft_open(char *file, int c)
{
	int	fd;

	if (c == 0)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (c == 1)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (fd < 0)
		ft_error("Failed to open file\n");
	return (fd);
}
