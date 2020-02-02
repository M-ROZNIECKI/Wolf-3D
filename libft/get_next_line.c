/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 12:49:37 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 14:44:38 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	checkline(char **buff, char **line)
{
	long	i;
	char	*bufft;
	char	*posend;

	i = 0;
	bufft = *buff;
	while (bufft[i] != '\n')
		if (!(bufft[i++]))
			return (0);
	posend = &bufft[i];
	*posend = '\0';
	*line = ft_strdup(*buff);
	*buff = ft_strdup(posend + 1);
	free(bufft);
	return (1);
}

static int	read_file(int fd, char *temp, char **buff, char **line)
{
	int		nbchar;

	while ((nbchar = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[nbchar] = '\0';
		if (*buff)
			*buff = ft_strjoinmod(*buff, temp, 1);
		else
			*buff = ft_strdup(temp);
		if (*buff == NULL)
		{
			free(temp);
			return (-1);
		}
		if (checkline(buff, line))
			return (1);
	}
	free(temp);
	return (nbchar);
}

int			get_next_line(int fd, char **line)
{
	static char	*buff[FD_SETSIZE];
	char		*temp;
	int			nbchar;

	if (!line || fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE < 1)
		return (-1);
	if (buff[fd])
		if (checkline(&buff[fd], line))
			return (1);
	if (!(temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if ((nbchar = read_file(fd, temp, &buff[fd], line)) == 1)
		free(temp);
	if (buff[fd] == NULL || buff[fd][0] == '\0' || nbchar != 0)
	{
		if (nbchar <= 0)
			*line = ft_strdup("");
		return (nbchar);
	}
	*line = buff[fd];
	buff[fd] = NULL;
	return (1);
}
