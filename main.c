/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/03/15 13:02:19 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(int a, char **b)
{
	char *line;
	int fd = 0;
	int i = -1;
	int j = 0;

	if (a)
		i = 0;

	fd = open(b[1], O_RDONLY);
	j = 0;
	line = NULL;
while ((j = get_next_line(fd, &line)) >= 0)
	{
		if (j == 1)
			ft_putendl(line);
		else if (j == 0)
		{
			ft_putendl("File ended");
			break;
		}
		else if (j == -1)
			ft_putendl("Error");
		else
			ft_putendl("wrong return");
		if (j == 1)
			ft_strdel(&line);
	}


	return (0);
}
