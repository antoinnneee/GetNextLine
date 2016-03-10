/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/03/08 15:46:50 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int main(int a, char **b)
{
	int i = -1;
	int j = 0;
	char *line;
int fd;
	//ft_putnbrnl(ft_atoi(b[2]));
	if (a == 2)
		fd = open(b[1], O_RDONLY);
	else
		fd = 0;
  
	line = NULL;
	ft_putendl("Starting For Loop");
	for (i = 0; i < 13; i++)
	{
		j = get_next_line(fd, &line);
		if (j == 1)
			ft_putendl(line);
		else if (j == 0)
			ft_putendl("File ended");
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
