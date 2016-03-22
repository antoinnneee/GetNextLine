/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/22 18:55:54 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static size_t		strparser(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static int			parsing(char **tmpbuff, char **line, int const fd)
{
	int	lenton;

	lenton = strparser(tmpbuff[fd]);
	*line = ft_strnew(lenton);
	ft_strncpy(*line, tmpbuff[fd], lenton);
	ft_strcpy(tmpbuff[fd], &tmpbuff[fd][lenton + 1]);
	return (1);
}

static void			mallocarray(char ***buff, int *ret)
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

static char			*superjoin(char *tmpbuff, char *readbuff)
{
	char	*res;
	int		i;

	i = ft_strlen(tmpbuff) + BUFF_SIZE;
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	res = ft_strcat(res, tmpbuff);
	res = ft_strcat(res, readbuff);
	if (tmpbuff)
		ft_strdel(&tmpbuff);
	return (res);
}

int					get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			retout[2];
	static char	**tmpb = NULL;

	(!tmpb) ? mallocarray(&tmpb, &retout[0]) : (retout[0] = -42);
	if (fd < 0 || fd > 255 || retout[0] == -1 || !line || fd > FDMAX - 1)
		return (-1);
	if (ft_strlen(&tmpb[fd][strparser(tmpb[fd])]) == 0)
	{
		if ((retout[0] = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[retout[0]] = '\0';
		tmpb[fd] = superjoin(tmpb[fd], buf);
		retout[1] = 2;
	}
	else
		retout[1] = parsing(tmpb, line, fd);
	if (retout[0] == 0 && (ft_strlen(&tmpb[fd][strparser(tmpb[fd])]) == 0))
	{
		retout[1] = (ft_strlen(tmpb[fd]) > 0) ? 1 : 0;
		parsing(tmpb, line, fd);
		ft_strdel(&tmpb[fd]);
		tmpb[fd] = ft_strnew(0);
	}
	return ((retout[1] == 2) ? get_next_line(fd, line) : retout[1]);
}
