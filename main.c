/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:18:58 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/15 15:09:33 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		ret;
	char	*ptr;
	char	**db;

	db = &ptr;
	ret = 1;
	fd = open("test.txt", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, db);
		printf("%s\n", *db);
		free(db[0]);
		db[0] = NULL;
	}
	close(fd);
	return (0);
}
