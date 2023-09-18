/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:10:22 by rofuente          #+#    #+#             */
/*   Updated: 2023/09/18 16:33:17 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static void	ft_first(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	if (fd < 0)
		ft_perror("pipe", STDERR_FILENO);
	pid = fork();
	if (pid < 0)
		ft_perror("fork", STDERR_FILENO);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_command(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, 0, 0);
	}
	close(fd[0]);
	close(fd[1]);
}

static void	loop(int *fd, char *line, char *end)
{
	while (line)
	{
		close(fd[0]);
		if ((ft_strncmp(line, end, ft_strlen(end)) == 0) && (ft_strlen(line) == ft_strlen(end) + 1))
			exit(EXIT_SUCCESS);
		write(1, "pipe heredoc> ", 14);
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

static void	here_doc(char *end)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	pipe(fd);
	if (fd < 0)
		ft_perror("pipe", STDERR_FILENO);
	pid = fork();
	if (pid < 0)
		ft_perror("fork", STDERR_FILENO);
	if (pid == 0)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(STDIN_FILENO);
		loop(fd, line, end);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
	}
}

static void	pipex(int argc, char **argv, char **env)
{
	int	file;
	int	file1;
	int	i;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 2;
		file1 = ft_open(argv[argc - 1], HERE_DOC);
		here_doc(argv[2]);
	}
	else
	{
		i = 1;
		file = ft_open(argv[1], INFILE);
		file1 = ft_open(argv[argc - 1], OUTFILE);
		dup2(file, STDOUT_FILENO);
		close(file);
	}
	while (++i < (argc - 2))
		ft_first(argv[i], env);
	dup2(file1, STDOUT_FILENO);
	close(file1);
	ft_command(argv[argc - 2], env);
}

int	main(int argc, char **argv, char **env)
{
	if (argc >= 5)
		pipex(argc, argv, env);
	else
		ft_error("Invalid", " arguments\n", STDERR_FILENO);
}
