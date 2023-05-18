/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/09 13:26:50 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_read(int fd, char *s)
{
	char	*b;
	int		x;

	x = 1;
	while (x != 0)
	{
		b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!b)
			return (NULL);
		x = (int)read(fd, b, BUFFER_SIZE);
		if (x == -1)
			return (ft_free(s, b));
		if (x == 0)
		{
			free (b);
			break ;
		}
		b[x] = '\0';
		s = ft_fill_s(s, b);
		if (!s)
			return (NULL);
		if (check_newline(s, 0) == 1)
			break ;
	}
	return (s);
}

int	s_line(char *s, char **line)
{
	int	x;

	*line = ft_newline(s, line);
	if (!*line)
		return (1);
	x = 0;
	while (s[x])
	{
		line[0][x] = s[x];
		if (s[x] == '\n')
		{
			x++;
			break ;
		}
		x++;
	}
	line[0][x] = '\0';
	return (0);
}

int	ft_clean2(char **s, char *aux, int x)
{
	int	y;
	int	flag;

	y = 0;
	x++;
	while (s[0][x])
	{
		aux[y++] = s[0][x++];
		flag = 1;
	}
	if (flag == 1)
	{
		aux[y] = '\0';
		free(s[0]);
		s[0] = ft_copy(s[0], aux);
	}
	else
	{
		free(aux);
		free(s[0]);
		s[0] = NULL;
	}
	if (!s)
		free(s);
	return (!s);
}

int	ft_clean(char **s)
{
	char	*aux;
	int		x;

	x = 0;
	while (s[0][x] != '\n' && s[0][x])
		x++;
	if (s[0][x] == '\0')
	{
		free(*s);
		*s = NULL;
		return (0);
	}
	else
		aux = malloc(sizeof(char) * (check_newline(s[0], 1) - x) + 1);
	if (!aux)
		return (1);
	if (ft_clean2(s, aux, x) == 1)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			x;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (s);
		s = NULL;
		return (NULL);
	}
	s = ft_read(fd, s);
	if (!s)
		return (ft_free(s, NULL));
	x = s_line(s, &line);
	if (x == 1)
		return (ft_free(line, NULL));
	x = ft_clean(&s);
	if (x == 1)
		return (ft_free (line, NULL));
	return (line);
}
