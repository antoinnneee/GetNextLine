/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/15 13:00:33 by abureau          ###   ########.fr       */
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

static char		*ft_strrdup(char *s1)
{
	char	*dest;

//	ft_putstrnb("fr_strlen : ", ft_strlen(s1) - ft_strlenn(s1 + 2));
	dest = malloc(sizeof(char) * (ft_strlen(s1) - ft_strlenn(s1) + 2));
	if (dest)
	{
		ft_strcpy(dest, &s1[ft_strlenn(s1) + 1]);
		if (s1)
		{
			free(s1);
			s1 = NULL;
		}
		return (dest);
	}
	return (NULL);
}
/*
static void		testting(char **s1)
{
	int i;


	i = ft_strlen(*s1) - ft_strlenn(*s1) + 2;
	*s1[i] = '\0';
}
*/
static int		parsing(char **tmpbuff, char **line, int const fd)
{
	size_t	index;

	*line = ft_strdup(ft_strsub(tmpbuff[fd], 0, ft_strlenn(tmpbuff[fd])));
//	tmpbuff[fd] = ft_strrdup(tmpbuff[fd]);
	ft_strclr(tmpbuff[fd]);
	ft_putstrnb("len : ", ft_strlen(tmpbuff[fd]));
	index = ft_strlenn(tmpbuff[fd]);
	if (tmpbuff[fd][index] == '\0')
	{
		return (1);
	}
	else if (tmpbuff[fd][index] == '\n')
	{
		return (1);
	}
	return (0);
}

static void		lafonctionquimallocletableau(char ***buff, int *ret)
{
	int		index;
	char	**tmpbuff;

	*ret = -42;
	index = 0;
	tmpbuff = NULL;
	if (!*buff)
	{
		tmpbuff = (char**)malloc(sizeof(char*) * 256);
		if (!tmpbuff)
		{
			*ret = -1;
			return ;
		}
		while (index < 256)
		{
			tmpbuff[index] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
			if (!tmpbuff[index])
			{
				*ret = -1;
				return ;
			}
			index++;
		}
		*buff = tmpbuff;
	}
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			retout[2];
	static char	**tmpb;

	lafonctionquimallocletableau(&tmpb, &retout[0]);
	if (fd < 0 || fd > 255 || retout[0] == -1)
		return (-1);
	if (ft_strlen(&tmpb[fd][ft_strlenn(tmpb[fd])]) == 0 )
	{
		if ((retout[0] = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[retout[0]] = '\0';
		tmpb[fd] = ft_strjoin(tmpb[fd], buf);
		retout[1] = 2;
	}
	else
		retout[1] = parsing(tmpb, line, fd);
	if (retout [0] == 0 && (ft_strlen(&tmpb[fd][ft_strlenn(tmpb[fd])]) == 0 ))
	{
		retout[1] = (ft_strlen(tmpb[fd]) > 0) ? 1 : 0;
		parsing(tmpb, line, fd);
		if (tmpb[fd])
			tmpb[fd] = ft_strrdup(tmpb[fd]);
	}
	return ((retout[1] == 2) ? get_next_line(fd, line) : retout[1]);
}
