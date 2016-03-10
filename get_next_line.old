/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/08 17:36:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static int	ft_strlenn(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strredup(char *s1)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * ft_strlenn(s1) + 2);
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

int			get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			state;
	int			ret;
	static char	*tmpbuff = NULL;
	int			out;

	out = 0;
	ret = 0;
	state = 0;
	if (fd < 0 || fd > 255)
		return (-1);
	if (!tmpbuff)
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (-1);
			buf[ret] = '\0';
			tmpbuff = ft_strjoin(tmpbuff, buf);
		}
	else if (tmpbuff)
	{
		tmpbuff = ft_strredup(tmpbuff);
		if (ret > 0 || ft_strlen(tmpbuff) >= 1)
			if (state < ret || (state == 0 && ret == 0))
			{
				free(*line);
				*line = ft_strdup(ft_strsub(tmpbuff, 0, ft_strlenn(tmpbuff)));
			}
		out = (ft_strlen(tmpbuff) == 0) ? 0 : 1;
		if (out == 0)
		{
			free(tmpbuff);
			tmpbuff = NULL;
		}
	}
	return (out);
}
