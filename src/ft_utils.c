/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:44:20 by rofuente          #+#    #+#             */
/*   Updated: 2023/06/21 12:41:01 by rofuente         ###   ########.fr       */
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
	return (i);
}

static char	*ft_path(char *c, char **env)
{
	int		i;
	char	**all_path;
	char	*slash;
	char	*path;

	if (access(c, X_OK) == 0)
		return (c);
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

void	ft_command(char *command, char **env)
{
	char	**c;
	char	*path;

	c = ft_split(command, ' ');
	if (!c || !c[0])
		ft_error("Command not found\n");
	path = ft_path(c[0], env);
	if (!path)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": Command not found\n", 2);
		exit (EXIT_FAILURE);
	}
	if (execve(path, c, env) == -1)
		ft_perror("");
}

int	ft_open(char *file, int x)
{
	int	fd;

	if (x == 0)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_perror(file);
	}
	if (x == 1)
	{
		fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_perror(file);
	}
	if (fd < 0)
		ft_perror(file);
	return (fd);
}
