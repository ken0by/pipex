/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:10:22 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/22 13:17:41 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_first(int *fd, char **argv, char **env)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		file = ft_open(argv[1], 0);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(file, STDIN_FILENO);
		close(file);
		ft_command(argv[2], env);
	}
}

static void	ft_last(int *fd, char **argv, char **env)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		file = ft_open(argv[4], 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(file, STDOUT_FILENO);
		close(file);
		ft_command(argv[3], env);
	}
}

void	pipex(char **argv, char **env)
{
	int	fd[2];
	int	status;

	pipe(fd);
	if (fd < 0)
		exit(EXIT_FAILURE);
	ft_first(fd, argv, env);
	ft_last(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		pipex(argv, env);
	else
		ft_error("Invalid arguments\n");
}
