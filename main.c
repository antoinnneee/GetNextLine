/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/03/10 15:56:57 by abureau          ###   ########.fr       */
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
int value;
int j;
		fd = open(b[1], O_RDONLY);
		fd2 = open(b[2], O_RDONLY);
	while (1)
	{
	if (a)
		;
//	int i = -1;
//	int j = 0;
	//ft_putnbrnl(ft_atoi(b[2]));
	j = 0;
		scanf("%d", &value);

		if (value == 1)
			j = get_next_line(fd, &line);
		else if (value == 2)
			j = get_next_line(fd2, &line);
		ft_putstr("get_next_line result : ");ft_putendl(line);
		ft_putstr("get_next_line return : ");ft_putnbrnl(j);
	}
	get_next_line(fd, &line);
		ft_putstr("get_next_line result : ");ft_putendl(line);
	get_next_line(fd2, &line);
		ft_putstr("get_next_line resulti (fd2) : ");ft_putendl(line);
	get_next_line(fd, &line);
		ft_putstr("get_next_line result : ");ft_putendl(line);
	get_next_line(fd2, &line);
		ft_putstr("get_next_line result (fd2) : ");ft_putendl(line);
	get_next_line(fd, &line);
		ft_putstr("get_next_line result : ");ft_putendl(line);
	get_next_line(fd2, &line);
		ft_putstr("get_next_line resulti (fd2) : ");ft_putendl(line);
 /* 
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
*/
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
