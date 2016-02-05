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
	char *line;
	int fd = open(b[1], O_RDONLY);

	ft_putnbr(a);
	
	ft_putendl("TEST");
	line = NULL;
	if(a == 2)
	{
		while((i = get_next_line(fd, &line)))
		{
			ft_putnbr(i);
		ft_putendl(line);
		i++;
		}
	}
	return (0);
}
