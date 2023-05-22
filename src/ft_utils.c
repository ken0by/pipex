/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:44:20 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/22 16:31:31 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_error("Path not found\n");
	exit (1);
}

static char	*ft_path(char *c, char **env)
{
	int		i;
	int		p;
	char	**all_path;
	char	*slash;
	char	*path;

	if (access(c, X_OK) == 0)
		return (c);
	p = ft_find_path(env);
	all_path = ft_split(env[p] + 5, ':');
	i = -1;
	while (all_path[i++])
	{
		slash = ft_strjoin("/", c);
		path = ft_strjoin(all_path[i], slash);
		free (slash);
		if (access(path, X_OK) == 0)
		{
			free_mtx(all_path);
			return (path);
		}
		free (path);
	}
	free_mtx(all_path);
	return (0);
}

void	ft_command(char *command, char **env)
{
	char	**c;
	char	*path;

	c = ft_split(command, ' ');
	path = ft_path(c[0], env);
	if (!path)
	{
		ft_putstr_fd("Invalid command\n", 2);
		exit (127);
	}
	if (execve(path, c, env) == -1)
		exit (1);
}

int	ft_open(char *file, int x)
{
	int	fd;

	if (x == 0)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (x == 1)
	{
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (fd < 0)
		ft_error("Failed to open file\n");
	return (fd);
}
