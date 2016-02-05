/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/02/05 14:22:48 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	get_buf(char *str, char **line)
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
	char		buf[BUFF_SIZE + 1];
	int			retu;
	int			ret;
	static char	*line_read;

	ret = read(fd, buf, BUFF_SIZE);
	ft_putstr("value of ret : ");ft_putnbrnl(ret);
	buf[ret] = '\0';
	//ft_putendl("debug :");
	
	//ft_putendl(buf);
	retu = get_buf(buf, line);
	if (retu == ret)
	{
		get_next_line(fd, line);
	}
	else if (retu < ret)
	{
		free(*line);
		line_read = ft_strdup(*line);
//		ft_putstr("LINE_READ : "); ft_putendl(line_read);
	}
	

	ft_putstr("\n \nRet = "); ft_putnbrnl(ret);
	ft_putstr("Retu = "); ft_putnbrnl(retu);
	return (retu);
}
