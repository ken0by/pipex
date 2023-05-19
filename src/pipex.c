/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:51:15 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 14:22:35 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_first(int end, char **argv, char **com)
{
	pid_t	pid;
	int		file;
	char	*command;

	pid = fork();
	if (pid < 0)
		exit (EXIT_FAILURE);
	if (pid == 0)
	{
		file = ft_open(argv[1], I);
		
	}
}

static void	ft_last(int end, char **argv, char **com)
{

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
		ft_error("Invalid arguments");
	return (0);
}
