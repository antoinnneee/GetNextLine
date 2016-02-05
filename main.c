/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:15 by abureau           #+#    #+#             */
/*   Updated: 2016/02/04 17:44:00 by abureau          ###   ########.fr       */
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
	int fd = open(b[1], O_RDONLY);

	ft_putnbrnl(a);
	

	line = NULL;
	if(a == 3)
      	{
	ft_putendl("TEST");
	  while(j  < ft_atoi(b[2]))
	    {
	      i = get_next_line(fd, &line);
	      ft_putnbrnl(i);
	      ft_putendl(line);
		i++;
		j++;
		}
	}
	return (0);
}
