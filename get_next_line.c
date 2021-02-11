/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:37:07 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/11 17:14:14 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* lseek is not allowed
** Write a function which returns a line read from a file descriptor
** without the /n included
** start by error checking, then in a while loop 
*/

static int	ft_findnext(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char		*ft_cutnext(char *str)
{
	int		limit;
	char	*ptr;

	limit = ft_findnext(str);
	if (!(ptr = malloc(sizeof(char) * (limit + 1))))
		return (NULL);
	
}

int			get_next_line(int fd, char **line)
{
	char		data[BUFFER_SIZE + 1];
	static char	*ptr;
	int			ret;
	int			funcstatus;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, data, 0) < 0)
		return (-1);
	while ((ft_findnext(ptr) < 0) && ((ret = read(fd, data, BUFFER_SIZE) > 0)))
	{
		data[ret] = '\0';
		ft_strjoin(ptr, data);
	}
	if ((ft_findnext(ptr)) >= 0)
	{
		*line = ft_cutnext(ptr);
		funcstatus = ft_staticclean(ptr);
		return (funcstatus);
	}
	return (-1);
}
