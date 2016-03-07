/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/07 19:16:34 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
/*
static int	get_buf(char *str)
{
	int carac;
//	char *my_line;

	carac = 0;
	while (str[carac] != '\n' && str[carac] != '\0' && carac <= BUFF_SIZE)
		carac++;
	
	my_line = ft_strsub(str, 0, carac);
	*line = ft_strjoin(*line, my_line);
	if ((my_line[carac] == '\0') && (carac != BUFF_SIZE))
	{
		free(my_line);
		return(-42);
	}
	
	return(carac);
}
*/
/*
static void readintobuffer(char *str, **line)
{

}
*/
static int ft_strlenn(const char *s)
{
	unsigned int	i;

	i = 0;
	while(s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			state;			/*State*/
	int			ret;			/*nbr of char read*/
	static char *tmpbuff;
	int			out;

	out = 0;
	ret = 0;
	state = 0;
		if (fd < 0)
		{
			return(-1);
		}
		if (tmpbuff)
		{
			tmpbuff = ft_strdup(&tmpbuff[ft_strlenn(tmpbuff) + 1]);
		}
		else
			while ((ret = read(fd, buf, BUFF_SIZE)))
			{
				buf[ret] = '\0';
				tmpbuff = ft_strjoin(tmpbuff, buf);
//				ft_putendl("WHILE LOOP");
//				ft_putendl(buf);
			}
	if (ret > 0 || ft_strlen(tmpbuff) >= 1)
		if (state < ret || (state == 0 && ret == 0))
		{
			free(*line);
			*line = ft_strdup(ft_strsub(tmpbuff, 0, ft_strlenn(tmpbuff)));
		}
	if (ft_strlen(tmpbuff) == 0)
		out = 0;
	else if (ft_strlen(tmpbuff))
		out = 1;
	return (out);
}
