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
	int fd[FDMAX];
	int i = -1;
	int j[FDMAX];
	int k = 0;

	while (k < a - 1)
	{
		fd[k] = open(b[k + 1], O_RDONLY);
		ft_putnbr(fd[k]);
		k++;
	}
	k = 0;
	line = NULL;
while (i > -10)
{
	i--;
	while (k < a - 1)
	{
		j[k] = get_next_line(fd[k], &line);
		if (j[k] == 1)
		{
			ft_putstr("LINE FD");ft_putnbr(k);ft_putstr(" : ");ft_putendl(line);
		}
		else if (j[k] == 0)
		{
			ft_putstr("end of file : ");ft_putnbr(k);ft_putstr("\n");
		}
		else if (j[k] == -1)
		{
			ft_putstr("error file : ");ft_putnbr(k);ft_putstr("\n");
		}
		else
		{
			ft_putstr("bad return file : ");ft_putnbr(k);ft_putstr("\n");
		}
		k++;
	}
	k = 0;
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
