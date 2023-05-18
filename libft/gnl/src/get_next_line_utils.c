/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/05/11 14:40:22 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_free(char *s, char *b)
{
	if (s)
	{
		free (s);
		s = NULL;
	}
	if (b)
		free (b);
	return (s);
}

int	check_newline(char *s, int y)
{
	int	x;

	x = 0;
	if (y == 1)
	{
		while (s[x])
			x++;
		return (x);
	}
	else if (y == 0)
	{
		if (!s)
			return (0);
		while (s[x])
		{
			if (s[x] == '\n')
				return (1);
			x++;
		}
	}
	return (0);
}

char	*ft_fill_s(char *s, char *b)
{
	int		i;
	char	*a;

	a = NULL;
	if (!s)
	{
		a = malloc(sizeof(char) * ft_strlen(b) + 1);
		i = 0;
		while (b[i])
		{
			a[i] = b[i];
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	else
		return (ft_strjoin(s, b));
}

char	*ft_newline(char *s, char **line)
{
	int	x;

	x = 0;
	while (s[x] != '\n' && s[x])
		x++;
	if (x == 1)
		line[0] = malloc(sizeof(char) * (x + 1));
	else
		line[0] = malloc(sizeof(char) * (x + 2));
	if (!line[0])
	{
		free (line[0]);
		return (NULL);
	}
	return (line[0]);
}

char	*ft_copy(char *s, char *aux)
{
	int	x;

	s = malloc(sizeof(char) * (check_newline(aux, 1) + 1));
	if (!s)
	{
		free (s);
		return (NULL);
	}
	x = 0;
	while (aux[x])
	{
		s[x] = aux[x];
		x++;
	}
	s[x] = '\0';
	free (aux);
	return (s);
}
