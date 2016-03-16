/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/03/16 15:15:07 by abureau          ###   ########.fr       */
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
	int fd2 = 0;
	int fd3 = 0;

	if (a)
		i = 20;

	fd = open(b[1], O_RDONLY);
	fd2 = open(b[2], O_RDONLY);
	fd3 = open(b[3], O_RDONLY);
	j = 0;
	line = NULL;
	ft_putstr("DEBUT DU PROGRAMME\n");
//while ((j = get_next_line(fd, &line)) >= 0)
while (i >= 0)
{	
	i--;
	if (i % 3 == 0)
	{
		j = get_next_line(fd, &line);
		if (j == 1)
			ft_putstr("LINE FD : ");ft_putendl(line);
	}
	else if (i % 3 == 1)
	{
		j = get_next_line(fd2, &line);
		if (j == 1)
			ft_putstr("LINE FD2 : ");ft_putendl(line);
	}
	else
	{
		j = get_next_line(fd3, &line);
		if (j == 1)
			ft_putstr("LINE FD3 : ");ft_putendl(line);
	}
	if (j == 1)
		ft_strdel(&line);
}
/*
		else if (j == 0)
		{
			ft_putendl("main result : --> File ended");
		}
		else if (j == -1)
			ft_putendl("mian result : --> Error");
		else
			ft_putendl("main result : --> wrong return");
*/




	return (0);
}
