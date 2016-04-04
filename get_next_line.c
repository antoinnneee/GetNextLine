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

static int			parsing(char **tmpbuff, char **line, int const fd, int funcchose)
{
	int	lenton;

	lenton = 0;
	while (tmpbuff[fd][lenton] != '\n' && tmpbuff[fd][lenton] != '\0')
		lenton++;
	if (funcchose)
		return(lenton);
	*line = ft_strnew(lenton);
	ft_strncpy(*line, tmpbuff[fd], lenton);
	ft_strcpy(tmpbuff[fd], &tmpbuff[fd][lenton + 1]);
	return (1);
}

static void			mallocarray(char ***buff, int *ret)
{
	char		**tmpbuff;

	*ret = -42;
	tmpbuff = NULL;
	tmpbuff = (char**)malloc(sizeof(char*) * 100000000);
	*buff = tmpbuff;
	if (!tmpbuff)
		*ret = -1;
}

static char			*superjoin(char *tmpbuff, char *readbuff)
{
	char	*res;
	int		i;

	if (tmpbuff)
	{
		i = ft_strlen(tmpbuff) + BUFF_SIZE;
	}
	else
	{
		i = BUFF_SIZE + 1;
	}
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (tmpbuff)
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
	if (fd < 0 || retout[0] == -1 || !line )
		return (-1);
	(!tmpb[fd]) ? (tmpb[fd] = (char*)malloc(sizeof(char))) : (void)42 ;
	if (ft_strlen(&tmpb[fd][parsing(tmpb, line, fd, 1)]) == 0)
	{
		if ((retout[0] = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[retout[0]] = '\0';
		tmpb[fd] = superjoin(tmpb[fd], buf);
		retout[1] = 2;
	}
	else
		retout[1] = parsing(tmpb, line, fd, 0);
	if (retout[0] == 0 && (ft_strlen(&tmpb[fd][parsing(tmpb, line, fd, 1)]) == 0))
	{
		retout[1] = (ft_strlen(tmpb[fd]) > 0) ? 1 : 0;
		parsing(tmpb, line, fd, 0);
		ft_strdel(&tmpb[fd]);
		tmpb[fd] = ft_strnew(0);
	}
	return ((retout[1] == 2) ? get_next_line(fd, line) : retout[1]);
}
