/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/16 15:36:59 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static size_t	ft_strlenn(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int		parsing(char **tmpbuff, char **line, int const fd)
{
	*line = ft_strdup(ft_strsub(tmpbuff[fd], 0, ft_strlenn(tmpbuff[fd])));
	ft_strcpy(tmpbuff[fd], &tmpbuff[fd][ft_strlenn(tmpbuff[fd]) + 1]);
	return (1);
}

static void		mallocarray(char ***buff, int *ret)
{
	int		index;
	char	**tmpbuff;

	*ret = -42;
	index = 0;
	tmpbuff = (char**)malloc(sizeof(char*) * FDMAX);
	if (tmpbuff)
	{
		while (index < FDMAX)
		{
			tmpbuff[index] = (char*)malloc(sizeof(char));
			if (!tmpbuff[index])
				while (index <= 0)
				{
					free(tmpbuff[index]);
					index--;
					*ret = -1;
				}
			index++;
		}
		*buff = tmpbuff;
	}
	else
		*ret = -1;
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			retout[2];
	static char	**tmpb;

	(!tmpb) ? mallocarray(&tmpb, &retout[0]) : (retout[0] = -42);
	if (fd < 0 || fd > 255 || retout[0] == -1 || !line || fd > FDMAX)
		return (-1);
	if (ft_strlen(&tmpb[fd][ft_strlenn(tmpb[fd])]) == 0)
	{
		if ((retout[0] = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[retout[0]] = '\0';
		tmpb[fd] = (sizeof(tmpb) >= ((sizeof(char) * ft_strlen(tmpb[fd])) +
		sizeof(buf)) ? ft_strcat(tmpb[fd], buf) : ft_strjoin(tmpb[fd], buf));
		retout[1] = 2;
	}
	else
		retout[1] = parsing(tmpb, line, fd);
	if (retout[0] == 0 && (ft_strlen(&tmpb[fd][ft_strlenn(tmpb[fd])]) == 0))
	{
		retout[1] = (ft_strlen(tmpb[fd]) > 0) ? 1 : 0;
		parsing(tmpb, line, fd);
		if (tmpb[fd])
			ft_strclr(tmpb[fd]);
	}
	return ((retout[1] == 2) ? get_next_line(fd, line) : retout[1]);
}
