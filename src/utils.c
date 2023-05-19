/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:22:53 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/19 14:31:40 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_open(char *file, int c)
{
	int	fd;

	if (c == I)
	{
		fd = open(file, O_RDONLY, 0644);
		if (access(file, R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (c == O)
	{
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (access(file, W_OK | R_OK) < 0)
			ft_error("Failed to open file\n");
	}
	if (fd < 0)
		ft_error("Failed to open file\n");
}
