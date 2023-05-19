/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:15 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 20:44:54 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_first(int *fd, char **argv, char **com)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		exit (EXIT_FAILURE);
	if (pid == 0)
	{
		file = ft_open(argv[1], 0);
		close (fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close (fd[1]);
		dup2(file, STDIN_FILENO);
		close (file);
		ft_command (argv[2], com);
	}
}

static void	ft_last(int *fd, char **argv, char **com)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		exit (EXIT_FAILURE);
	if (pid == 0)
	{
		file = ft_open(argv[4], 1);
		close (fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close (fd[1]);
		dup2(file, STDIN_FILENO);
		close (file);
		ft_command (argv[3], com);
	}
}

static void	pipex(char **argv, char **com)
{
	int	fd[2];
	int	s;

	if (pipe(fd) < 0)
		exit (EXIT_FAILURE);
	ft_first(fd, argv, com);
	ft_last(fd, argv, com);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &s, 0);
	waitpid(-1, &s, 0);
}

int	main(int argc, char **argv, char **com)
{
	if (argc == 5)
		pipex(argv, com);
	else
		ft_error("Invalid arguments\n");
	return (0);
}
