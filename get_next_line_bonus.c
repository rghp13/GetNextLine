/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:37:07 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/15 16:13:20 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_fnext(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_staticclean(char **ptr, int fd)
{
	char	*ret;

	if (!ptr || !ptr[fd])
		return (NULL);
	ret = ft_substr(ptr[fd], (ft_fnext(ptr[fd]) + 1), ft_strlen(ptr[fd]));
	free(ptr[fd]);
	ptr[fd] = NULL;
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	char		data[BUFFER_SIZE + 1];
	static char	*ptr[FDLIMIT];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, data, 0) < 0)
		return (-1);
	ret = read(fd, data, BUFFER_SIZE);
	data[ret] = '\0';
	ptr[fd] = ft_gnl_strjoin(ptr, data, fd);
	while ((ft_fnext(ptr[fd]) < 0) && ((ret = read(fd, data, BUFFER_SIZE)) > 0))
	{
		data[ret] = '\0';
		ptr[fd] = ft_gnl_strjoin(ptr, data, fd);
	}
	if ((ft_fnext(ptr[fd])) >= 0)
	{
		*line = ft_substr(ptr[fd], 0, ft_fnext(ptr[fd]));
		ptr[fd] = ft_staticclean(ptr, fd);
		return (1);
	}
	*line = ft_strdup(ptr[fd]);
	free(ptr[fd]);
	ptr[fd] = NULL;
	return (0);
}
