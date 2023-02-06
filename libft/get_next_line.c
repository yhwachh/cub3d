/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:51:14 by ibalbako          #+#    #+#             */
/*   Updated: 2022/06/09 15:15:53 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*ret[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rd_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	while (rd_bytes > 0)
	{
		buff[rd_bytes] = '\0';
		ft_add_buff(&ret[fd], buff);
		if (ft_strchr_gnl(ret[fd], '\n') != -1)
			return (ft_get_line(&ret[fd]));
		rd_bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_get_line(&ret[fd]));
}
