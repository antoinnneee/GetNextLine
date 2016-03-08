/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:40:53 by abureau           #+#    #+#             */
/*   Updated: 2016/03/08 14:49:03 by abureau          ###   ########.fr       */
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
	if (tmpbuff)
		tmpbuff = ft_strdup(&tmpbuff[ft_strlenn(tmpbuff)] + 1);
	else
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret < 0)
				return (-1);
			buf[ret] = '\0';
			tmpbuff = ft_strjoin(tmpbuff, buf);
		}
	if (tmpbuff)
	{
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
