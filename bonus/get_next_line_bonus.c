/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:20:52 by yeham             #+#    #+#             */
/*   Updated: 2023/04/01 20:55:34 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	gnl_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*line_maker(int fd, char *buf, char *storage)
{
	int	r_size;

	r_size = read(fd, buf, 1);
	while (r_size > 0)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = gnl_strdup(buf);
		else
			storage = gnl_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
		if (gnl_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, 1);
	}
	return (storage);
}

char	*namuji(char *line)
{
	unsigned int		i;
	char				*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = gnl_strdup(line + i + 1);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		buf[1];
	char		*line;
	char		*temp2;
	static char	*storage;

	if (fd < 0)
		return (NULL);
	line = line_maker(fd, buf, storage);
	if (line == NULL)
		return (NULL);
	storage = namuji(line);
	temp2 = gnl_strdup(line);
	free(line);
	line = NULL;
	return (temp2);
}
