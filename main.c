/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:18:58 by rponsonn          #+#    #+#             */
/*   Updated: 2021/02/15 17:12:36 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
/*	int		fd2;
	int		fd3;
	int		fd4;*/
	int		ret;
	char	*ptr;
	char	**db;

	db = &ptr;
	ret = 1;
	fd1 = open("test1.txt", O_RDONLY);
/*	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);*/
	while (ret > 0)
	{
		ret = get_next_line(fd1, db);
		printf("Return value is %d\n%s\n", ret, ptr);
		free(ptr);
	}

	return (0);
}
