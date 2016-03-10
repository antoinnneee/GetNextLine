/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/03/10 18:11:47 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(int a, char **b)
{
	
char *line;
int fd;
int fd2;
if (a)
	;
fd = open(b[1], O_RDONLY);
		fd2 = open(b[2], O_RDONLY);
	int i = -1;
	int j = 0;
	j = 0;
	line = NULL;
	for (i = 0; i < 13; i++)
	{
		j = get_next_line(fd, &line);
		if (j == 1)
			ft_putendl(line);
		else if (j == 0)
		{
			ft_putendl("File ended");
		}
		else if (j == -1)
			ft_putendl("Error");
		else
			ft_putendl("wrong return");
		if (j == 1)
			ft_strdel(&line);
	}
	/*
	line = NULL;
	if(a == 3)
      	{
		while(j  < ft_atoi(b[2]))
		{
			i = get_next_line(fd, &line);
			ft_putstr("Line N_");ft_putnbr(j + 1);ft_putstr(" : ");ft_putendl(line);
			i++;
			j++;
		}
	}*/
	return (0);
}
