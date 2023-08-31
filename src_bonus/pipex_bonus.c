/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:10:22 by rofuente          #+#    #+#             */
/*   Updated: 2023/08/31 12:58:55 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static void	ft_first(int *fd, char *infile, char *cmd, char **env)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		ft_perror("fork", STDERR_FILENO);
	if (pid == 0)
	{
		file = ft_open(infile, 0);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		dup2(file, STDIN_FILENO);
		close(file);
		ft_command(cmd, env);
	}
}

static void	ft_last(int *fd, char *outfile, char *cmd, char **env)
{
	pid_t	pid;
	int		file;

	pid = fork();
	if (pid < 0)
		ft_perror("fork", STDERR_FILENO);
	if (pid == 0)
	{
		file = ft_open(outfile, 1);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		dup2(file, STDOUT_FILENO);
		close(file);
		ft_command(cmd, env);
	}
}

static void	loop(int *fd, int argc, char **argv, char **env)
{
	int	i;
	char	*infile;
	char	*outfile;

	infile = argv[1];
	outfile = argv [argc - 1];
	i = 1;
	while (++i < (argc - 2))
	{
		ft_first(fd, infile, argv[i], env);
		ft_last(fd, outfile, argv[i + 1], env);
	}
}

static void	pipex(int argc, char **argv, char **env)
{
	int	fd[2];
	int	status;

	pipe(fd);
	if (fd < 0)
		ft_perror(NULL, STDERR_FILENO);
	loop(fd, argc, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc > 5)
		pipex(argc, argv, env);
	else
		ft_error("Invalid", " arguments\n", STDERR_FILENO);
}
