/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:44:20 by rofuente          #+#    #+#             */
/*   Updated: 2023/08/31 12:59:53 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

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
	ft_putstr_fd("Path not found\n", STDERR_FILENO);
	exit (127);
	return (i);
}

static char	*ft_path(char *c, char **env)
{
	int		i;
	char	**all_path;
	char	*slash;
	char	*path;

	i = ft_find_path(env);
	all_path = ft_split(env[i] + 5, ':');
	i = -1;
	while (all_path[++i])
	{
		slash = ft_strjoin("/", c);
		path = ft_strjoin(all_path[i], slash);
		free (slash);
		if (access(path, F_OK & R_OK) == 0)
		{
			free_mtx(all_path);
			return (path);
		}
		free (path);
	}
	free_mtx(all_path);
	return (NULL);
}

static int	check_command(char *command)
{
	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, X_OK) == 0)
			return (1);
		else
			ft_error_perror(command, "", 127);
	}
	return (0);
}

void	ft_command(char *command, char **env)
{
	char	**c;
	char	*path;

	c = ft_split(command, ' ');
	if (!c || !c[0])
		ft_error(command, ": Command not found\n", 127);
	if (check_command(c[0]) == 1)
		path = c[0];
	else
	{
		path = ft_path(c[0], env);
		if (!path)
			ft_error(command, ": Command not found\n", 127);
	}
	if (execve(path, c, env) == -1)
		ft_perror("", STDERR_FILENO);
}

int	ft_open(char *file, int x)
{
	int	fd;

	if (x == 0)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_perror(file, 1);
	}
	if (x == 1)
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_perror(file, 1);
	}
	if (fd < 0)
		ft_perror(file, 1);
	return (fd);
}
