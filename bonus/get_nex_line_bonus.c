/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nex_line_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:32:05 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 02:04:01 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_del_line(char *holder)
{
	int		i;
	int		j;
	char	*reserve;

	i = 0;
	reserve = NULL;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i])
		i++;
	if (ft_strlen(holder) - i)
		reserve = malloc (ft_strlen(holder) - i + 1);
	if (!reserve)
	{
		free (holder);
		return (NULL);
	}
	j = 0;
	while (holder[i])
		reserve[j++] = holder[i++];
	reserve[j] = '\0';
	if (holder)
		free (holder);
	return (reserve);
}

char	*ft_till_newline(char *holder)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (holder[j] && holder[j] != '\n')
		j++;
	if (holder[j])
		j++;
	if (!j)
		return (NULL);
	str = malloc (j + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (holder[i] != '\n' && holder[i])
	{
		str[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_read_line(int fd, char *holder)
{
	int		readed;
	char	*dst;

	if (!holder)
		holder = ft_strdup("");
	dst = malloc((BUFFER_SIZE + (size_t)1));
	if (!dst)
		return (NULL);
	readed = 1;
	while (!ft_strchr(holder, '\n'))
	{
		readed = read(fd, dst, BUFFER_SIZE);
		if (!readed)
		{
			free (dst);
			return (holder);
		}
		if (readed == -1)
			return (free (dst), free(holder), NULL);
		dst[readed] = '\0';
		holder = ft_strjoin(holder, dst);
	}
	return (free(dst), holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = ft_read_line(fd, holder);
	if (!holder)
		return (NULL);
	line = ft_till_newline(holder);
	holder = ft_del_line(holder);
	return (line);
}
