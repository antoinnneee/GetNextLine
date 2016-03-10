/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/10 18:11:31 by abureau          ###   ########.fr       */
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

static char	*ft_strrdup(char *s1)
{
	char *dest;

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

static int	parsing(char **tmpbuff, char **line, int const fd)
{
	size_t index;

	*line = ft_strdup(ft_strsub(tmpbuff[fd], 0, ft_strlenn(tmpbuff[fd])));
	tmpbuff[fd] = ft_strrdup(tmpbuff[fd]);
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


static void	lafonctionquimallocletableau(char ***buff)
{
	int index;
	char **tmpbuff;

	index = 0;
	tmpbuff = NULL;
	if (!*buff)
	{
		tmpbuff = (char**)malloc(sizeof(char*) * 256);
			while(index < 256)
			{
				tmpbuff[index] = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
				index++;
			}
	*buff = tmpbuff;
	}
}


int			get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	**tmpbuff;
	int			out;

	lafonctionquimallocletableau(&tmpbuff);
	ret = -42;
	out = 2;
	if (fd < 0 || fd > 255)
		return (-1);
		if (ft_strlenn(tmpbuff[fd]) == ft_strlen(tmpbuff[fd]))
		{
			ret = read(fd, buf, BUFF_SIZE);
			if (ret < 0)
				return (-1);
			buf[ret] = '\0';
			tmpbuff[fd] = ft_strjoin(tmpbuff[fd], buf);
			out = 2;
		}
		else
		{
			out = parsing(tmpbuff, line, fd);
		}
	if (ret == 0) 
	{
		if (ft_strlenn(tmpbuff[fd]) == ft_strlen(tmpbuff[fd]) && ft_strlen(tmpbuff[fd]) > 0)
		{
			parsing(tmpbuff, line, fd);
			if (tmpbuff[fd])
				tmpbuff[fd] = ft_strrdup(tmpbuff[fd]);
			out = 1;
		}
		else if (ft_strlenn(tmpbuff[fd]) == ft_strlen(tmpbuff[fd]))
		{
			parsing(tmpbuff, line, fd);
			if (tmpbuff[fd])
				tmpbuff[fd] = ft_strrdup(tmpbuff[fd]);
			out = 0;
		}
	}
	if (out == 2)
		return (get_next_line(fd, line));
	return (out);
}
