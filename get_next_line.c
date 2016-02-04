/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/02/04 17:39:34 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	get_line(char *str, char **line)
{
	int carac;
	char *my_line;

	carac = 0;
	while (str[carac] != '\n' && str[carac] != '\0' && carac <= BUFF_SIZE)
		carac++;
	my_line = ft_strsub(str, 0, carac);
	*line = ft_strjoin(*line, my_line);
	free(my_line);

	return(carac);
}

int get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		retu;
	int ret;
//	static char	*line_read;

	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	//ft_putendl("debug :");
	
	//ft_putendl(buf);
	retu = get_line(buf, line);
	if (retu == ret)
		get_next_line(fd, line);
	else
		free(*line);
//	line_read = ft_strdup(*line);
	
	return (retu);
}
