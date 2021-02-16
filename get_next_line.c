/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:37:07 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/15 17:11:00 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*ft_staticclean(char **ptr)
{
	char	*ret;

	if (!ptr || !ptr[0])
		return (NULL);
	ret = ft_substr(*ptr, (ft_fnext(*ptr) + 1), ft_strlen(*ptr));
	free(*ptr);
	*ptr = NULL;
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	char		data[BUFFER_SIZE + 1];
	static char	*ptr;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, data, 0) < 0)
		return (-1);
	ret = read(fd, data, BUFFER_SIZE);
	data[ret] = '\0';
	ptr = ft_gnl_strjoin(&ptr, data);
	while ((ft_fnext(ptr) < 0) && ((ret = read(fd, data, BUFFER_SIZE)) > 0))
	{
		data[ret] = '\0';
		ptr = ft_gnl_strjoin(&ptr, data);
	}
	if ((ft_fnext(ptr)) >= 0)
	{
		*line = ft_substr(ptr, 0, ft_fnext(ptr));
		ptr = ft_staticclean(&ptr);
		return (1);
	}
	*line = ft_strdup(ptr);
	free(ptr);
	ptr = NULL;
	return (0);
}
