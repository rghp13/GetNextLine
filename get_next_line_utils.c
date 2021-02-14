/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:39:28 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/14 16:31:06 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr = ft_memcpy(ptr, s1, size + 1);
	return (ptr);
}

char	*ft_gnl_strjoin(char **s1, const char *s2)
{
	int		len;
	char	*ptr;

	if (*s1 == NULL)
		return (ft_strdup(s2));
	len = ft_strlen(*s1) + ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(ptr, *s1, ft_strlen(*s1));
	ft_memcpy(ptr + ft_strlen(*s1), s2, ft_strlen(s2));
	ptr[len] = '\0';
	free(*s1);
	*s1 = NULL;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	rlen;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		if (!(ptr = malloc(sizeof(char) * 1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	rlen = ft_strlen(s + start);
	if (rlen < len)
		len = rlen;
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_memcpy(ptr, s + start, len + 1);
	ptr[len] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*xfr;

	i = 0;
	if (dst == src)
		return (dst);
	ptr = (unsigned char *)dst;
	xfr = (unsigned char *)src;
	while (i < n)
	{
		*ptr++ = *xfr++;
		i++;
	}
	return (dst);
}
